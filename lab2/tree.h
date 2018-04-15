#include <iostream>

using namespace std;

class tree {
  private:
    struct Node {
      double data;
      Node *parent;
      Node *left;
      Node *right;
    };
    int count;
    double sum;
    Node *root;
  public:
    tree();
    ~tree();
    void add(double data);
    void add_node(Node *current, Node *element); // additional's helper
    tree::Node *_search_node(double data); // deletition's and contains' helper
    void _comparing(Node *deleted, Node *side); // deletition's helper
    void delete_node(double data);
    double average(); // find average of all elements
    void add_average() {
      double average = this->average(); // add average to the tree
      this->add(average);
    };
    int get_count() { // count of all elements
      return count;
    }
    double get_sum() { // sum of all elements
      return sum;
    }
    bool contains(double data) { // returns true if element contains in the tree
      return !!this->_search_node(data);
    }
};
