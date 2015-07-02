/* 
 * File:   main.cpp
 * Author: Justin Castaneda
 * Created on July 2, 2015, 11:02 AM
 * Purpose:Fibonacci sequence
 */

//System Libraires
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constant

//Function Prototypes

//Execution!!
int main(int argc, char** argv) {
    //Declare and initialize members of the sequence
    unsigned short fi=1,fip1=1,fip2;
    unsigned char terms=10;
    
    //Print the initial conditions
    cout<<"The number of terms in the Fibonacci sequence to display is "<<terms<<endl;
    cout<<"Term "<<1<<" in the sequence = "<<fi<<endl;
    cout<<"Term "<<2<<" in the sequence = "<<fip1<<endl;
    
    //Loops and show the terms as you generate
    for(unsigned char term=3;term<=terms;term++){
        //Calculate the next term in the sequence
        fip2=fi+fip1;
        
        //Output the current term
        cout<<"Term "<<static_cast<int>(term)<<" in the sequence = "<<fip2<<endl;
        
        //No shift
        fi=fip1;
        fip1=fip2;
        
    }

    return 0;
}

