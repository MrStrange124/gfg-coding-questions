#include <bits/stdc++.h>
using namespace std;
// long long t[1001][1001];
// } Driver Code Ends
int t[100][100];
int count(int S[], int m, int n)
{
    if (m <= 0)
        return 0;
    if (n == 0)
        return 1;
    if (S[m - 1] > n)
        return count(S, m - 1, n);
    else
        return count(S, m, n - S[m - 1]) + count(S, m - 1, n);
}

int count2(int S[], int m, int n)
{
    if (m <= 0)
        return 0;

    if (n == 0)
        return 1;

    if (t[m][n] != -1)
        return t[m][n];

    if (S[m - 1] > n)
        return t[m][n] = count2(S, m - 1, n);
    else
        return t[m][n] = count2(S, m, n - S[m - 1]) + count2(S, m - 1, n);
}
int count3(int S[], int m, int n)
{
    int i, dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (i = 0; i <= m; i++)
        dp[0][i] = 1;
    for (i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (S[j - 1] > i)
                dp[i][j] = dp[i][j - 1];
            else
                dp[i][j] = dp[i][j - 1] + dp[i - S[j - 1]][j];
        }

    return dp[n][m];
}
int count4(int S[], int m, int n)
{
    int i, dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (S[i - 1] <= j)
                dp[j] += dp[j - S[i - 1]];
        }

    return dp[n];
}
// { Driver Code Starts.
int main()
{
    memset(t, -1, sizeof(t));
    int n, m;
    cin >> n >> m;
    int arr[m];
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    cout << count4(arr, m, n) << endl;
    return 0;
}