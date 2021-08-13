// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = x; i <= n; i += x)
            dp[i] = dp[i - x] + 1;
        if (y <= n)
        {
            dp[y] = 1;
            for (int i = y; i <= n; i++)
                if (dp[i - y] > 1)
                    dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (z <= n)
        {
            dp[z] = 1;
            for (int i = z; i <= n; i++)
                if (dp[i - z] > 0)
                    dp[i] = max(dp[i], dp[i - z] + 1);
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{

    //taking testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;
    }

    return 0;
} // } Driver Code Ends