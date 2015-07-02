/* 
 * File:   main.cpp
 * Author: Justin Castaneda
 *
 * Created on July 2, 2015, 12:10 PM
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
    float fact=1;
    unsigned n=6;
    
    //Loop and find the n!
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    //Output the result
    cout<<static_cast<int>(n)<<"!="<<fact<<endl;
    
    
    return 0;
}

