/* 
 * File:   main.cpp
 * Author: Justin Castaneda
 * Created on July 12, 2015, 6:28 PM
 * Purpose: Practice monster attacks
 */
//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Function Prototypes
int mAtk(int,int);

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
        int mAttack=mAtk(15,1);
        cout<<"The Creature did "<<mAttack<<" damage to you."<<endl;
        
    }
    return 0;
}

int mAtk(int amin,int amax){
    int msum;

    for (int atk=1;atk<=amax;atk++){
            msum+=(rand()%amin+15);
            
            return msum;
        }
       
}