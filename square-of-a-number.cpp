#include <bits/stdc++.h>
#define ll long long
using namespace std;
int square(int n)
{
    int p = 0, ans = 0, temp = n;
    while (temp)
    {
        if (temp & 1)
            ans += n << p;
        temp >>= 1;
        p++;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << square(14);
    return 0;
}