#include<iostream>
#include<vector>

using namespace std;

void Merge(vector<int> &v,int start,int end, int mid){


    //copying the leftmost part of the array to a new array.
    vector<int> v1;
    for(int k=0;k<=mid;k++){
        v1.push_back(v[k]);
    }

    //copying the rightmost part of the array to another array.
    vector<int> v2;
    for(int l= mid +1;l<=end;l++){
        v2.push_back(v[l]);
    }

    //now merging the two newly formed arrays 
    int i = 0;
    int j = 0;
    int mainArrayIndex = 0;

    while(i<v1.size() && j<v2.size()){
        if(v1[i]<v2[j]){
            v[mainArrayIndex++] = v1[i++];
        }
        else{
            v[mainArrayIndex++] = v2[j++];
        }
    }

    while(i<v1.size()){
            v[mainArrayIndex++] = v1[i++];
    }

    while(j<v2.size()){
            v[mainArrayIndex++] = v2[j++];
    }


}

void MergeSort(vector<int> &v,int start,int end){
    int mid = (start+end)/2;

    //base cas 
    if(start>=end){
        return ;
    }

    //left half of the array 
    MergeSort(v,start,mid);

    //right half of the array 
    MergeSort(v,mid+1,end);

    //now merging the two arrays
    Merge(v,start,end,mid);
}

int main(){
    //array to be sort
    vector<int> v={2,5,3,9,6};

    int n = v.size();

    MergeSort(v,0,n-1);

    cout<<endl<<"printing the sorted array: "<<endl;
    for(int i : v){
        cout<< i << " ";
    }

    return 0;
}