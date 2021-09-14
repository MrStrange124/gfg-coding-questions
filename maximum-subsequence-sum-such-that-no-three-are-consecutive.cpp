#include <bits/stdc++.h>
#define ll long long
#define inf INT_MAX
using namespace std;
int soln(int arr[], int n)
{
    int sum[n];
    if (n >= 1)
        sum[0] = arr[0];
    if (n >= 2)
        sum[1] = arr[0] + arr[1];
    if (n >= 3)
        sum[2] = max(arr[2] + arr[0], max(arr[1] + arr[2], sum[1]));
    for (int i = 3; i < n; i++)
        sum[i] = max(sum[i - 1], max(sum[i - 3] + arr[i] + arr[i - 1], sum[i - 2] + arr[i]));

    return sum[n - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {100, 1000, 100, 1000, 1};
    cout << soln(arr, 5);
    return 0;
}