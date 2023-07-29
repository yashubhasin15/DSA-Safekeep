#include<iostream>
#include<string>
using namespace std;

class Smartphone{
  private:
    double rating;

  public:
    string company;
    int price;
    double ram;

    Smartphone(string company,int price, double ram, double rating){
      this->company=company;
      this->price=price;
      this->ram=ram;
      setRating(rating);//here we didnt directly assign rating because we wanted to apply the restriction on rating from 1 to 5
    }

    Smartphone(int price, double ram, double rating){
      this->company="Unbranded";
      this->price=price;
      this->ram=ram;
      setRating(rating);
    }

    bool isExpensive(){
      if(price>=21999){
        return true;
      }
      return false;
    }

    void setRating(double a){
      if(a>1&&a<5){
        rating=a;
      }
      else{
        rating=-1;
      }
    }

    double getRating(){
      return rating;
    }
};

int main(){
  Smartphone s1("samsung",23999,8.5,4.8);
  Smartphone s2(9999,4,0.9);
  
  cout<<s1.company<<endl;
  cout<<s1.price<<endl;
  cout<<s1.ram<<endl;
  cout<<s1.isExpensive()<<endl;
  // cout<<s1.rating<<endl;//we cant do this as rating is private
  cout<<s1.getRating()<<endl;
  s1.setRating(4.2);
  cout<<s1.getRating()<<endl<<endl;

  cout<<s2.company<<endl;
  cout<<s2.price<<endl;
  cout<<s2.ram<<endl;
  cout<<s2.isExpensive()<<endl;
  cout<<s2.getRating()<<endl;

  return 0;
}