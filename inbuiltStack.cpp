#include<iostream>
#include<climits>
#include<stack>
using namespace std;


int main(){
  //for int
  stack<int> s1;
  s1.push(10);
  s1.push(20);
  s1.push(30);
  s1.push(40);

  //inbuilt stack has the function empty(), not isEmpty()
  cout<<s1.empty()<<endl;

  //pop function of inbuilt stack has return type void. so it only deletes the top element but doesnt return it
  cout<<s1.top()<<endl;
  s1.pop();
  s1.pop();

  cout<<s1.top()<<endl;

  s1.pop();
  cout<<s1.size()<<endl;

  s1.pop();
  s1.pop();

  cout<<endl;

  // for char
  stack<char> s2;
  s2.push('c');
  s2.push('?');
  s2.push('4');
  s2.push(121);
  s2.push(30);

  cout<<s2.empty()<<endl;

  s2.pop();
  s2.pop();

  cout<<s2.top()<<endl;

  s2.pop();

  cout<<s2.size()<<endl;

  s2.pop();
  s2.pop();
  s2.pop();
  
  return 0;
}