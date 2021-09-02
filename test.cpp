#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  int n = 2 * 1e6;
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++)
  {
    if (is_prime[i] && (long long)i * i <= n)
    {
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
  }

  long long ans = 0;
  for (int i = 2; i < n; i++)
    if (is_prime[i])
      ans += i;
  cout << ans;
  return 0;
}