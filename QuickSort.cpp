#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &v,int start,int end){
    int pit = v[start];

    //finding the number of elements  smaller than the pivot element
    int count = 0;
    for(int i =start+1;i<=end;i++){
        if(v[i]<pit){
            count++;
        }
    }

    int pivotIndex = start + count;

    //swapping the pivot to its position
    swap(v[start],v[pivotIndex]);

    int i = start;
    int j = end;

    while(i<pivotIndex && j>pivotIndex){
        while(v[i]<v[pivotIndex]){
            i++;
        }
        while(v[j]>v[pivotIndex]){
            j--;
        }
        if(i<pivotIndex && j> pivotIndex){
            swap(v[i++],v[j--]);
        }
    }
    return pivotIndex;
}

void QS(vector<int> &v,int start,int end){
    
    //base case
    if(start >= end){
        return;
    }

    int pivot = partition(v,start,end);

    //sorting the left array 
    QS(v,start,pivot-1);

    //sorting the right array
    QS(v,pivot+1,end);

}

int main(){

    vector<int> v ={2,4,6,1,9};

    QS(v,0,v.size()-1);

    for(int i : v){
        cout<<endl<<i<<" ";
    }


    return 0;
}