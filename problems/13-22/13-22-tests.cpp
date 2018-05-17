#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "13-22-task.cpp"

using namespace std;

TEST_CASE("Problem_13") {
  int *arr = new int[5];
  arr[0] = 3;
  arr[1] = -7;
  arr[2] = 9;
  arr[3] = 0;
  arr[4] = -12;
  int *res = problem_13(arr, 5);
  CHECK(res[0] == 9);
  CHECK(res[1] == 3);
  CHECK(res[2] == 0);
  CHECK(res[3] == -7);
  CHECK(res[4] == -12);
}

TEST_CASE("Problem_14") {
  int *arr1 = new int[5];
  arr1[0] = 3;
  arr1[1] = -7;
  arr1[2] = 9;
  arr1[3] = 0;
  arr1[4] = -12;
  CHECK_NOTHROW(shell_sort_decrease(arr1, 5));
  int *res1 = problem_14(arr1, 5, 10);
  CHECK(res1[0] == 10);
  CHECK(res1[1] == 9);
  CHECK(res1[2] == 3);
  CHECK(res1[3] == 0);
  CHECK(res1[4] == -7);
  CHECK(res1[5] == -12);
}

TEST_CASE("Problem_15") {
  int *arr2 = new int[5];
  arr2[0] = 3;
  arr2[1] = -7;
  arr2[2] = 9;
  arr2[3] = 0;
  arr2[4] = -12;
  CHECK_NOTHROW(shell_sort_increase(arr2, 5));
  int *res2 = problem_15(arr2, 5);
  CHECK(res2[0] == 9);
  CHECK(res2[1] == 3);
  CHECK(res2[2] == 0);
  CHECK(res2[3] == -7);
  CHECK(res2[4] == -12);
}

TEST_CASE("Problem_16") {
  int *arr3 = new int[5];
  arr3[0] = 3;
  arr3[1] = -7;
  arr3[2] = 9;
  arr3[3] = 5;
  arr3[4] = -12;
  int *res3 = problem_16(arr3, 5);
  CHECK(res3[0] == 3);
  CHECK(res3[1] == 5);
  CHECK(res3[2] == 9);
}

TEST_CASE("Problem_17") {
  int *arr4 = new int[5];
  arr4[0] = 3;
  arr4[1] = -7;
  arr4[2] = 9;
  arr4[3] = 0;
  arr4[4] = -12;
  int *res4 = problem_17(arr4, 5);
  CHECK(res4[0] == -12);
  CHECK(res4[1] == -7);
  CHECK(res4[2] == 0);
  CHECK(res4[3] == 3);
  CHECK(res4[4] == 9);
}

TEST_CASE("Problem_18") {
  vector <string> arr5;
  arr5.push_back("Johnson");
  arr5.push_back("Chase");
  arr5.push_back("Blossom");
  arr5.push_back("Osvald");
  vector <string> res5 = problem_18(arr5);
  CHECK(res5[0] == "Blossom");
  CHECK(res5[1] == "Chase");
  CHECK(res5[2] == "Johnson");
  CHECK(res5[3] == "Osvald");
}

TEST_CASE("Problem_19") {
  vector <Struct> arr6;
  Struct User1, User2, User3;
  User1.number = 8765656;
  User1.surname = "Johnson";
  User2.number = 9393023;
  User2.surname = "Chase";
  User3.number = 1782023;
  User3.surname = "Kory";
  arr6.push_back(User1);
  arr6.push_back(User2);
  arr6.push_back(User3);
  vector <Struct> res6 = problem_19(arr6);
  CHECK(res6[0].surname == "Kory");
  CHECK(res6[1].surname == "Johnson");
  CHECK(res6[2].surname == "Chase");
}

TEST_CASE("Problem_20") {
  vector <string> arr7;
  arr7.push_back("John");
  arr7.push_back("Chase");
  arr7.push_back("Blossom");
  arr7.push_back("Osvald");
  vector <string> res7 = problem_20(arr7);
  CHECK(res7[0] == "John");
  CHECK(res7[1] == "Chase");
  CHECK(res7[2] == "Osvald");
  CHECK(res7[3] == "Blossom");
}

TEST_CASE("Problem_21") {
  int *arr8 = new int[5];
  arr8[0] = 3;
  arr8[1] = -7;
  arr8[2] = 9;
  arr8[3] = 0;
  arr8[4] = -12;
  int *res8 = problem_21(arr8, 5);
  CHECK(res8[0] == -12);
  CHECK(res8[1] == 9);
  CHECK(res8[2] == -7);
  CHECK(res8[3] == 3);
  CHECK(res8[4] == 0);
}

TEST_CASE("Problem_22") {
  int *arr9 = new int[5];
  arr9[0] = 3;
  arr9[1] = -7;
  arr9[2] = 9;
  arr9[3] = 0;
  arr9[4] = -12;
  CHECK_NOTHROW(shell_sort_increase(arr9, 5));
  int *res9 = problem_22(arr9, 5);
  CHECK(res9[0] == -12);
  CHECK(res9[1] == -11);
  CHECK(res9[2] == -7);
  CHECK(res9[3] == -6);
  CHECK(res9[4] == 0);
  CHECK(res9[5] == 1);
  CHECK(res9[6] == 3);
  CHECK(res9[7] == 4);
  CHECK(res9[8] == 9);
}
