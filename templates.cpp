#include<iostream>
using namespace std;

template <typename T, typename V>
class Pair{
  T x;
  V y;

  public:
  T getX(){
    return x;
  }
  void setX(T x){
    this->x = x;
  }
  V getY(){
    return y;
  }
  void setY(V y){
    this->y = y;
  }
};

int main(){
  Pair<int,char> p1;
  p1.setX(5);
  p1.setY('a');
  cout<<p1.getX()<<" "<<p1.getY()<<endl;

  //now if we want to make a triplet without making a separate class with 3 variables, then..
  Pair<int,Pair<double,char>> p2;
  p2.setX(8);
  //Y in p2 is of the type Pair, so we create a separte pair with double and char and pass it in p2
  Pair<double,char> p3;
  p3.setX(23.34);
  p3.setY('e');

  //now just set Y of p3 as object p2.
  p2.setY(p3);
  cout<<p2.getX()<<" "<<p2.getY().getX()<<" "<<p2.getY().getY()<<endl;

  return 0;
}