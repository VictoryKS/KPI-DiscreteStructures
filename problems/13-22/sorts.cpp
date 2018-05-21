#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;

void shell_sort_increase(int *arr, int size) {
  int d = size/2;
  while (d >= 1) {
    for (int i = 0; i < size - d; i++) {
      for (int j = i; j >= 0 && arr[j] > arr[j + d]; j--) {
        int temp = arr[j];
        arr[j] = arr[j + d];
        arr[j + d] = temp;
      }
    }
    d = d/2;
  }
}

void shell_sort_decrease(int *arr, int size) {
  int d = size/2;
  while (d >= 1) {
    for (int i = 0; i < size - d; i++) {
      for (int j = i; j >= 0 && arr[j] < arr[j + d]; j--) {
        int temp = arr[j];
        arr[j] = arr[j + d];
        arr[j + d] = temp;
      }
    }
    d = d/2;
  }
}

void quick_sort_increase(int *arr, int left, int right) {
  int i = left, j = right;
  int temp;
  int pivot = arr[(left + right) / 2];
  while (i <= j) {
    while (arr[i] < pivot) i++;
    while (arr[j] > pivot) j--;
    if (i <= j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  };
  if (left < j) quick_sort_increase(arr, left, j);
  if (i < right) quick_sort_increase(arr, i, right);
}

void quick_sort_decrease(int *arr, int left, int right) {
  int i = left, j = right;
  int temp;
  int pivot = arr[(left + right) / 2];
  while (i <= j) {
    while (arr[i] > pivot) i++;
    while (arr[j] < pivot) j--;
    if (i <= j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  };
  if (left < j) quick_sort_decrease(arr, left, j);
  if (i < right) quick_sort_decrease(arr, i, right);
}
