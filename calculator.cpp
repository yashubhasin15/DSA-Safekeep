#include<iostream>
using namespace std;

int main(){
  int num1,num2;
  char op;
  char cont='y';
  while(cont=='y'){
    cout<<"Enter first number: ";
    cin>>num1;
    cout<<"Enter second number: ";
    cin>>num2;
    cout<<"Enter operator: ";
    cin>>op;

    if(op=='+'){
      cout<<num1+num2<<endl;
    }
    else if(op=='-'){
      cout<<num1-num2<<endl;
    }
    else if(op=='*'){
      cout<<num1*num2<<endl;
    }
    else if(op=='/'){
      cout<<num1/num2<<endl;
    }
    else{
      cout<<"Invalid Operator"<<endl;
    }

    cout<<"Do you want to continue?(y/n): ";
    cin>>cont;
  }
  return 0;
}