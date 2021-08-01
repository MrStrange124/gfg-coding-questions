// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
  vector<int> factorial(int N)
  {
    vector<int> res;
    res.push_back(1);
    int carry = 0, i = 0, temp = 0;
    while (i++ < N)
    {
      for (auto it = res.begin(); it != res.end(); it++)
      {
        *it = (*it) * i + carry;
        carry = 0;
        if (*it > 9)
        {
          carry += *it / 10;
          *it %= 10;
        }
      }
      if (carry)
      {
        temp = carry % 10;
        res.push_back(temp);
        carry /= 10;
      }
    }
    reverse(res.begin(), res.end());
    return res;
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
    Solution ob;
    vector<int> result = ob.factorial(N);
    for (int i = 0; i < result.size(); ++i)
    {
      cout << result[i];
    }
    cout << endl;
  }
  return 0;
}