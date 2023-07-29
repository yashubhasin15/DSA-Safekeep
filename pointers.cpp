#include<iostream>
using namespace std;

int main(){
    int a=3;
    int* b= &a;
    // & --> (Address of) Operator
    cout<<"The address of a is "<<&a<<endl;
    cout<<"The address of a is "<<b<<endl<<endl;

    // * --> (Value at) Dereference Operator
    cout<<"The value at address b is "<<*b<<endl<<endl;

    // pointer to pointer
    int** c= &b; //c is storing address of b which itself contains an address
    cout<<"The address of b is "<<&b<<endl;
    cout<<"The address of b is "<<c<<endl;
    cout<<"The value at address c is "<<*c<<endl; //this will give value of b which is address of a,so same output as line 8 and 9
    cout<<"The value at (value at address c) is "<<**c<<endl;

    return 0;
}