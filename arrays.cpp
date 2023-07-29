#include<iostream>
using namespace std;

int main(){
    int marks[]= {1,2,3,4,5};

    int percent[5];
    percent[0]=90;
    percent[1]=91;
    percent[2]=94;
    percent[3]=87;
    percent[4]=99;

    for(int i=0;i<5;i++){
        cout<<marks[i]<<endl;
    }
    cout<<endl;

    //the name of array acts as a pointer to the first element of array, and incrementing 1 in the array shifts the pointer to second element and so on.
    for (int i = 0; i < 5; i++)
    {
        cout<<*(percent+i)<<endl; //we cant write percentage++ as array cannot be modified like that
    }
    cout<<endl;

    int* a= percent; //but we can store address of array in a pointer variable and then increment/modify this variable. Also note that we didn't write &percent to store address as the variable percent is itself a reference to address of first block in the array
    for (int i = 0; i < 5; i++)
    {
        cout<<*(a++)<<endl;
    }

    
    
    return 0;
}