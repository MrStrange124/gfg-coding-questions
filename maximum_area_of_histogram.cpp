// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        long long nright[n], i = 0, j = 0;
        stack<long> s, s2;
        for (i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (s.empty())
                nright[i] = n;
            else
                nright[i] = s.top();
            s.push(i);
        }
        long long ans = 0, index;
        for (i = 0; i < n; i++)
        {
            while (!s2.empty() && arr[s2.top()] >= arr[i])
                s2.pop();
            if (s2.empty())
                index = -1;
            else
                index = s2.top();
            s2.push(i);
            ans = max(ans, arr[i] * (nright[i] - index - 1));
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends