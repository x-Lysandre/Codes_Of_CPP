#include "std_lib_facilities.h"
using namespace std;
// Binary search in a 2d array
int BinarySearch(vector<vector<int>> v, int r, int c, int target)
{
    int s = 0;
    int e = r * c - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        int midvalue = v[mid / c][mid % c];

        if (midvalue == target)
        {
            return mid;
        }
        if (midvalue > target)
        {
            e = mid = 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int r, c;
    cout << "Enter the number of rows in the matrix: ";
    cin >> r;
    cout << "Enter the number of columns in the matrix: ";
    cin >> c;
    vector<vector<int>> v(r, vector<int>(c));
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> v[i][j];
        }
    }

    int target;
    cout << "Enter the element to search: ";
    cin >> target;
    int ans = BinarySearch(v,r,c,target);

    if(ans == -1){
        cout<<"Element was not found in the matrix:";
    }
    else{
        cout<<"The element is present in the "<<ans + 1<< " index.";
    }

    return 0;
}