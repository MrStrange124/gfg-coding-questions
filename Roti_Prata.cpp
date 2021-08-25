#include <bits/stdc++.h>
#define ll long long
using namespace std;
int roti(int t, int rank)
{
    if (rank == t)
        return 1;
    int temp = t * 2 / rank;
    int n = floor(sqrt(temp));
    if (n * (n + 1) > temp)
        return n - 1;
    return n;
}
int soln(int arr[], int n, int c)
{
    int low = 1, high = 4 * (n + 1) * n / c, temp, ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        temp = 0;
        for (int i = 0; i < c; i++)
        {
            temp += roti(mid, arr[i]);
            if (temp >= n)
            {
                high = mid - 1;
                ans = mid;
                break;
            }
        }
        if (temp < n)
            low = mid + 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, c;
    int arr[51];
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        for (int i = 0; i < c; i++)
            cin >> arr[i];
        cout << soln(arr, n, c) << endl;
    }
    return 0;
}