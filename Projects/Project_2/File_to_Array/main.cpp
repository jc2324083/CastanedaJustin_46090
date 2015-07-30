/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on July 29, 2015, 12:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void fileOpen();
void getInput();

int main(int argc, char** argv) {
    
    fileOpen();
  
    return 0;
}

void fileOpen(){
  std::fstream infile;
  infile.open("passcode.txt");{
    if(!infile){
       std::cerr << "Error: file could not be opened" << std::endl;
       exit(1);
    }
    std::cout << "File is open" << std::endl;
  }
  int array[5];
  int i=0;
  while (i<5&&infile>>array[i]){
      i++;
  }
  //
  for (int j=0;j<5;j++){
      cout<<array[j]<<" ";
  }
}


