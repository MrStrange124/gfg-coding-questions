// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int sb(int arr[], int n, int x)
    {
        int l = 0, sum = 0, i = 0, mn = INT_MAX;
        while (i < n)
        {
            sum += arr[i];
            while (sum > x)
            {
                sum -= arr[l];
                mn = min(mn, i - l + 1);
                l++;
            }
            i++;
        }
        return mn;
    }
};

// { Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.sb(a, n, x) << endl;
    }
    return 0;
} // } Driver Code Ends