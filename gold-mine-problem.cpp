// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int t[n + 1][m + 1];
        memset(t, -1, sizeof(t));
        for (int i = 1; i <= m; i++)
            t[1][i] = M[0][i - 1];
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                t[i][j] = max(M[i - 1][j - 1] + t[i - 1][j], t[i][j - 1] + t[i - 1][j] - t[i - 1][j - 1]);
            }
        return t[n][m];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
} // } Driver Code Ends