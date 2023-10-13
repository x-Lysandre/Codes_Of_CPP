#include <iostream>
#include <vector>
//sieve of eratosthenes
//to find the all prime numbers strictly lower than n
using namespace std;

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    int count = 0;
    
    //an vector to mark the prime numbers
    vector<bool> prime(n+1,true);
    prime[0] = prime[1] = false;
    
    for(int i = 2;i<=n;i++){
        if(prime[i]){
            count++;
            for(int j = 2;j<n;j++){
                prime[i*j]=false;
            }
        }

    }
    cout<<"The result is : "<<count;
    return 0;
    
}