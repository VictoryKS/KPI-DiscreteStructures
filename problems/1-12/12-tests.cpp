#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "12-task.cpp"

using namespace std;

TEST_CASE("Find_add") {
  tree *t1 = new tree();
  t1->add(-33);
  t1->add(76);
  t1->add(-64);
  t1->add(20);
  t1->add(65);
  t1->add(81);

  tree *t2 = t1->find_add();
  CHECK(t2->contains(-64));
  CHECK(t2->contains(81));
  REQUIRE(t2->get_count() == 2);
}

TEST_CASE("Find_del") {
  tree *t3 = new tree();
  t3->add(-33);
  t3->add(76);
  t3->add(-64);
  t3->add(20);
  t3->add(65);
  t3->add(81);

  tree *t4 = t3->find_del();
  CHECK(!t4->contains(-64));
  CHECK(!t4->contains(81));
  CHECK(t4->contains(20));
  CHECK(t4->contains(-33));
  CHECK(t4->contains(76));
  CHECK(t4->contains(65));
  REQUIRE(t4->get_count() == 4);
}
