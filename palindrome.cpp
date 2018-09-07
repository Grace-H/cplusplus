#include <iostream>
#include <cstring>

using namespace std;

int main(){
  char original[80];
  cin.get(original, 80);
  cin.get();
  char input[80];
  int count = 0;
  int letterTotal = 0;
  while (original[count] != '\n' && count < 80 && original[count] != '\0'){
    if (isalnum(original[count])){
      input[letterTotal] = original[count];
      letterTotal++;
    }
    count++;
  }
  input[count] = '\0';
  cout << input << endl;
  
  return 0;
}
