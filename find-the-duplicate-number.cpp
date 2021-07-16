#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int findDuplicate(int *nums, int n)
{
  int i;
  int *arr = new int[n + 1];
  for (i = 1; i < n + 1; i++)
  {
    arr[i] = 0;
  }
  for (i = 1; i <= n; i++)
  {
    if (arr[nums[i]] == 1)
      return nums[i];
    arr[nums[i]] = 1;
  }

  return -1;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = {0, 3, 1, 3, 4, 2};
  int n = 5;
  cout << findDuplicate(arr, n);
  return 0;
}