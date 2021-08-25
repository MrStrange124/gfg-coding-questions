#include <bits/stdc++.h>
#define ll long long
using namespace std;
int bs(int arr[], int high, int t)
{
    int low = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (t == arr[mid])
            return mid;
        else if (t < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, i, sum = 0, j;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        int *a = new int[n];
        int *c = new int[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i == 0)
                c[i] = a[i];
            else
                c[i] = c[i - 1] + a[i];
        }
        cin >> m;
        int *b = new int[m], t;
        int *d = new int[m];
        vector<int> v[2];
        for (i = 0; i < m; i++)
        {
            cin >> b[i];
            if (i == 0)
                d[i] = b[i];
            else
                d[i] = d[i - 1] + b[i];
        }
        for (i = 0; i < m; i++)
        {
            t = bs(a, n - 1, b[i]);
            if (t != -1)
            {
                v[0].push_back(i);
                v[1].push_back(t);
            }
        }
        // for (auto i : v[1])
        //     cout << a[i] << " ";
        // cout << endl;
        for (j = 0; j < v[0].size(); j++)
        {
            // cout << c[v[1][j]] << " " << d[v[0][j]] << endl;
            if (j == 0)
                sum = max(c[v[1][j]], d[v[0][j]]);
            else
                sum += max(c[v[1][j]] - c[v[1][j - 1]], d[v[0][j]] - d[v[0][j - 1]]);
        }
        sum += max(c[n - 1] - c[v[1][j - 1]], d[m - 1] - d[v[0][j - 1]]);
        cout << sum << endl;
        delete[] a;
        delete[] b;
        delete[] c;
        delete[] d;
    }
    return 0;
}