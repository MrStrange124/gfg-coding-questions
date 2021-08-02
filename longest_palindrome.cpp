#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  bool isPalin(string S)
  {
    int i = 0, j = S.length() - 1;
    while (i < j)
    {
      if (S[i++] != S[j--])
        return false;
    }
    return true;
  }
  string longestPalin(string S)
  {
    int i, j;
    string temp, Str;
    Str = S.substr(0, 1);
    for (i = 2; i <= S.length(); i++)
    {
      for (j = 0; i + j <= S.length(); j++)
      {
        temp = S.substr(j, i);
        if (isPalin(temp))
        {
          Str = temp;
          break;
        }
      }
    }
    return Str;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string S;
    cin >> S;

    Solution ob;
    cout << ob.longestPalin(S) << endl;
  }
}