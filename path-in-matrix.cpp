// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    int end;

public:
    int soln(int r, int c, int sum, vector<vector<int>> &Matrix, vector<vector<int>> &dp)
    {
        if (r == end)
            return sum;
        if (dp[r][c] != -1)
            return dp[r][c];
        int a = soln(r + 1, c, sum + Matrix[r][c], Matrix, dp), b = 0;
        b = a;
        if (c - 1 >= 0)
            a = max(soln(r + 1, c - 1, sum + Matrix[r][c], Matrix, dp), a);
        if (c + 1 < end)
            b = max(soln(r + 1, c + 1, sum + Matrix[r][c], Matrix, dp), b);
        return max(a, b);
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        end = N;
        vector<vector<int>> dp(N, vector<int>(N, -1));
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            ans = max(ans, soln(0, i, 0, Matrix, dp));
        }
        return ans;
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
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
} // } Driver Code Ends