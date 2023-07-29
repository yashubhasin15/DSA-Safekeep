#include<iostream>
#include<string>

using namespace std;

void sayhi(string name, int age){
    cout<< "Hello "<<name<<" ,Your age is "<<age<<endl;
}

double cube(double a){
    return a*a*a;
}

int main(){
    sayhi("Yashu",19);
    cout<< cube(4.5) <<endl;
    return 0;
}