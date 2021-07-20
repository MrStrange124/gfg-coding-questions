#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unordered_map<char, int> count;
  char c[] = "hellooh";
  int i = 0;
  while (c[i] != '\0')
  {
    count[c[i++]]++;
  }
  for (auto j : count)
  {
    if (j.second > 1)
      cout << j.first;
  }
  return 0;
}