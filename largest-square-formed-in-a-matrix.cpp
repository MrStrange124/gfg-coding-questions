// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        int ans = 0, j, k, l, r;
        for (j = 0; j < m; j++)
            ans = max(ans, mat[0][j]);
        for (int i = 1; i < n; i++)
        {
            for (j = 0; j < m; j++)
                if (mat[i][j])
                    mat[i][j] += mat[i - 1][j];
            for (j = 0; j < m; j++)
            {
                if (mat[i][j] > ans)
                {
                    l = j;
                    r = j;
                    while (mat[i][l] >= mat[i][j] && l >= 0)
                        l--;
                    while (mat[i][r] >= mat[i][j] && r < m)
                        r++;
                    if (r - l - 1 >= mat[i][j])
                        ans = mat[i][j];
                    else if (ans < r - l - 1)
                        ans = r - l - 1;
                }
            }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
} // } Driver Code Ends