// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    int romanToDecimal(string &str)
    { //ix
        int n = str.length(), i = 0, num = 0;
        unordered_map<char, int> rom;
        rom['I'] = 1;
        rom['V'] = 5;
        rom['X'] = 10;
        rom['L'] = 50;
        rom['C'] = 100;
        rom['D'] = 500;
        rom['M'] = 1000;
        while (i < n)
        {
            if (i + 1 < n && rom[str[i]] < rom[str[i + 1]])
                num -= rom[str[i++]];
            else
                num += rom[str[i++]];
        }
        return num;
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
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
} // } Driver Code Ends