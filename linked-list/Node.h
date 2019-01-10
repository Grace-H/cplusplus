#include <cstring>
#include <iostream>

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node {
 public:
  Node();
  Node(int newnum, Node* newnext);
  ~Node();

  void display();
  int getValue();
  void setValue(int newnum);
  Node* getNext();
  void setNext(Node* newnext);

 private:
  int num;
  Node* next;
};

#endif
