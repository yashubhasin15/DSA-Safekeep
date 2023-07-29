#include<iostream>
#include<string>

using namespace std;

struct employee
{
    int age;
    string name;
    char favChar;
    float salary; 
};

// by using typedef keyword, we can create shorm form to declare a struct
typedef struct student
{
    int age;
    string name;
    char favChar;
    float fees; 
} st; // now we only write "st bhasin" while declaring instead  of "stuct student bhasin"

//if we use union instead of struct, we can use only one of the variables at a time. it helps in space management. here at a time, we'll either be using cash or gold or stock as money
union money{
    double cash;
    float gold;
    int stock;
};

int main(){
    struct employee yashu;
    st bhasin;

    yashu.name = "yashu";
    bhasin.name = "bhasin";
    yashu.favChar = '&';
    bhasin.fees = 23039.21;
    cout << yashu.name << endl;
    cout << bhasin.name << endl;
    cout << yashu.favChar << endl;
    cout << bhasin.fees << endl;
     cout << bhasin.age << endl<<endl;//this will throw some garbage value
    

    union money m1;
    m1.cash=122.44;
    m1.stock=3901;
    m1.gold=3.2;
    cout<<m1.gold<<endl;
    cout<<m1.stock<<endl;// this will throw garbage value
    cout<<m1.cash<<endl;// " " " " " "
    
    return 0;
}