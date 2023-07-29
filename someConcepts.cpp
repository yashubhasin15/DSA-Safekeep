#include<iostream>
#include<iomanip> //for using setw manipulator
using namespace std;

int a=8;

int main(){
    // *******Global and local Variables*********
    int a=1;
    cout<<"the value of local a is "<<a<<endl;
    cout<<"the value of global a is "<<::a<<endl;
    cout<<endl;

    // ********Float, double and double long Literals*********
    //float is 4 bytes, double is 8 bytes and long dohble is 12 bytes. By default, a decimal number is considered as double, so to make it float, we write 34.4f and for long double, we write 34.4l. Below, since we are already declaring type, we dont need to write f or l(unlike java where we have to specify float even if we declared it already)
    float b= 34.4;
    long double c= 34.4;
    cout<<"Size of 34.4 is: "<<sizeof(34.4)<<endl;
    cout<<"Size of 34.4f is: "<<sizeof(34.4f)<<endl;
    cout<<"Size of float variable is: "<<sizeof(b)<<endl;
    cout<<"Size of 34.4l is: "<<sizeof(34.4l)<<endl;
    cout<<"Size of long double variable is: "<<sizeof(c)<<endl;
    cout<<endl;

    // **********Reference Vraiables*********
    float d= 111;
    float &e= d; // e is reference variable of d
    cout<<d<<endl<<e<<endl;
    cout<<endl;

    // *******Typecasting*********
    int f=44;
    cout<<(float)f<<endl<<float(f)<<endl; // float(f) and (float)f are the same. Also, in java, this would print 44.0 but in cpp, it not add decimal on its own,
    float g= 44.4;
    cout<<(int)g<<endl<<int(g)<<endl; //here float was converted to floor integer same as java.

    // ********Constant Vaiables********
    // adding const keywork before any variable wil make it constant
    const int h= 35;
    // h=34; this will produce error

    //setw sets a width for the characters to be printed, its used to right align
    cout<<"yo wtf:"<<setw(4)<<1<<endl;
    cout<<"yo wtf:"<<setw(4)<<11<<endl;
    cout<<"yo wtf:"<<setw(4)<<2213<<endl;
    return 0;
}