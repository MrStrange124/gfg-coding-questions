// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n, int x);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        ans = find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends

int binary(int arr[], int l, int r, int x)
{
    if (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return binary(arr, l, mid - 1, x);
        else
            return binary(arr, mid + 1, r, x);
    }
    return -1;
}
vector<int> find(int arr[], int n, int x)
{
    vector<int> v;
    int i = 0, first = -1, last = -1;
    first = last = binary(arr, 0, n - 1, x);
    while (first - 1 >= 0 && arr[first - 1] == x)
        first--;
    while (last + 1 < n && arr[last + 1] == x)
        last++;
    v.push_back(first);
    v.push_back(last);
    return v;
}