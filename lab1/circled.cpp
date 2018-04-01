#include "circled.h"

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

void list::insert(int index, string value) {
  Node *current = first;
  for (int i = 0; i < index ; i++) {
    current = current->next;
  }
  if (index < 0 || index >= length) {
    throw out_of_range("Incorrect position for insertion");
  }
  if (index == length - 1) {
    this->push(value);
  }
  if ((index >= 0) && (index < length - 1)) {
    Node *element = new Node;
    element->data = value;
    element->next = current->next;
    element->prev = current;
    current->next = element;
    element->next->prev = element;
    length++;
  }
}

void list::delete_count(int index, int count) {
  Node *current = first;
  if(length > 2) {
    for (int i = 0; i < index; i++) {
      current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    if ((index == 0) || (index % (length - 1) == 0)) {
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
    throw logic_error("The list is empty");
  }
  if (length != 0 && count != 0) {
    this->delete_count(index, count);
  }
}

void list::move(int start, int steps) {
  Node *current = first;
  for (int i = 0; i < start; i++) {
    current = current->next;
  }
  int index = start + steps - 1;
  this->insert(index, current->data);
  this->delete_count(start, 1);
}
