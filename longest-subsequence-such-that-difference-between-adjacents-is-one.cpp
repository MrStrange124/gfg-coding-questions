// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int longestSubsequence(int N, int A[])
    {
        vector<int> dp(N, 1);
        int j;
        for (int i = 1; i < N; i++)
        {
            j = i - 1;
            while (j >= 0)
            {
                if (A[i] == A[j] + 1 || A[i] == A[j] - 1)
                    dp[i] = max(dp[i], dp[j] + 1);
                j--;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.longestSubsequence(N, A) << endl;
    }
    return 0;
} // } Driver Code Ends