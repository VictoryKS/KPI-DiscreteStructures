#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "dijkstra.cpp"

TEST_CASE("First graph") {
  int **arr1 = new int* [4];
  for (int i = 0; i < 4; i++) {
    arr1[i] = new int [4];
  }
  arr1[0][1] = 7;
  arr1[0][2] = 9;
  arr1[0][3] = 6;
  arr1[1][2] = 10;
  arr1[1][3] = 3;
  arr1[2][3] = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i < j) {
        arr1[j][i] = arr1[i][j];
      } else if (i == j) arr1[i][j] = 0;
    }
  }

  int *res1 = dijkstra(arr1, 4, 0, 2);
  CHECK(res1[0] == 0);
  CHECK(res1[1] == 3);
  CHECK(res1[2] == 2);
  REQUIRE(res1[3] == 7);

  int *res2 = dijkstra(arr1, 4, 1, 3);
  CHECK(res2[0] == 1);
  CHECK(res2[1] == 3);
  REQUIRE(res2[2] == 3);

  int *res3 = dijkstra(arr1, 4, 3, 2);
  CHECK(res3[0] == 3);
  CHECK(res3[1] == 2);
  REQUIRE(res3[2] == 1);

  CHECK_THROWS(dijkstra(arr1, 4, 5, 9));

  for (int i = 0; i < 4; i++) delete [] arr1[i];
  delete [] res1;
  delete [] res2;
  delete [] res3;
}

TEST_CASE("Second graph") {
  int **arr2 = new int* [3];
  for (int i = 0; i < 3; i++) {
    arr2[i] = new int [3];
  }
  arr2[0][1] = -7;
  arr2[0][2] = -9;
  arr2[1][2] = 10;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i < j) {
        arr2[j][i] = arr2[i][j];
      } else if (i == j) arr2[i][j] = 0;
    }
  }

  CHECK_THROWS(dijkstra(arr2, 3, 0, 1));

  for (int i = 0; i < 3; i++) delete [] arr2[i];
}
