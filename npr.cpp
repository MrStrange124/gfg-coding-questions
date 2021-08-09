#include <bits/stdc++.h>
#define ll long long
using namespace std;
int npk(int n, int k)
{
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            dp[j][i] = dp[j - 1][i] + i * dp[j - 1][i - 1];
    return dp[n][k];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << npk(10, 2);
    return 0;
}