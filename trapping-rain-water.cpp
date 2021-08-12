// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    int trappingWater(int arr[], int n)
    {
        int res = 0;
        int left[n];
        int right[n];

        left[0] = arr[0];
        for (int j = 1; j < n; j++)
            left[j] = max(left[j - 1], arr[j]);
        right[n - 1] = arr[n - 1];
        for (int j = n - 2; j >= 0; j--)
            right[j] = max(right[j + 1], arr[j]);
        for (int i = 0; i < n; i++)
            res = res + (min(left[i], right[i]) - arr[i]);

        return res;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends