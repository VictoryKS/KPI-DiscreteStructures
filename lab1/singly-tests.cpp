#include "singly.cpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../labs/doctest.h"
#include <string>

list l1;

TEST_CASE("Push") {
  l1.push("Johnson");
  l1.push("Pines");
  l1.push("Chase");
  l1.push("Baker");
  CHECK(l1.get_first()->data == "Johnson");
  CHECK(l1.get_last()->data == "Baker");
  CHECK(l1.size() == 4);
};

TEST_CASE("Select") {
  CHECK_THROWS(l1.select(0));
  CHECK_THROWS(l1.select(8));
  CHECK(l1.select(2).size() == 2);
  CHECK(l1.select(2).get_first()->data == "Pines");
}

TEST_CASE("Insert") {
  l1.insert(0, "Aurelius");
  REQUIRE(l1.size() == 5);
  CHECK(l1.get_first()->next->data == "Aurelius");
}

TEST_CASE("Del") {
  CHECK_NOTHROW(l1.del(1, 2));
  CHECK(l1.get_first()->next->data == "Chase");
  REQUIRE(l1.size() == 3);
  CHECK_THROWS(l1.del(3, 9));
}

TEST_CASE("Move") {
  l1.push("Pines");
  l1.move(2, 1);
  CHECK(l1.get_last()->data == "Baker");
  CHECK_THROWS(l1.move(5, 1));
}
