#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tree.cpp"

using namespace std;

TEST_CASE("Add") {
  tree *t = new tree();
  t->add(10);
  t->add(8);
  t->add(12.4);
  t->add(5);
  t->add(9.0);
  t->add(11);
  t->add(15.3);

  REQUIRE(t->get_count() == 7);
  REQUIRE(t->get_sum() == 70.7);
  CHECK(t->contains(10));
  CHECK(t->contains(8));
  CHECK(t->contains(12.4));
  CHECK(t->contains(5));
  CHECK(t->contains(9));
  CHECK(t->contains(11));
  CHECK(t->contains(15.3));
}

TEST_CASE("Delete") {
  tree *t1 = new tree();
  t1->add(10);
  t1->add(8);
  t1->add(12.4);
  t1->add(5);
  t1->add(9.0);
  t1->add(11);
  t1->add(15.3);

  CHECK_NOTHROW(t1->delete_node(10));
  REQUIRE(t1->get_sum() == 60.7);
  CHECK(!t1->contains(10));
  REQUIRE(t1->get_count() == 6);
  CHECK_NOTHROW(t1->delete_node(11));
  REQUIRE(t1->get_sum() == 49.7);
  CHECK(!t1->contains(11));
  REQUIRE(t1->get_count() == 5);
  CHECK_NOTHROW(t1->delete_node(5));
  REQUIRE(t1->get_sum() == 44.7);
  CHECK(!t1->contains(5));
  REQUIRE(t1->get_count() == 4);
  CHECK_NOTHROW(t1->delete_node(8));
  REQUIRE(t1->get_sum() == 36.7);
  CHECK(!t1->contains(8));
  REQUIRE(t1->get_count() == 3);

  CHECK_THROWS(t1->delete_node(7854));
  tree *t2 = new tree();
  CHECK_THROWS(t2->delete_node(9));
  t1->~tree();
}

TEST_CASE("Average") {
  tree *t3 = new tree();
  t3->add(10);
  t3->add(8);
  t3->add(12.4);
  t3->add(5);

  REQUIRE(t3->average() == 8.85);
  CHECK_NOTHROW(t3->add_average());
  REQUIRE(t3->get_count() == 5);
  CHECK(t3->contains(8.85));

  tree *t4 = new tree();
  CHECK_THROWS(t4->average());
  CHECK_THROWS(t4->add_average());
}
