#include <cstring>
#include <iostream>
#include "Node.h"

int getNth(Node* current, int index);
int lenList(Node* head, int total);
int count(Node* current, int searchFor, int total);
void findHighest(Node* current, int num1, int num2);
void findLowest(Node* current, int num1, int num2);
void print(Node* start);
void addNode(Node* &head, Node* current, int num);
Node* abrevList(Node* &head);

int main(){
  Node* head = NULL;
  addNode(head, head, 220);
  addNode(head, head, 23);
  addNode(head, head, 34);
  addNode(head, head, 57);
  addNode(head, head, 100);
  addNode(head, head, 29);
  addNode(head, head, 29);
  addNode(head, head, 12);
  addNode(head, head, 220);

  print(head);

  findLowest(head, head->getValue(), head->getNext()->getValue());
  findHighest(head, head->getValue(), head->getNext()->getValue());

  //abrev list
  Node* head2 = abrevList(head);
  cout << "list2: ";
  print(head2);

  //count
  cout << "Num of 29: " << count(head, 29, 0) << endl;
  cout << "Num of 100: " << count(head, 100, 0) << endl;

  //len list
  cout << "len list: " << lenList(head, 0) << endl;
  cout << getNth(head, 4);
  return 0;
}

int getNth(Node* head, int index){
  if(index <= lenList(head, 0) - 1){
    int count = 0;
    while(count < index){
      head = head->getNext();
      count++;
    }
    return head->getValue();
  }
  else{
    cout << "doesn't exist" << endl;
  } 
}

int lenList(Node* head, int total){
  total ++;
  if(head->getNext() != NULL){
    lenList(head->getNext(), total);
  }
  else{
    return total;
  }
}

//return number of times an int appears in list
int count(Node* current, int searchFor, int total){
  if(current->getValue() == searchFor){
    total++;
  }
  if(current->getNext() != NULL){
    count(current->getNext(), searchFor, total);
  }
  else{
    return total;
  }
}

/*
void sortList(Node* &head){
  //if head is more than next
  //swap, run sort list again
  //move to next
  */

//creates new list using first and last nodes of given list, returns head of new list
Node* abrevList(Node* &head){
  Node* newHead = new Node();
  newHead->setValue(head->getValue());
  Node* current = head;
  while(current->getNext() != NULL){
    current = current->getNext();
  }
  Node* last = new Node();
  last->setValue(current->getValue());
  newHead->setNext(last);
  return newHead;
}

//returns 2 highest values in list
void findHighest(Node* current, int num1, int num2){
  if(current != NULL){
    if(current->getValue() != num1 && current->getValue() != num2 && (current->getValue() > num1 || current->getValue() > num2)){
      if(num1 <= num2){
	num1 = current->getValue();
      }
      else{
	num2 = current->getValue();
      }
    }
    findHighest(current->getNext(), num1, num2);
  }
  else{
    cout << "The two highest values are: " << num1 << "," << num2 << endl;
  }
}

//returns two lowest values is list
void findLowest(Node* current, int num1, int num2){
  if(current != NULL){
    if(current->getValue() != num1 && current->getValue() != num2 && (current->getValue() < num1 || current->getValue() < num2)){
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
    cout << "The two lowest values are: " << num1 << "," << num2 << endl;
  }
}

//prints list in one line like this: 1,2,3,4
void print(Node* start){
  if(start != NULL && start->getNext() != NULL){
    start->display();
    cout << ",";
    print(start->getNext());
  }
  else{
    start->display();
    cout << endl;
  }
}

//adds node with num as value at end of list
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
