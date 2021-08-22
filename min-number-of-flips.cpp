// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int minFlips(string s);
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << minFlips(s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int minFlips(string S)
{
    int i, count1 = 0, count2 = 0, n = S.length();
    string temp1 = "", temp2 = "";
    for (i = 0; i < n; i++)
    {
        temp1 += i & 1 ? '0' : '1';
        temp2 += i & 1 ? '1' : '0';
        if (S[i] != temp1[i])
            count1++;
        if (S[i] != temp2[i])
            count2++;
    }
    return min(count1, count2);
}