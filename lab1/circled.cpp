#include <stdexcept>
#include <string>
#include "circled.h"

using namespace std;

list::list():
  first(nullptr),
  length(0)
{}

list::~list() {
  Node* current = first;
    while(length != 0) {
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
  if (length == 0) {
    first = element;
    first->prev = element;
  } else {
    first->prev->next = element;
    element->prev = first->prev;
    first->prev = element;
    element->next = first;
  }
  length++;
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

void list::insert(int index, string value) {
  // insert an element after element[index]
  Node *current = first;
  for (int i = 0; i < index ; i++) {
    current = current->next;
  }
  if (index == length - 1) {
    this->push(value);
  } else {
    Node *element = new Node;
    element->data = value;
    element->next = current->next;
    element->prev = current;
    current->next = element;
    element->next->prev = element;
    length++;
  }
}

void list::del(int index, int count) {
  // delete [count] of elements from element[index]
  Node *current = first;
  if(length > 2) {
    for (int i = 0; i < index; i++) {
      current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    if (index == 0 || index % (length - 1) == 0) {
      first = current->next;
    }
  }
  if (length == 2) {
    for (int i = 0; i < index; i++) {
      current = current->next;
    }
    first = current->next;
  }
  if (length == 1) {
    first = nullptr;
  }
  delete current;
  length--;
  count--;
  if (length == 0 && count != 0) {
    throw invalid_argument("The list is empty");
  }
  if (length != 0 && count != 0) {
    this->del(index, count);
  }
}

void list::move(int start, int steps) {
  // move element[start] [steps] times
  Node *current = first;
  for (int i = 0; i < start; i++) {
    current = current->next;
    cout << i << " - " << current->data;
  }
  int index = (start + steps) % length;
  this->insert(index - 1, current->data);
  this->del(start + 1, 1);
}

list::Node *list::get_first() {
  return this->first;
}

int list::size() {
  return length;
}
