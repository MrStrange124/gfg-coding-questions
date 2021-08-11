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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {10, 22, 5, 75, 65, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxProfit(arr, n);
    return 0;
}