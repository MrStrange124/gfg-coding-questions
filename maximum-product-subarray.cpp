#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
  // Function to find maximum product subarray
  long long maxProduct(int *arr, int n)
  {
    long long max_so_far = 0, max_till_now = 1, min_till_now = 1;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] > 0)
      {
        max_till_now *= arr[i];
        min_till_now = min(min_till_now * arr[i], (long long)1);
      }
      else if (arr[i] == 0)
      {
        min_till_now = 1;
        max_till_now = 1;
      }
      else
      {
        int temp = max_till_now;
        max_till_now = max(min_till_now * arr[i], (long long)1);
        min_till_now = temp * arr[i];
      }
      if (max_till_now > max_so_far)
        max_so_far = max_till_now;
    }
    return max_so_far;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.maxProduct(arr, n);
    cout << ans << "\n";
  }
  return 0;
} // } Driver Code Ends