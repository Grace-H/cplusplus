/*
 * Node.cpp - Linked list node class
 */
#include <cstring>
#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() {
  next = NULL;
}

Node::Node(int newnum, Node* newnext) {
  next = newnext;
  num = newnum;
}

Node::~Node() {
}

void Node::display() {
  cout << num;
}

int Node::getValue() {
  return num;
}

void Node::setValue(int newnum) {
  num = newnum;
}

Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}
