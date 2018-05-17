#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int *dijkstra(int **arr, int size, int start, int end) {
  if (start >= size || end >= size) {
    throw out_of_range("The graph doesn't contain this vertex(es)");
  }
  int *prev = new int;
  int *length = new int(size);
  bool visited[size];
  for (int temp = 0; temp < size; temp++) {
    length[temp] = 100000;
    visited[temp] = false;
  }
  visited[start] = true;
  length[start] = 0;
  prev[0] = start;
  int p = start, count = 1, res_length = 0;
  while (true) {
    int min_length = 100000, min_index = 100000;
    for (int temp = 0; temp < size; temp++) {
      if (!visited[temp] && length[temp] > length[p] + arr[p][temp]) {
        if (arr[p][temp] < 0) {
          throw out_of_range("Negative weight of edge");
        }
        length[temp] = length[p] + arr[p][temp];
        if (!visited[temp] && min_length > length[temp]) {
          min_length = length[temp];
          min_index = temp;
        }
      }
    }
    visited[min_index] = true;
    p = min_index;
    res_length += length[min_index];
    if (length[p] < res_length) {
      length[min_index] = min_length;
    }
    prev[count] = p;
    count++;

    if (p == end) {
      int *res = prev;
      length[p] > res_length ? res[count] = res_length : res[count] = length[p];
      return res;
    };
  }
}
