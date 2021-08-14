// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        set<int> arr;
        for (int i = 0; i < n; i++)
            arr.insert(a[i]);
        for (auto i : arr)
            for (int j = 1; j <= n; j++)
            {
                if (i == a[j - 1])
                    dp[j] = 1 + dp[j];
                else
                    dp[j] = max(dp[j - 1], dp[j]);
            }
        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        //taking size of array
        cin >> n;
        int a[n];

        //inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends