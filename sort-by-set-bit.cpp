
#include <bits/stdc++.h>

using namespace std;
int cmp(int a, int b)
{
    if (__builtin_popcount(a) <= __builtin_popcount(b))
        return false;
    return true;
}
void sortBySetBitCount(int arr[], int n)
{
    stable_sort(arr, arr + n, cmp);
    // sort(arr, arr + n, cmp);
}

// Utility function to print an array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortBySetBitCount(arr, n);
    printArr(arr, n);
    return 0;
}
