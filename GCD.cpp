#include "std_lib_facilities.h"
//Euclid's Algorithm
//gcd(a,b)=gcd(a-b,b)
using namespace std;

int GCD(int a , int b){
    if(a==0)
    return b;
    
    if(b==0){
        return a;
    }

    while(a!=b){
        if(a>b){
            a-=b;
        }
       else{
            b-=a;
        }
    }
    return a;
}

int main(){

    int a , b;
    cout<<"Enter the first number: ";
    cin>>a;
    cout<<"Enter the first number: ";
    cin>>b;
    int x =GCD(a,b);
    cout<<"The answer is : "<<x;
    return 0;
}