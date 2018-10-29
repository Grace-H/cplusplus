//Student List: User can enter, delete, and print out students
//Author: Grace Hunter
//Date: 11 October 2018

#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

//struct Student, will hold data about each student
struct Student {
  char firstN[256];
  char lastN[256];
  int id;
  float gpa;
};

void addS(vector<Student*>* students);
void deleteS(vector<Student*>* students);
void printS(vector<Student*>* students);
void quit(vector<Student*>* students);

int main(){
  //cstrings with commands for comparision
  char addStr[10] = "ADD";
  char deleteStr[10] = "DELETE";
  char printStr[10] = "PRINT";
  char quitStr[10] = "QUIT";

  //student vector
  vector<Student*>* students = new vector<Student*>;

  //Welcome!
  cout << "Welcome to student list." << endl;
  
  //continue to read in commands while still running
  bool stillRunning = true;
  char input[256];
  while (stillRunning){
    
    //get a command from the user
    cout << "Ready for command 'ADD' 'DELETE' 'PRINT' 'QUIT'" << endl;
    cin.get(input, 256);
    cin.get();
    
    //make all caps
    for(int i = 0; i < 256; i++){
      input[i] = toupper(input[i]);
    }

    //match the input to a command and run corresponding function
    if(strcmp(input, addStr) == 0){ //ADD
      addS(students);
      cout << "Added Student" << endl;
    } else if (strcmp(input, deleteStr) == 0){ //DELETE
      deleteS(students);
    } else if (strcmp(input, printStr) == 0){ //PRINT
      printS(students);
    } else if (strcmp(input, quitStr) == 0){ //QUIT
      quit(students);
      stillRunning = false;
      cout << "Quit application" << endl;
    } else { //input not recognized, prompt again
      cout << "Sorry, did not recognize that command" << endl;
    }
  }  
  return 0;
}

//deletes all vector data
void quit(vector<Student*>* students){
  //delete everything in vector
  while (!students->empty()){
    vector<Student*>::iterator it = students->begin();
    students->erase(it);
  }
  //delete vector
  delete students;
  
}

//deletes a student based on provided ID number
void deleteS(vector<Student*>* students){
  //get the ID number from user
  char input[256];
  cout << "Enter the student's ID:" << endl;
  cin.get(input, 256);
  cin.get();
  int id = atoi(input);

  //find student with matching ID
  bool found = false;
  vector<Student*>::iterator student;
  for(vector<Student*>::iterator it = students->begin(); it != students->end(); ++it){
    if((*it)->id == id){
      student = it;
      found = true;
    }
  }
  //if one was found, delete it
  if(found == true){
   cout << "Deleted Student" << endl;
    students->erase(student);
  }
  else{ //else tell user no student matched
    cout << "No matching student" << endl;
  }
}

//print out all students: First Last, ID, GPA
void printS(vector<Student*>* students){
  //loop throuhg vector and print out information for each student
  for(vector<Student*>::iterator it = students->begin(); it != students->end(); ++it){
    cout << (*it)->firstN << " " << (*it)->lastN << ", " << (*it)->id << ", " << setprecision(3) << (*it)->gpa << endl;
  }
}

//prompt and parse information from user to add a new student
void addS(vector<Student*>* students){
  //create a student pointer
  Student *student = new Student;

  char input[256];

  //get a valid first name and store
  cout << "First name: " << endl;
  cin.get(input, 256);
  cin.get();
  strcpy(student->firstN, input);

  //get a valid last name and store
  cout << "Last name: " << endl;
  cin.get(input, 256);
  cin.get();
  strcpy(student->lastN, input);

  //get a valid student ID and store
  bool valid = true;
  cout << "Student ID: " << endl;
  int id = 0;
  cin.get(input, 256);
  cin.get();
  id = atoi(input);
  student->id = id;

  //get a valid gpa
  float gpa = 0;
  cout << "GPA: " << endl;
  cin.get(input, 256);
  cin.get(); 
  gpa = atof(input);
  student->gpa = gpa;

  //add student to vector
  students->push_back(student);
}
