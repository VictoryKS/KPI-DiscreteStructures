#ifndef CIRCLED_H_INCLUDED
#define CIRCLED_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class list {
  private:
    struct Node {
      string data;
      Node *next;
      Node *prev;
    };
    Node *first;
    int length;
  public:
    list();
    ~list();
    void push(string value);
    list select(int number);
    void insert(int index, string value);
    void del(int index, int count);
    void move(int start, int steps);
    int size();
    list::Node *get_first();
};

#endif