#include <iostream>
#include <algorithm>
#include <unordered_map>
#define ll long long
using namespace std;
int getPairsCount(int *arr, int n, int k)
{
  unordered_map<int, int> m;
  int i = 0;
  for (; i < n; i++)
  {
    m[arr[i]]++;
  }
  int count = 0;
  for (i = 0; i < n; i++)
  {
    count += m[k - arr[i]];
    if (arr[i] == k - arr[i])
      count--;
  }
  return count / 2;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = {1, 1, 1, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  int sum = 2;
  cout << getPairsCount(arr, n, sum);
  return 0;
}