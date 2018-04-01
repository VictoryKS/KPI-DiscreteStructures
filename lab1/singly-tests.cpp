#include "singly.cpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>

TEST_CASE("Push") {
  list l1;
  l1.push("Johnson");
  l1.push("Pines");
  l1.push("Chase");
  l1.push("Baker");
  CHECK(*l1.begin() == "Johnson");
  CHECK(*l1.end() == "Baker");
  CHECK(l1.size() == 4);
};

TEST_CASE("Select") {
  list l2;
  l2.push("Johnson");
  l2.push("Pines");
  l2.push("Chase");
  l2.push("Baker");
  CHECK(l2.select(2).size() == 2);
  CHECK(*l2.select(2).begin() == "Pines");
  CHECK_THROWS(l2.select(0));
  CHECK_THROWS(l2.select(8));
  CHECK_THROWS(l2.select(-3));
}

TEST_CASE("Insert") {
  list l3;
  l3.push("Johnson");
  l3.push("Pines");
  l3.push("Chase");
  l3.push("Baker");
  l3.insert(0, "Aurelius");
  REQUIRE(l3.size() == 5);
  list::iterator temp = l3.begin();
  ++temp;
  CHECK(*temp == "Aurelius");
  CHECK_THROWS(l3.insert(-8, "Smth"));
  CHECK_THROWS(l3.insert(10, "Smth"));
}

TEST_CASE("Delete_count") {
  list l4;
  l4.push("Johnson");
  l4.push("Aurelius");
  l4.push("Pines");
  l4.push("Chase");
  l4.push("Baker");
  CHECK_NOTHROW(l4.delete_count(0, 2));
  CHECK(*l4.begin() == "Pines");
  REQUIRE(l4.size() == 3);
  CHECK_THROWS(l4.delete_count(3, 9));
}

TEST_CASE("Move") {
  list l5;
  l5.push("Johnson");
  l5.push("Pines");
  l5.push("Chase");
  l5.move(0, 1);
  CHECK(*l5.begin() == "Pines");
  CHECK_THROWS(l5.move(5, 1));
  CHECK_THROWS(l5.move(-7, 1));
  CHECK_THROWS(l5.move(1, 9));
}
