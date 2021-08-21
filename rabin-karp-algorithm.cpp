#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define d 256
void search(string &pat, string &txt, int q)
{
    int m = pat.length(), n = txt.length(), i, j, p = 0, t = 0, h = 1;
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;
    for (i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            j = 0;
            while (j < m)
            {
                if (txt[i + j] != pat[j++])
                    break;
            }
            if (j == m)
                cout << "pattern found at index : " << i << endl;
        }
        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[m + i]) % q;
            if (t < 0)
                t = t + q;
            // cout << t << " ";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";

    // A prime number
    int q = 5381;

    // Function Call
    search(pat, txt, q);
    return 0;
    return 0;
}