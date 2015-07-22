/* 
 * File:   main.cpp
 * Author: Justin Castaneda
 * Created on July 14, 2015, 10:08 AM
 * Purpose: Practicing charge attacks
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Function Prototypes
int chrgAtk(int,int);

//Engage
int main(int argc, char** argv) {
    //Random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    int command;
    
    
    //Input Command
    cout<<"Enter 1 please...";
    cin>>command;
    
    if (command==1){
        int attack=chrgAtk(20,1);
        cout<<"You did "<<attack<<" damage to the creature."<<endl;
        
    }
    return 0;
}

int chrgAtk(int amin,int amax){
    int sum;

    for (int atk=1;atk<=amax;atk++){
            sum+=(rand()%amin+32);
            
            return sum;
        }
       
}