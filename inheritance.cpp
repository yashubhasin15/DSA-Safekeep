#include<iostream>
#include<string>
using namespace std;

class Chef{
    public:
        void makeBread(){
            cout<<"The chef makes Bread"<<endl;
        }
        void makePasta(){
            cout<<"The chef makes Pasta"<<endl;
        }
        void makeChicken(int n){
            cout<<"The chef makes "<<n<<" pieces of chicken"<<endl;
        }
};

class ItalianChef:public Chef{
    public:
        void makePizza(){
            cout<<"The Italian Chef makes Pizza"<<endl;
        }
        void makePasta(){
            cout<<"The Italian Chef makes Italian style Pasta"<<endl;
        }
};

int main(){
    Chef c1;
    ItalianChef c2;

    c1.makePasta();
    c2.makePasta(); //updated method in c2
    // c1.makePizza(): //error as c1 doesnt make pizza
    c2.makeChicken(6); //inherited from c1
    

    return 0;
}