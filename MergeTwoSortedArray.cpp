#include<iostream>
#include<vector>
using namespace std;

void mergeArray(vector<int> &v1,vector<int> &v2,vector<int> &v3){
    int i=0 , j=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i] < v2[j]){
            v3.push_back(v1[i]);
            i++;
        }
        else{
            v3.push_back(v2[j]);
            j++;
        }    
    }
    while(i<v1.size()){
        v3.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        v3.push_back(v2[j]);
        j++;
    }
}

int main(){

    vector<int> v1 = {1,3,5,7,9};
    vector<int> v2 = {2,4,6};

    vector<int> v3;

    mergeArray(v1,v2,v3);

    cout<<"The new array is: "<<endl;
    for(int i : v3){
        cout<<i<<" ";
    }
    return 0;
}