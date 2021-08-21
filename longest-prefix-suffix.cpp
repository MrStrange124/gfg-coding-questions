// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++

class Solution
{
public:
    int lps(string s)
    {
        int n = s.length(), j = 0;
        int lp[n];
        memset(lp, 0, sizeof(lp));
        for (int i = 1; i < n; i++)
        {
            if (s[j] == s[i])
            {
                lp[i] = j + 1;
                j++;
            }
            else
            {
                while (j != 0)
                {
                    j = lp[j - 1];
                    if (s[j] == s[i])
                    {
                        lp[i] = ++j;
                        break;
                    }
                }
            }
        }
        return lp[n - 1];
    }
};

// { Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}
// } Driver Code Ends