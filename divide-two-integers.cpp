#include <bits/stdc++.h>
#define ll long long
using namespace std;
int divide(ll divident, ll divisor)
{
    ll quotient = 0, temp = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (temp + (divisor << i) <= divident)
        {
            temp += divisor << i;
            quotient |= 1LL << i;
        }
    }
    return quotient;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << divide(10, 2);
    return 0;
}