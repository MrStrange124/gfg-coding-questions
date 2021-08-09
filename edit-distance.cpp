// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
// } Driver Code Ends
class Solution
{
public:
    int solve(string s, string t, int n, int m)
    {
        if (n == 0)
            return m;
        if (m == 0)
            return n;
        if (dp[n][m] != -1)
            return dp[n][m];
        if (s[n - 1] == t[m - 1])
            return dp[n][m] = solve(s, t, n - 1, m - 1);

        return dp[n][m] = 1 + min(solve(s, t, n - 1, m - 1), min(solve(s, t, n, m - 1), solve(s, t, n - 1, m)));
    }
    int editDistance(string s, string t)
    {
        int n = s.length(), m = t.length();
        memset(dp, -1, sizeof(dp));
        return solve(s, t, n, m);
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends