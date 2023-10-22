#include "std_lib_facilities.h"
//[1,2,3,4] result should be [24,12,8,6]
using namespace std;

void Result(vector<int> &arr,int n,vector<int> &ans){
    for(int i =0 ;i<n;i++){
        if(arr[i]==0){
            ans[i] =0;
        }
        else{

            ans[i] = (ans[i]/arr[i]);
        }
    }

}

int main(){

    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;

    cout<<"Enter the elements of the array: "<<endl;

    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    
    int multSum = 1;
    for(int i=0;i<n;i++){
        multSum =( v[i] * multSum);
    }
    vector<int> ans(n,multSum);

    Result(v,n,ans);

    cout<<"The answer is : "<<endl;
    for(int i:ans){
        cout<<i<<endl;
    }

    return 0;
}