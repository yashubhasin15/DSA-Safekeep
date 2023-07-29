#include <iostream>
using namespace std;

int main(){
    int* a= new int;//this will create an 8 byte storage for pointer a in the stack memory and 4 byte storage for int in heap memory
    *a=5;
    cout<<*a<<endl;
    delete a;//this will delete the int memory in the heap but not the pointer memory in the stack

    a= new int[100];//since only the heap memory is deleted and pointer a still exists, we can reassign a new value to the pointer. Also, new int[100] will create a 400byte memory in the heap
    delete [] a;//to delee array memory from the heap, we have to write [] to specify its an array

    int n;
    cin>>n;
    int* b= new int[n];//heap memory is allocated in runtime so it is prefered to create user input arrays in the heap memory

    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    delete [] b;
    

    return 0;
}