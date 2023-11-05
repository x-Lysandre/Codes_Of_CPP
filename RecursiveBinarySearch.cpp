#include "std_lib_facilities.h"
//Binary Search using Recursion
using namespace std;

bool binarySearch(int arr[], int size, int key){
    //base case
    if(size<=0){
        return false;
    }

    //recursive relation
    int mid = size/2;
    if(arr[mid]<key){
        return binarySearch(arr + mid + 1,size-mid -1,key);
    }
    if(arr[mid]>key){
        return binarySearch(arr ,size-mid,key);
    }
    return true;
    
}

int main(){

    int arr[10];
    int size;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;
    cout<<"Enter the array: "<<endl;
    for(int i=0;i<size;i++){
        cin >>arr[i];
    }
    int key;
    cout<<"Enter the element to find: ";
    cin>>key;
    if(binarySearch(arr,size,key)){
        cout<<"The element is present in the array.";
    }else{
        cout<<"The element is not present in the array.";
    }
    return 0;
}