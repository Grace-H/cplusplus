#include <cstring>
#include <iostream>
#include "Node.h"

void findLowest(Node* current, int num1, int num2);
void print(Node* start);
void addNode(Node* &head, Node* current, int num);

int main(){
  Node* head = NULL;
  addNode(head, head, 220);
  addNode(head, head, 23);
  addNode(head, head, 34);
  addNode(head, head, 57);
  addNode(head, head, 100);
  print(head);
  findLowest(head, head->getValue(), head->getNext()->getValue());
  return 0;
}

void findLowest(Node* current, int num1, int num2){
  if(current != NULL){
    if(current->getValue() < num1 || current->getValue() < num2){
      if(num1 <= num2){
	num2 = current->getValue();
      }
      else{
	num1 = current->getValue();
      }
    }
    findLowest(current->getNext(), num1, num2);
  }
  else{
    cout << "The two highest values are: " << num1 << ", " << num2 << endl;
  }
}

void print(Node* start){
  if(start != NULL){
    start->display();
    print(start->getNext());
  }
}

void addNode(Node* &head, Node* current, int num){
  if(head == NULL){
    head = new Node(num, NULL);
  }
  else if(current->getNext() == NULL){
    current->setNext(new Node(num, NULL));
  }
  else{
    addNode(head, current->getNext(), num);
  }
}
