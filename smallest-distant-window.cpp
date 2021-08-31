// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string findSubString(string str)
    {
        map<char, int> m;
        for (int i = 0; i < str.length(); i++)
            m[str[i]]++;

        int i = 0, j = str.length() - 1;
        for (; i < j; i++)
        {
            if (m[str[i]] == 1)
                break;
            m[str[i]]--;
        }
        for (; j > i; j--)
        {
            if (m[str[j]] == 1)
                break;
            m[str[j]]--;
        }
        string temp = str.substr(i, j - i + 1);
        for (auto t : m)
            m[t.first] = 0;

        for (int i = 0; i < str.length(); i++)
            m[str[i]]++;

        i = 0, j = str.length() - 1;
        for (; j > i; j--)
        {
            if (m[str[j]] == 1)
                break;
            m[str[j]]--;
        }
        for (; i < j; i++)
        {
            if (m[str[i]] == 1)
                break;
            m[str[i]]--;
        }
        if (temp.length() <= j - i + 1)
            return temp;
        return str.substr(i, j - i + 1);
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