/* 
 * File:   main.cpp
 * Author: Justin Castaneda
 * Created on July 13, 2015, 11:09 AM
 * Purpose: To Test Nova Crystal Item
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
//User Libraries

//Global Constant

//Function Prototypes
int recover(int);

//Engage!
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    int hp=50;          //Character health power
    int command;        //input command
    
    //Input
    cout<<"Input a command (type 2)";
    cin>>command;
    
    if(command==2){
        int heal=recover();
        hp=hp+heal;
    }
    
    return 0;
}

int recover(){
    
}