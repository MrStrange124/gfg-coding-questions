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
    vector<vector<int>> fourSum(vector<int> &arr, int q)
    {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int k, l, sum;
        vector<int> temp;
        for (int i = 0; i < n - 3; i++)
        {
            temp.push_back(arr[i]);
            for (int j = i + 1; j < n - 2; j++)
            {
                temp.push_back(arr[j]);
                k = j + 1;
                l = n - 1;
                sum = arr[i] + arr[j];
                while (k < l)
                {
                    if (sum + arr[k] + arr[l] == q)
                    {
                        temp.push_back(arr[k]);
                        temp.push_back(arr[l]);
                        if (ans.empty() || ans.back() != temp)
                            ans.push_back(temp);
                        temp.pop_back();
                        temp.pop_back();
                        k++;
                    }
                    else if (sum + arr[k] + arr[l] > q)
                        l--;
                    else
                        k++;
                }
                temp.pop_back();
            }
            temp.pop_back();
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