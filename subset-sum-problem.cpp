// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int t[101][101];
class Solution
{
public:
    bool solve(int arr[], int N, int sum)
    {
        if (sum == 0)
            return true;
        if (N < 0)
            return false;
        if (t[N][sum] != -1)
            return t[N][sum];
        if (arr[N - 1] > sum)
            return t[N][sum] = solve(arr, N - 1, sum);

        return t[N][sum] = solve(arr, N - 1, sum - arr[N - 1]) || solve(arr, N - 1, sum);
    }
    int equalPartition(int N, int arr[])
    {
        memset(t, -1, sizeof(t));
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum & 1)
            return 0;
        return solve(arr, N, sum / 2);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends