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
    double average();
    void add_average() {
      double average = this->average();
      this->add(average);
    };
    int get_count() {
      return count;
    }
    double get_sum() {
      return sum;
    }
    bool contains(double data) {
      return !!this->_search_node(data);
    }
};
