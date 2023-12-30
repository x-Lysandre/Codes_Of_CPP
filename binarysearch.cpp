#include "std_lib_facilities.h"
using namespace std;

int binarysearch(int arr[], int key, int n)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end-start) / 2;
    while (start <= end)
    {
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
int main()
{

    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter an element for searching: ";
    int m;
    cin >> m;
    cout<<binarysearch(a, m, n);
    return 0;
}