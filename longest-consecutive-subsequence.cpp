#include <bits/stdc++.h>
#define ll long long
using namespace std;
int findLongestConseqSubseq(int *arr, int n)
{
  unordered_set<int> S;
  int ans = 0, j;
  for (int i = 0; i < n; i++)
    S.insert(arr[i]);
  for (int i = 0; i < n; i++)
  {
    if (S.find(arr[i] - 1) == S.end())
    {
      j = arr[i];
      while (S.find(j) != S.end())
        j++;
      ans = max(ans, j - arr[i]);
    }
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = {1, 2, 2, 3};
  int n = sizeof arr / sizeof arr[0];
  cout << "Length of the Longest contiguous subsequence "
          "is "
       << findLongestConseqSubseq(arr, n);
  return 0;
}