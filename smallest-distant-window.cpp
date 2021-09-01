// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string findSubString(string str)
    {
        map<char, int> m, t;
        for (int i = 0; i < str.length(); i++)
            m[str[i]]++;
        int i = 0, j = 0, k = m.size(), count = 0;
        string ans = str;
        while (j < str.length())
        {
            if (t[str[j]] == 0)
                count++;
            t[str[j]]++;
            if (count == k)
            {
                while (i < j)
                {
                    if (t[str[i]] == 1)
                        break;
                    t[str[i++]]--;
                }
                if (j - i + 1 < ans.length())
                    ans = str.substr(i, j - i + 1);
                count--;
                t[str[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
} // } Driver Code Ends