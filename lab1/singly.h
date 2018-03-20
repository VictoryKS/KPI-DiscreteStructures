#ifndef SINGLY_H_INCLUDED
#define SINGLY_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class list {
  private:
    struct Node {
      string data;
      Node *next;
    };
    Node *first;
    Node *last;
    int length;
  public:
    list();
    ~list();
    void push(string value); // push an element to the end of the list
    list select(int number); // create new list of elements on
                             // [number] position from current list
    void insert(int index, string value); // insert an element after
                                          // element[index]
    void delete_count(int index, int count); // delete [count] of elements
                                             // from element[index]
    void move(int start, int steps); // move element[start] [steps] times
    int size() {
      return length;
    }
    class iterator {
      private:
        const list &l;
        Node *current;
        int index;
      public:
        iterator(const list &s): l(s), index(0) {
          current = l.first;
        }
        iterator(const list &s, int size): l(s), index(size) {
          current = l.first;
          for (int i = 0; i < size; i++) {
            current = current->next;
          }
        }
        void operator ++() {
          current = current->next;
          index++;
        }
        bool operator !=(const iterator& other) {
          return index != other.index;
        }
        bool operator ==(const iterator& other) {
          return index == other.index;
        }
        string operator *() {
          if (current) {
            return current->data;
          }
          return "";
        }
      };
      iterator begin() {
        iterator it(*this);
        return it;
      }
      iterator end() {
        iterator it(*this, this->size() - 1);
        return it;
      }
};

#endif
