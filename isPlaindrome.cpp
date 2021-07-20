#include <iostream>
#include <algorithm>
#include <string.h>
#define ll long long
using namespace std;
int isPlaindrome(char *s)
{
  int e = 0, i = 0;
  e = strlen(s) - 1;
  while (i < e)
  {
    if (s[i++] != s[e--])
      return 0;
  }
  return 1;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char c[] = {'a', 'b', 'c', 'c', 'b', 'a'};
  cout << isPlaindrome(c);

  return 0;
}