// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int countPS(string str)
    {
        int mod = 1e9 + 7;
        int n = str.length();
        unsigned cps[n + 1][n + 1];
        memset(cps, 0, sizeof(cps));
        for (int i = 0; i < n; i++)
            cps[i][i] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 0; j <= n - i; j++)
            {
                int k = i + j - 1;
                if (str[j] == str[k])
                    cps[j][k] = (cps[j][k - 1] + cps[j + 1][k] + 1) % mod;
                else
                    cps[j][k] = (1ll * cps[j][k - 1] + (cps[j + 1][k] - cps[j + 1][k - 1])) % mod;
            }
        return cps[0][n - 1];
    }
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout << ans << endl;
    }
} // } Driver Code Ends