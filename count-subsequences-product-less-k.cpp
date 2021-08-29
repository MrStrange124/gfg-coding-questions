#include <bits/stdc++.h>
using namespace std;

// Function to count numbers of such subsequences
// having product less than k.
int productSubSeqCount(vector<int> &arr, int n, int k, int product)
{
    if (n == 0)
    {
        if (product * arr[n] > k)
            return 0;
        else
            return 1;
    }
    if (product * arr[n] > k)
        return productSubSeqCount(arr, n - 1, k, product);
    return 1 + productSubSeqCount(arr, n - 1, k, product) + productSubSeqCount(arr, n - 1, k, product * arr[n]);
}
int psc(vector<int> &arr, int k)
{
    int n = arr.size();
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[j][i] = dp[j - 1][i];
            if (arr[j - 1] <= i)
            {
                dp[j][i] += dp[j - 1][i / arr[j - 1]] + 1;
            }
        }
    }
    return dp[n][k];
}

// Driver code
int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    int k = 10;
    // cout << productSubSeqCount(A, 4, k, 1) << endl;
    cout << psc(A, k) << endl;
}