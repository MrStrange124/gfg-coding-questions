#include <bits/stdc++.h>
#define ll long long
using namespace std;
string countAndSay(int n)
{
  string s = "1";
  int k = 0;
  int i;
  string temp;
  while (--n)
  {
    char c = s[0];
    temp = "";
    k = 0;
    for (i = 0; i < s.length(); i++)
    {
      if (s[i] == c)
      {
        k++;
      }
      else
      {
        temp = temp + (char)(k + 48);
        temp = temp + s[i - 1];
        k = 1;
        c = s[i];
      }
    }
    temp = temp + (char)(k + 48);
    temp = temp + s[i - 1];
    s = temp;
  }
  return s;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << countAndSay(10);
  return 0;
}