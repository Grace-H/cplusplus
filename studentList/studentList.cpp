#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>

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
void printS();

int main(){
  char addStr[10] = "ADD";
  char deleteStr[10] = "DELETE";
  char printStr[10] = "PRINT";
  char quitStr[10] = "QUIT";


  //student vector
  vector<Student*> stuVector;
  vector<Student*>* students = &stuVector;
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
      cout << "Printed students" << endl;
    } else if (strcmp(input, quitStr) == 0){
      stillRunning = false;
      cout << "Quit application" << endl;
    } else {
      cout << "Sorry, did not recognize that command" << endl;
    }
  }
  //if ADD:
  //if PRINT
  //if DELETE
  //if QUIT
  
  return 0;
}

void addS(vector<Student*>* students){
  Student student;
  char input[20];
  cout << "First name: " << endl;
  cin.get(input, 20);
  cin.get();
  strcpy(student.firstN, input);
  cout << "Last name: " << endl;
  cin.get(input, 20);
  cin.get();
  strcpy(student.lastN, input);
  int id;
  cout << "Student ID: " << endl;
  cin >> id;
  student.id = id;
  float gpa;
  cout << "GPA: " << endl;
  cin >> gpa;
  student.gpa = gpa;
  cout << student.firstN << student.lastN << student.gpa << student.id << endl;
}
