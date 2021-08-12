// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m);
string isSubset2(int a1[], int a2[], int n, int m)
{
    if (m > n)
        return "No";
    unordered_set<int> s;
    int i;
    for (i = 0; i < m; i++)
        s.insert(a2[i]);
    for (i = 0; i < n; i++)
        s.insert(a1[i]);
    if (s.size() == n)
        return "Yes";
    return "No";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends

string isSubset(int a1[], int a2[], int n, int m)
{
    if (m > n)
        return "No";
    unordered_map<int, int> m1;
    for (int i = 0; i < m; i++)
        m1[a2[i]]++;
    int count = m;
    for (int i = 0; i < n; i++)
    {
        if (m1.find(a1[i]) != m1.end())
            count--;
        if (!count)
            return "Yes";
    }
    return "No";
}