#include <bits/stdc++.h>
#define ll long long
using namespace std;
class Job
{
public:
    int start, finish, profit;
    Job() {}
    Job(int s, int f, int p)
    {
        start = s;
        finish = f;
        profit = p;
    }
};
int cmp(Job j1, Job j2)
{
    if (j1.finish < j2.finish)
        return true;
    return false;
}
int soln(Job *j, int n)
{
    sort(j, j + n, cmp);
    int mx = j[n - 1].finish;
    int i = 0, dp[mx + 1];
    memset(dp, 0, sizeof(dp));
    while (i < n)
    {
        if (dp[j[i].start] + j[i].profit > dp[j[i].finish])
        {
            int k = j[i].finish;
            while (k <= mx)
                dp[k++] = dp[j[i].start] + j[i].profit;
        }
        i++;
    }
    return dp[mx];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Job j[4];
    j[1] = {1, 2, 50}, j[0] = {3, 5, 20}, j[2] = {6, 19, 100}, j[3] = {2, 100, 200};
    cout << soln(j, 4);
    return 0;
}