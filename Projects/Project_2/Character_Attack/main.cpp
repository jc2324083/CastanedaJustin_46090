/* 
 * File:   main.cpp
 * Author: Justin Castaneda
 * Created on July 7, 2015, 6:28 PM
 * Purpose: Practice Character attacks
 */
//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Function Prototypes
int catk(int atkmin,int atkmax);

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
        int attack=catk(10,1);
        cout<<"You did "<<attack<<" damage to the creature."<<endl;
        
    }
    return 0;
}

int catk(int amin,int amax){
    int sum;

    for (int atk=1;atk<=amax;atk++){
            sum+=(rand()%amin+15);
            
            return sum;
        }
       
}