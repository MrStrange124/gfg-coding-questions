// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool find(string A, vector<string> &B)
    {
        for (int i = 0; i < B.size(); i++)
        {
            if (B[i] == A)
                return true;
        }
        return false;
    }
    int wordBreak(string A, vector<string> &B)
    {
        int size = A.length();
        int n = size;
        if (size == 0)
            return 1;
        bool dp[n + 1];
        memset(dp, 0, sizeof(dp));
        vector<int> matched_index;
        matched_index.push_back(-1);
        for (int i = 0; i < n; i++)
        {
            int msize = matched_index.size(), f = 0;
            for (int j = msize - 1; j >= 0; j--)
            {
                string sb = A.substr(matched_index[j] + 1, i - matched_index[j]);
                if (find(sb, B))
                {
                    f = 1;
                    break;
                }
            }
            if (f)
            {
                dp[i] = 1;
                matched_index.push_back(i);
            }
        }
        return dp[n - 1];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";
    }
}
// } Driver Code Ends