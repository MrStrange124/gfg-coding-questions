// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n)
    {
        ll count = 0, sum = 0;
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == 0)
                count++;
            if (map.find(sum) != map.end())
            {
                for (auto it = map[sum].begin(); it != map[sum].end(); it++)
                    count++;
            }
            map[sum].push_back(i);
        }
        return count;
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
        cin >> n; //input size of array

        vector<ll> arr(n, 0);

        for (int i = 0; i < n; i++)
            cin >> arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr, n) << "\n";
    }
    return 0;
} // } Driver Code Ends