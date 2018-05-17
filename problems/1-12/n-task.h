#include <iostream>

using namespace std;

class tree {
  private:
    struct Node {
      int data;
      Node *parent;
      Node *left;
      Node *right;
    };
    int arr[1000];
    Node *root;
    int count;
  public:
    tree();
    ~tree();
    void add(int data);
    void add_node(Node *current, Node *element); // additional's helper
    tree::Node *_search_node(int data);
    void _comparing(Node *deleted, Node *side); // deletition's helper
    void delete_node(int data);
    bool contains(int data); // returns true if element contains in the tree
    tree *find_add(int n);
    tree *find_del(int n);
    int get_count() {
      return count;
    }
};
