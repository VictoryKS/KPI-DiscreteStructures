#include <iostream>
#include <string>
#include "singly.h"

using namespace std;

list::list():
first(nullptr),
last(nullptr),
length(0)
{}

list::~list() {
Node* current = first;
  while(length > 0) {
    Node* next = current->next;
    delete current;
    length--;
    current = next;
  }
}

void list::push(string value) {
  Node *element = new Node;
  element->data = value;
  element->next = nullptr;
  if (length == 0) {
    first = element;
    last = element;
    element = nullptr;
  }
  if (length != 0) {
    last->next = element;
    last = element;
  }
  length++;
}

void list::insert(int index, string value) {
  Node *current = first;
  if (index == length - 1) {
    this->push(value);
  }
  if (index < length && index >= 0) {
    for (int i = 0; i < index ; i++) {
      current = current->next;
    }
    Node *element = new Node;
    element->data = value;
    element->next = current->next;
    current->next = element;
    length++;
  }
  if (index >= length || index < 0) {
    throw out_of_range("Incorrect position for insertion");
  }
}

void list::delete_count(int index, int count) {
  Node *current = first;
  Node *prev;
  if (count == 0) {
    throw out_of_range("Senseless request: zero count");
  }
  if (index < length && index > 0) {
    for (int i = 0; i < index; i++) {
      prev = current;
      current = current->next;
    }
    if (length == 2) {
      first = prev;
      last = prev;
    } else {
      if (!prev) first = current->next;
      if (!current->next) last = prev;
      if (prev && current->next) prev->next = current->next;
    }
  }
  if (index == 0) {
    if (current->next) {
      first = current->next;
    } else {
      first = nullptr;
      last = nullptr;
    }
  }
  if (index >= length || index < 0) {
    throw out_of_range("Incorrect index for deletition\n");
  }
  delete current;
  length--;
  count--;
  if (length == 0 && count != 0) {
    throw logic_error("The list is empty");
  }
  if (count != 0 && length != 0) {
    this->delete_count(index, count);
  }
}

void list::move(int start, int steps) {
  Node *current = first;
  if (start < length && start > 0) {
    for (int i = 0; i < start; i++) {
      current = current->next;
      cout << i << " - " << current->data;
    }
  }
  int index = start + steps;
  this->insert(index, current->data);
  this->delete_count(start, 1);
}

list list::select(int number) {
  list result;
  Node *current = first;
  if (number > length || number == 0 || number < 0) {
    throw out_of_range("Selection by zero or negative number\n");
  }
  for (int i = 1; i <= length; i++) {
    if(number > 0 && i % number == 0) result.push(current->data);
    current = current->next;
  }
  return result;
}
