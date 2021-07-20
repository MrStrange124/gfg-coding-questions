#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool areRotations(string str1, string str2)
{
  if (str1.length() != str2.length())
    return false;
  string temp = str1 + str1;
  return (temp.find(str2) != string::npos);
}
bool areRotations2(string str1, string str2)
{
  if (str1.length() != str2.length())
    return false;
  queue<char> s1, s2;
  int i = str1.length();
  int j = 0;
  while (j < i)
    s1.push(str1[j++]);
  j = 0;
  while (j < i)
    s2.push(str2[j++]);
  i++;
  while (i--)
  {
    char ch = s1.front();
    s1.pop();
    s1.push(ch);
    if (s1 == s2)
      return true;
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str1 = "ABCD";
  string str2 = "CDAB";
  cout << areRotations(str1, str2);
  return 0;
}