// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        pair<int, int> arr[n];
        for (int i = 0; i < n; i++)
            arr[i] = {nums[i], i};
        sort(arr, arr + n);
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] || arr[i].second == i)
                continue;
            int circle_size = 0;
            int j = i;
            while (!visited[j])
            {
                visited[j] = true;
                j = arr[j].second;
                circle_size++;
            }
            if (circle_size)
                ans += circle_size - 1;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends