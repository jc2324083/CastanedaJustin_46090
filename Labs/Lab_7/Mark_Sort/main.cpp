/* 
 * File:   main.cpp
 * Author: Justin Castaneda
 * Created on July 14, 2015, 12:12 PM
 * Purpose: Simple sort
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void filAray(int[],int);
void prntAray(const int [],int,int);
void swap(int &, int &);
void swapMin(int [],int,int);
void markSrt(int [],int);
int linSrch(int [],int,int);

//Engage!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=200;
    int array[SIZE];
    
    //Initialize the array
    filAray(array,SIZE);
    
    //Process the inputs
    markSrt(array,SIZE);
    
    //Output the results
    prntAray(array,SIZE,20);
    
    //Test the search routine
    int value=rand()%90+10;
    int pos=linSrch(array,SIZE,value);
    if(pos==-1)cout<<value<<" was not found!"<<endl;
    else cout<<value<<" was found at array["<<pos<<"]"<<endl;
    
    //Exit
    return 0;
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
void filAray(int a[],int n){
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
void prntAray(const int a[],int n,int nCols){
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

/*********************************************************************
 *                            Swap                                   *
 *********************************************************************
 * Purpose: To swap by logical operations two values
 * Input-Output:
 *     a->the integer value
 *     b->the integer value

 **********************************************************************/
void swap(int &a, int &b){
    //Perform the logical in-place swap
    a=a^b;
    b=a^b;
    a=a^b;
}

/*********************************************************************
 *                            SwapMin                                *
 *********************************************************************
 * Purpose: To place the minimum at the top of the list
 * Input:
 *     a->the integer array/list
 *     b->the size of the array/list
 *     pos->Position to place the minimum
 * Input-Output:
 *     a-> An integer array/list

 **********************************************************************/
void swapMin(int a[],int n,int pos){
    //Loop through the list starting at pos+1
    for(int i=pos+1;i<n;i++){
        //Place smallest
        if(a[pos]>a[i])swap(a[pos],a[i]);
    }
}

void markSrt(int a[],int n){
    //Loop and sort every position
    for(int pos=0;pos<n-1;pos++){
        swapMin(a,n,pos);
    }
}

/*********************************************************************
 *                            SwapMin                                *
 *********************************************************************
 * Purpose: To find where a value resides
 * Input:
 *     n->The size of the array
 *     a->The integer
 *     val->The value to search find
 * Output:
 *     Position where val was found

 **********************************************************************/
int linSrch(int a[],int n,int val){
    //Loop until value is found
    for(int i=0;i<n;i++){
        //Report back if found
        if(a[i]==val)return i;
    }
}