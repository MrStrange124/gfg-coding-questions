// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int countRev(string s);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << countRev(s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends

int countRev(string s)
{
    if (s.length() & 1)
        return -1;
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '}' && temp.back() == '{')
            temp.pop_back();
        else
            temp.push_back(s[i]);
    }
    int count = 0, i = 0, j = 0;
    while (temp[i] == '}')
        i++;
    j = temp.length() - i;
    if (i % 2 == 0)
        count = temp.length() / 2;
    else
        count += i / 2 + j / 2 + 2;
    return count;
}