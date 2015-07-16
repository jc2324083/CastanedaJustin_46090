/* 
 * File:   main.cpp
 * Author: Justin Castaneda
 * Created on July 16, 2015, 11:25 AM
 * Purpose: Calculate the mean and sta
 */
//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constant
const double MXRND=pow(2,31)-1;

//Function Prototype
float normal();
void filAray(float [],int);
void prntAray(const float [],int,int);
float max(float [],int);
float min(float [],int);
float mean(float [],int);

//Execute
int main(int argc, char** argv) {
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and initialize variables
    const int SIZE=100;
    float array[SIZE];
    
    //Initialize the array
    filAray(array,SIZE);
    
    //Output
    //prntAray(array,SIZE,5);
    
    cout<<"The max value in the array is "<<max(array,SIZE)<<endl;
    cout<<"The max value in the array is "<<min(array,SIZE)<<endl;
    cout<<"The mean value in the array is "<<mean(array,SIZE)<<endl;

    return 0;
}
float max(float a[], int n){
    //Declare Variables
    float max=a[0];
    //Loops to find max
    for(int i=1;i<n;i++){
        if(max<a[i])a[i]=max=a[1];
    }
    //return
    return max;
}

float min(float a[], int n){
    //Declare Variables
    float min=a[0];
    //Loops to find max
    for(int i=1;i<n;i++){
        if(min>a[i])a[i]=min=a[i];
    }
    //return
    return min;
}

float mean(float a[],int n){
    //Declare Variables
    float mean=0;
    //Loops to find max
    for(int i=1;i<n;i++){
        mean+=a[1];
    }
    //return
    return mean;
}

/****************************************************************************
 *                      Normal Distribution Approximation
 * **************************************************************************
 * Output-> Normal density function approximation
 * 
 */
float normal(){
    //Declare a Variable
    float norm=0;                       //[-6,6]
    
    //Loop 12 times
    for(int i=1;1<12;i++){
        norm+=(rand()/MXRND-0.5);       //[-0.5,0.5];
    }
    //Exit and return norm
    return norm;
}

/*********************************************************************
 *                      Fill Array                              *
 *********************************************************************
 * Purpose: To fill an array with 2 digit integer random numbers
 * Input:
 *     n-> The size of the array
 * Input-Output
 *     a-> The integer Array
 * Output:
 **********************************************************************/
void filAray(float a[],int n){
   //Loop on every element and equate to 2 digits
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;      //[10-99]
    }
}
/*********************************************************************
 *                      Print Array                              *
 *********************************************************************
 * Purpose: To print an integer array with any number of columns
 * Input:
 *     n-> The size of the array
 *     a->the integer array
 *     nCols->Number of columns to display the array
 * Output:
 *      on screen
 **********************************************************************/
void prntAray(const float a[],int n,int nCols){
    //Format
    cout<<fixed<<showpoint<<setprecision(4);
            
    //Separate outputs with a line
    cout<<endl;
    
    //Loop and output every element in the array
    for(int i=0;i<n;i++){
        
        cout<<a[i]<<" ";
        //when column is reached go to next line
        if(i%nCols==(nCols-1))
            cout<<endl;
    }
    //Separate outputs with a line
    cout<<endl;
}