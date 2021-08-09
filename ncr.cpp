#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int mod = 1e9 + 7;
int t[1001][801];
class Solution
{
public:
    Solution()
    {
        memset(t, -1, sizeof(t));
    }
    int nCr(int n, int r)
    {
        if (r > n)
            return 0;
        if (r == 0 || n == r)
            return 1;
        if (r == 1)
            return n;
        if (t[n][r] != -1)
            return t[n][r];

        return t[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % mod;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
}