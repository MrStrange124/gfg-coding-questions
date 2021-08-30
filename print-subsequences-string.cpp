#include <bits/stdc++.h>
#define ll long long
using namespace std;
void soln(string s, int n, string o)
{
    if (n < 0)
    {
        if (o.length())
        {
            reverse(o.begin(), o.end());
            cout << o << endl;
        }
        return;
    }
    soln(s, n - 1, o + s[n]);
    soln(s, n - 1, o);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string output = "";
    string input = "abcd";
    soln(input, input.length() - 1, output);
    return 0;
}