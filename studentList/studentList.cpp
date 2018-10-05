#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

struct Student {
  char firstN[20];
  char lastN[20];
  int id;
  float gpa;
};

//vector pointer as parameter for each
void addS(vector<Student*>* students);
void deleteS();
void printS(vector<Student*>* students);

int main(){
  char addStr[10] = "ADD";
  char deleteStr[10] = "DELETE";
  char printStr[10] = "PRINT";
  char quitStr[10] = "QUIT";


  //student vector
  vector<Student*>* students = new vector<Student*>;
  //vector<Student*>* students = &stuVector;
  //while still running
  cout << "Welcome to student list." << endl;

  bool stillRunning = true;
  char input[256];
  while (stillRunning){
    cout << "Ready for command 'ADD' 'DELETE' 'PRINT' 'QUIT'" << endl;
    cin.get(input, 256);
    cin.get();
    for(int i = 0; i < 256; i++){
      input[i] = toupper(input[i]);
    }
    cout << input << endl;
    if(strcmp(input, addStr) == 0){
      addS(students);
      cout << "Added Student" << endl;
    } else if (strcmp(input, deleteStr) == 0){
      cout << "Deleted Student" << endl;
    } else if (strcmp(input, printStr) == 0){
      printS(students);
      cout << "Printed students" << endl;
    } else if (strcmp(input, quitStr) == 0){
      stillRunning = false;
      cout << "Quit application" << endl;
    } else {
      cout << "Sorry, did not recognize that command" << endl;
    }
  }  
  return 0;
}

//WORKING ON THIS
void printS(vector<Student*>* students){
  cout << students->size() << endl;
  //cout << students->begin() << endl;
  //cout << students->end() << endl;
  for(vector<Student*>::iterator it = students->begin(); it != students->end(); ++it){
    cout << "it: " << *it << endl;
    cout << (*it)->firstN << " " << (*it)->lastN << endl;
    cout << "ID: " << (*it)->id << endl;
    cout << "GPA: " << (*it)->gpa << endl;
  }
}
void addS(vector<Student*>* students){
  Student *student = new Student;
  char input[20];

  //get a valid first name
  cout << "First name: " << endl;
  cin.get(input, 20);
  cin.get();
  strcpy(student->firstN, input);

  //get a valid last name
  cout << "Last name: " << endl;
  cin.get(input, 20);
  cin.get();
  strcpy(student->lastN, input);

  //get a valid student ID
  bool valid = true;
  cout << "Student ID: " << endl;
  int id = 0;
  //do {
  //id = 0;
  cin.get(input, 20);
  cin.get();
  id = atoi(input);
  student->id = id;

  //get a valid gpa
  float gpa = 0;
  cout << "GPA: " << endl;
  cin.get(input, 20);
  cin.get(); 
  gpa = atof(input);
  student->gpa = gpa;

  //add student to vector
  //Student* stuPtr = &student;
  students->push_back(student);
  cout << students->size() << endl;
  cout << student->firstN << student->lastN << student->gpa << student->id << endl;

  printS(students);
}
