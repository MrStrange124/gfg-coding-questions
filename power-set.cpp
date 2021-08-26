// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void soln(vector<string> &a, string s, int n, string temp)
    {
        if (n == s.length())
        {
            if (temp.length())
                a.push_back(temp);
            return;
        }
        soln(a, s, n + 1, temp + s[n]);
        soln(a, s, n + 1, temp);
    }
    vector<string> AllPossibleStrings(string s)
    {
        // soln(ans, s, 0, "");
        // return ans;
        vector<string> ans;
        int t = s.length();
        int bit = 1 << t;
        for (int count = 1; count < bit; count++)
        {
            string t = "";
            for (int i = 0; i < bit; i++)
            {
                if (count & (1 << i))
                    t += s[i];
            }
            ans.push_back(t);
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
        string s;
        cin >> s;
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s);
        for (auto i : res)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends