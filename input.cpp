#include<iostream>
#include<string>

using namespace std;

int main()
{
    string name;
    cout<<"Enter a statement: ";
    getline(cin,name);// this will cath whole sentence(just like scanner.nextLine in java)
    cout<<name<<endl;

    string name2;
    cout<<"Enter the name: ";
    cin>>name2;// this will only cath first word(just like scanner.next in java)
    cout<<name2<<endl;

    int num1, num2;
    cout<<"Enter first number: ";
    cin>>num1;
    cout<<"Enter second number: ";
    cin>>num2;
    cout<<"Sum is: "<<num1+num2<<endl;

    return 0;

}
