#include "std_lib_facilities.h"
//practicing dynamic memory allocations.
using namespace std;

int main(){

    int n,m;
    cout<<"Enter the values of rows and columns: "<<endl;
    cin>>n;
    cin>>m;

    //creating a matrix using dynamic memory allocation
    int** arr = new int*[n];
    for(int i = 0;i<m;i++){
        arr[i] = new int[n];
    }
    cout<<"Enter the elements of the array: "<<endl;

    //taking inputs
    for(int i = 0 ;i< n;i++){
        for(int j = 0 ;j<m ; j++){
            cin>>arr[i][j];
        }
    }

    //printing the matrix
    cout<<"The matrix is: "<<endl;
    for(int i = 0 ;i< n;i++){
        for(int j = 0 ;j<m ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //releasing the memory
    for(int i = 0;i<n;i++){
        delete [] arr[i];
    }
    delete []arr;
    return 0;
}