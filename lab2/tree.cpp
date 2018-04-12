#include "tree.h"

using namespace std;

tree::tree():
  root(nullptr),
  count(0),
  sum(0.0)
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
      current->right = element;
      element->parent = current;
      return;
    } else {
      this->add_node(current->right, element);
    }
  }
  if (element->data <= current->data) {
    if (!current->left) {
      current->left = element;
      element->parent = current;
      return;
    } else {
      this->add_node(current->left, element);
    }
  }
}

void tree::add(double data) {
  Node *element = new Node;
  element->data = (double)data;
  sum += data;
  count++;
  this->add_node(root, element);
}

tree::Node *tree::_search_node(double data) {
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

void tree::delete_node(double data) {
  Node *deleted = this->_search_node(data);
  if (!deleted) {
    throw out_of_range("No elements to delete");
  }
  if (!root) {
    throw logic_error("The tree has no elements");
  }
  count--;
  sum -= data;
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
  delete deleted;
}

double tree::average() {
  if (!root) {
    throw logic_error("The tree has no elements");
  }
  return sum/count;
};
