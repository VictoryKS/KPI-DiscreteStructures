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
  // push an element to the end of the list
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
  // insert an element after element[index]
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
    throw invalid_argument("Invalid argument, impossible to insert");
  }
}

void list::del(int index, int count) {
  // delete [count] of elements from element[index]
  Node *current = first;
  Node *prev;
  if (index < length && index >= 0) {
    for (int i = 0; i < index; i++) {
      prev = current;
      current = current->next;
    }
    if (!prev) first = current->next;
    if (!current->next) last = prev;
    if (prev && current->next) prev->next = current->next;
  }
  if (index >= length || index < 0) {
    throw invalid_argument("Invalid argument, impossible to insert");
  }
  delete current;
  length--;
  count--;
  if (length == 0 && count != 0) {
    throw invalid_argument("The list is empty");
  }
  if (count != 0 && length != 0) {
    this->del(index, count);
  }
}

void list::move(int start, int steps) {
  Node *current = first;
  if (start < length && start > 0) {
    for (int i = 0; i < start; i++) {
      current = current->next;
      cout << i << " - " << current->data;
    }
    int index = start + steps;
    this->insert(index, current->data);
    this->del(start, 1);
  }
  if (start >= length || start < 0) {
    throw invalid_argument("Invalid argument, impossible to move");
  }
}

list::Node* list::get_first() {
  return first;
}

list::Node* list::get_last() {
  return last;
}

int list::size() {
  return length;
}

list list::select(int number) {
  // create new list of elements on
  // [number] position from current list
  list result;
  Node *current = first;
  if (number > length || number == 0) {
    throw invalid_argument("Impossible to select\n");
  }
  for (int i = 1; i <= length; i++) {
    if(number > 0 && i % number == 0) result.push(current->data);
    current = current->next;
  }
  return result;
}
