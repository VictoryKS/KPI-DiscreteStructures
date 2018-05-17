#include "task.h"

tree::tree():
  root(nullptr),
  count(0)
{}

tree::~tree() {
  delete root;
  root = nullptr;
}

void tree::add_node(Node *current, Node *element) {
  if (!root) {
    root = element;
    return;
  }
  if (element->data > current->data) {
    if (!current->right) {
      element->parent = current;
      current->right = element;
      return;
    } else {
      this->add_node(current->right, element);
    }
  }
  if (element->data <= current->data) {
    if (!current->left) {
      element->parent = current;
      current->left = element;
      return;
    } else {
      this->add_node(current->left, element);
    }
  }
}

void tree::add(int data) {
  Node *element = new Node;
  element->data = data;
  arr[count] = data;
  count++;
  this->add_node(root, element);
}

void tree::_comparing(Node *deleted, Node *side) {
  if (!deleted->parent) {
    root = side;
    return;
  }
  if (deleted->parent->right == deleted) {
    deleted->parent->right = side;
  }
  if (deleted->parent->left == deleted) {
    deleted->parent->left = side;
  }
}

tree::Node *tree::_search_node(int data) {
  Node *current = root;
  int counter = count;
  while (counter > 0) {
    if (current->data == data) {
      return current;
    }
    if (!current->right && !current->left) {
      return nullptr;
    }
    if (current->right && (current->data < data)) {
      current = current->right;
    }
    if (current->left && (current->data > data)) {
      current = current->left;
    }
    counter--;
  }
}

void tree::delete_node(int data) {
  Node *deleted = this->_search_node(data);
  if (!deleted) {
    throw out_of_range("No elements to delete");
  }
  if (!root) {
    throw logic_error("The tree has no elements");
  }
  count--;
  if (deleted->right && !deleted->left) {
    deleted->right->parent = deleted->parent;
    this->_comparing(deleted, deleted->right);
  }
  if (deleted->left && !deleted->right) {
    deleted->left->parent = deleted->parent;
    this->_comparing(deleted, deleted->left);
  }
  if (deleted->left && deleted->right) {
    deleted->right->parent = deleted->parent;
    this->_comparing(deleted, deleted->right);
    this->add_node(root, deleted->left);
  }
  if (!deleted->left && !deleted->right) {
    this->_comparing(deleted, nullptr);
  }
  bool then = false;
  for (int i = 0; i < count; i++) {
    if (arr[i] == data || then) {
      arr[i] = arr[i+1];
      then = false;
    }
  }
  delete deleted;
}

tree *tree::find_add() {
  bool prime[count];
  for (int i = 0; i < count; i++) {
    int counter = 0;
    int num;
    arr[i] > 0 ? num = arr[i] : num = -arr[i];
    for (int j = 1; j <= num; j++) {
      if (arr[i] % j == 0) counter++;
    }
    counter <= 2 ? prime[i] = true : prime[i] = false;
  }
  tree *res = new tree();
  for (int i = 0; i < count; i++) {
    if (!prime[i]) res->add(arr[i]);
  }
  return res;
}

tree *tree::find_del() {
  bool prime[count];
  for (int i = 0; i < count; i++) {
    int counter = 0;
    int num;
    arr[i] > 0 ? num = arr[i] : num = -arr[i];
    for (int j = 1; j <= num; j++) {
      if (arr[i] % j == 0) counter++;
    }
    counter <= 2 ? prime[i] = true : prime[i] = false;
  }
  tree *res = new tree();
  for (int i = 0; i < count; i++) {
    if (prime[i]) res->add(arr[i]);
  }
  return res;
}

bool tree::contains(int data) {
  for (int i = 0; i < count; i++) {
    if (arr[i] == data) return true;
  }
  return false;
}
