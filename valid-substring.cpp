// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++
class Solution
{
public:
    int findMaxLen(string s)
    {
        if (s.size() < 2)
            return 0;
        vector<int> longest(s.size(), 0);
        int curMax = 0;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == ')' && i - longest[i - 1] - 1 >= 0 && s[i - longest[i - 1] - 1] == '(')
            {
                longest[i] = longest[i - 1] + 2 + ((i - longest[i - 1] - 2 >= 0) ? longest[i - longest[i - 1] - 2] : 0);
                curMax = max(longest[i], curMax);
            }
        }
        return curMax;
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
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
// } Driver Code Ends