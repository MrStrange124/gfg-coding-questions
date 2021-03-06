// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string secFrequent(string arr[], int n)
    {
        unordered_map<string, int> map;
        for (int i = 0; i < n; i++)
            map[arr[i]]++;
        int mx = 0, s = 0;
        for (auto i : map)
        {
            mx = max(i.second, mx);
        }

        for (auto i : map)
            if (i.second > s && i.second != mx)
                s = i.second;
        for (auto i : map)
            if (i.second == s)
                return i.first;
        return "";
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent(arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends