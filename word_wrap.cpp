// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int solveWordWrap(vector<int> nums, int k)
    {
        int n = nums.size();
        int inf = INT_MAX;
        int dp[n][n], i, j, temp, l;
        int cost[n + 1], pos[n];
        cost[n] = 0;
        for (i = 0; i < n; i++)
        {
            temp = 0;
            for (j = i; j < n; j++)
            {
                temp += nums[j];
                l = temp + j - i;
                if (l <= k)
                    dp[i][j] = (k - l) * (k - l);
                else
                    dp[i][j] = inf;
            }
        }
        i = n - 1;
        int min;
        while (i > -1)
        {
            min = inf;
            j = n - 1;
            while (dp[i][j] == inf)
                j--;
            while (j >= i)
            {
                temp = dp[i][j] + cost[j + 1];
                if (min > temp)
                {
                    cost[i] = temp;
                    pos[i] = j + 1;
                    min = temp;
                }
                j--;
            }
            i--;
        }
        for (int i = 0; i < n; i++)
            cout << dp[5][i] << " ";
        for (j = n - 1; j >= 0; j--)
        {
            if (pos[j] == n)
                break;
            temp = cost[j];
        }
        return cost[0] - temp;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
    }
    return 0;
} // } Driver Code Ends