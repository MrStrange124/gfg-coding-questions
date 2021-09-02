// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    bool match(string w, string p)
    {
        int m = w.length(), n = p.length(), i = 0, j = 0, index_w = -1, index_p = -1;
        while (i < n)
        {
            if (j < m && (w[j] == p[i] || w[j] == '?'))
            {
                i++;
                j++;
            }
            else if (j < m && w[j] == '*')
            {
                index_w = j;
                index_p = i;
                j++;
            }
            else if (index_p != -1)
            {
                j = index_w + 1;
                i = index_p + 1;
                index_p++;
            }
            else
                return 0;
        }
        while (j < m)
            if (w[j++] != '*')
                return 0;
        return 1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string wild, pattern;
        cin >> wild >> pattern;

        Solution ob;
        if (ob.match(wild, pattern))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
} // } Driver Code Ends