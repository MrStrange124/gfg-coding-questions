// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        int l = 0;
        string temp = "";
        if (x.length() & 1)
            return false;
        for (int i = 0; i < x.length(); i++)
        {
            if (x[i] == '{' || x[i] == '[' || x[i] == '(')
            {
                temp.push_back(x[i]);
                l++;
            }
            else if (x[i] == '}' || x[i] == ']' || x[i] == ')')
            {
                if (i - 1 < 0)
                    return false;
                else if (x[i] == '}' && temp[--l] == '{')
                    temp.pop_back();
                else if (x[i] == ']' && temp[--l] == '[')
                    temp.pop_back();
                else if (x[i] == ')' && temp[--l] == '(')
                    temp.pop_back();
                else
                    return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
} // } Driver Code Ends