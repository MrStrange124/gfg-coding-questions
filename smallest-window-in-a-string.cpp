// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow1(string s, string p)
    {
        int m[257] = {0}, count = 0, start = 0, ans = INT_MAX;
        for (int i = 0; i < p.length(); i++)
        {
            if (m[p[i]] == 0)
                count++;
            m[p[i]]++;
        }
        int i = 0, j = 0, k = s.length();
        while (j < k)
        {
            m[s[j]]--;
            if (m[s[j]] == 0)
                count--;
            if (!count)
            {
                while (!count)
                {
                    if (ans > j - i + 1)
                    {
                        ans = j - i + 1;
                        start = i;
                    }
                    m[s[i]]++;
                    if (m[s[i]] > 0)
                        count++;
                    i++;
                }
            }
            j++;
        }
        if (ans == INT_MAX)
            return "-1";
        return s.substr(start, ans);
    }
    string smallestWindow(string s, string p)
    {
        map<char, int> m;
        int i = 0, j = 0, k, count = 0;
        string ans = s + p;
        for (; j < p.length(); j++)
            m[p[j]]++;
        k = m.size();
        j = 0;
        while (j < s.length())
        {
            if (m.find(s[j]) != m.end())
            {
                m[s[j]]--;
                if (m[s[j]] == 0)
                    count++;
            }
            if (count == k)
            {
                while (i < j)
                {
                    if (m.find(s[i]) != m.end())
                    {
                        if (m[s[i]] < 0)
                            m[s[i]]++;
                        else
                            break;
                    }
                    i++;
                }
                if (j - i + 1 < ans.length())
                    ans = s.substr(i, j - i + 1);
                m[s[i]]++;
                i++;
                count--;
            }
            j++;
        }
        if (ans.length() > s.length())
            return "-1";
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow1(s, pat) << endl;
    }
    return 0;
} // } Driver Code Ends