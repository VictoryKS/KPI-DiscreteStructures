#include "sorts.cpp"

struct Struct {
  int number;
  string surname;
};

int *problem_13(int *arr, int size) {
  int *res = arr;
  shell_sort_decrease(res, size);
  // quick_sort_decrease(res, 0, size - 1);
  return res;
}

int *problem_14(int *arr, int size, int insertion) {
  int *res = new int(size + 1);
  for (int i = 0; i < size; i++) {
    res[i] = arr[i];
  }
  res[size] = insertion;
  shell_sort_decrease(res, size + 1);
  // quick_sort_decrease(res, 0, size - 1);
  return res;
}

int *problem_15(int *arr, int size) {
  int *res = arr;
  shell_sort_decrease(res, size);
  // quick_sort_decrease(res, 0, size - 1);
  return res;
}

int *problem_16(int *arr, int size) {
  int *res = new int;
  int counter = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] >= 0) {
      res[counter] = arr[i];
      counter++;
    }
  }
  shell_sort_increase(res, counter);
  // quick_sort_increase(res, 0, counter - 1);
  return res;
}

int *problem_17(int *arr, int size) {
  int *res = arr;
  for (int j = 1; j < size; j++) {
    int temp = res[j];
    int index = j - 1;
    while (index >= 0 && res[index] > temp) {
      res[index + 1] = res[index];
      res[index] = temp;
      index--;
    }
  }
  return res;
}

vector<string> problem_18(vector<string> arr) {
  int size = arr.size();
  vector<string> res = arr;
  int d = size/2;
  while (d >= 1) {
    for (int i = 0; i < size - d; i++) {
      for (int j = i; j >= 0 && res[j].c_str()[0] > res[j + d].c_str()[0]; j--) {
        string temp = res[j];
        res[j] = res[j + d];
        res[j + d] = temp;
      }
    }
    d = d/2;
  }
  return res;
}

vector<Struct> problem_19(vector<Struct> arr) {
  int len = arr.size();
  int d = len/2;
  while (d >= 1) {
    for (int i = 0; i < len - d; i++) {
      for (int j = i; j >= 0 && arr[j].number > arr[j + d].number; j--) {
        Struct temp = arr[j];
        arr[j] = arr[j + d];
        arr[j + d] = temp;
      }
    }
    d = d/2;
  }
  return arr;
}

vector<string> problem_20(vector<string> arr) {
  int len = arr.size();
  int *length = new int(len);
  for (int i = 0; i < len; i++) {
    length[i] = arr[i].size();
  }
  shell_sort_increase(length, len);
  // quick_sort_increase(length, 0, len - 1);
  vector<string> res;
  int counter = 0;
  while (counter < len) {
    for (int i = 0; i < len; i++) {
      if (arr[i].size() == length[counter]) {
        res.push_back(arr[i]);
        counter++;
      }
    }
  }
  return res;
}

int *problem_21(int *arr, int size) {
  int d = size/2;
  int *abs = new int(size);
  for (int i = 0; i < size; i++) {
    arr[i] >= 0 ? abs[i] = arr[i] : abs[i] = -arr[i];
  }
  while (d >= 1) {
    for (int i = 0; i < size - d; i++) {
      for (int j = i; j >= 0 && abs[j] < abs[j + d]; j--) {
        int temp = arr[j];
        arr[j] = arr[j + d];
        arr[j + d] = temp;
        int tmp = abs[j];
        abs[j] = abs[j + d];
        abs[j + d] = tmp;
      }
    }
    d = d/2;
  }
  return arr;
}

int *problem_22(int *arr, int size) {
  int *res = new int[size * 2 - 1];
  int counter = -1;
  for(int i = 0; i < size; i++) {
    res[++counter] = arr[i];
    if (arr[i] + 1 < arr[i + 1]) {
      res[++counter] = arr[i] + 1;
    } else {
      res[++counter] = arr[i];
    }
  }
  return res;
}
