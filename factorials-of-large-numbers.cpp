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
    int carry = 0, i = 2, temp = 0;
    while (i <= N)
    {
      for (int it = 0; it < res.size(); it++)
      {
        temp = res[it] * i + carry;
        if (temp < 10)
        {
          res[it] = temp;
          carry = 0;
        }
        else
        {
          res[it] = temp % 10;
          carry = temp / 10;
        }
      }
      while (carry)
      {
        res.push_back(carry % 10);
        carry /= 10;
      }
      i++;
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