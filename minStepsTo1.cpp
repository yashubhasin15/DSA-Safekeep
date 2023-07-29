#include<iostream>
#include<algorithm>
using namespace std;

int minStepsTo1(int n,int* arr){
    if(n==1){
        return 0;
    }
    if(arr[n]!=-1){
        return arr[n];
    }
    int a=minStepsTo1(n-1,arr);
    int b= (n%2==0? minStepsTo1(n/2,arr):INT_MAX);
    int c= (n%3==0? minStepsTo1(n/3,arr):INT_MAX);

    int ans= 1+min(a,min(b,c));
    arr[n]=ans;
    return ans;
}

int main(){
    int n;
    cin>>n;
    int* arr= new int[n+1];
    for(int i=0;i<n+1;i++){
        arr[i]=-1;
    }
    cout<<minStepsTo1(n,arr);
    return 0;
}