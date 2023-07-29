#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char reVal(int num){
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

string fromDeci(int base, int inputNum){
    string res;
    int index = 0;
    while (inputNum > 0) {
        res.push_back(reVal(inputNum % base));
        inputNum /= base;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    cout<<fromDeci(4,11);
    return 0;
}
