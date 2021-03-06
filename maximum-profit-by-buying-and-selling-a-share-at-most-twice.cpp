#include <bits/stdc++.h>
#define ll long long
using namespace std;
int soln(int arr[], int i, int j)
{
    if (j - i == 0)
        return 0;
    int mx = 0, profit = 0;
    for (int k = j; k >= i; k--)
    {
        mx = max(arr[k], mx);
        profit = max(profit, mx - arr[k]);
    }
    return profit;
}
int maxProfit(int arr[], int n)
{
    int i = 0, j = n - 1, k = 1;
    int mx = 0;
    for (; k < n; k++)
    {
        mx = max(mx, soln(arr, 0, k) + soln(arr, k + 1, n - 1));
    }
    return mx;
}
int maxProfit2(int arr[], int n)
{
    int profit[n], mx = arr[n - 1];
    memset(profit, 0, sizeof(profit));
    for (int i = n - 2; i >= 0; i--)
    {
        mx = max(mx, arr[i]);
        profit[i] = max(profit[i + 1], mx - arr[i]);
    }
    int mn = arr[0];
    for (int i = 1; i < n; i++)
    {
        mn = min(mn, arr[i]);
        profit[i] = max(profit[i - 1], profit[i] + arr[i] - mn);
    }
    return profit[n - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {10, 22, 5, 75, 65, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxProfit2(arr, n);
    return 0;
}