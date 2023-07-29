#include<iostream>
using namespace std;
#include "BSTclass.h"

int main(){
  BST b;
  b.insertData(5);
  b.insertData(4);
  b.insertData(64);
  b.insertData(24);
  b.insertData(1);
  b.insertData(5);

  b.printTree();
  cout<<endl;

  b.deleteData(5);
  b.deleteData(4);
  b.printTree();
  cout<<endl;

  cout<<b.hasData(64)<<endl;
  cout<<b.hasData(3)<<endl;
  return 0;
}