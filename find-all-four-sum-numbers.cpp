// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for (auto i : arr)
            cout << i << " ";
        cout << endl;
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                int l = j + 1, m = n - 1;
                while (l < m)
                {
                    if (arr[i] + arr[j] + arr[l] + arr[m] == k)
                    {
                        vector<int> v;
                        v.push_back(arr[i]);
                        v.push_back(arr[j]);
                        v.push_back(arr[l]);
                        v.push_back(arr[m]);
                        ans.push_back(v);
                        l++;
                        m--;
                    }
                    else if (arr[i] + arr[j] + arr[l] + arr[m] < k)
                        l++;
                    else
                        m--;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends