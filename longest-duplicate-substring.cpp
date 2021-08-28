#include <bits/stdc++.h>
using namespace std;
#define d 26
bool rabin_karp(string &s1, string s2)
{
    int m = s2.length(), n = s1.length(), i, j;
    int p = 0, t = 0, h = 1;
    int q = 101;
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;
    for (i = 0; i < m; i++)
    {
        p = (p * d + s2[i]) % q;
        t = (t * d + s1[i]) % q;
    }
    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (s1[i + j] != s2[j])
                    break;
            }
            if (j == m)
                return true;
        }
        if (i < n - m)
        {
            t = (d * (t - s1[i] * h) + s1[i + m]) % q;
            if (t < 0)
                t = t + q;
        }
    }
    return false;
}
string longestDupSubstring(string s1)
{
    cout << rabin_karp(s1, "ana");
    return "hello";
}

int main()
{
    string s;
    cin >> s;

    cout << longestDupSubstring(s);
}