#include<iostream>
using namespace std;

int main(){
    int a=4, b=6;
    cout<<a++<<endl;
    cout<<--a<<endl;
    cout<<++b<<endl;
    cout<<b--<<endl;
    cout<<(a==b)<<endl;
    cout<<(a!=b)<<endl;
    cout<<(a>b)<<endl;
    cout<<(a<b)<<endl;
    cout<<((a==b)&&(a<b))<<endl;
    cout<<((a==b)||(a<b))<<endl;
    cout<<!(a>b)<<endl;
    return 0;
}