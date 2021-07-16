#include <iostream>
#include <algorithm>
#define imax INT_MAX
#define imin INT_MIN
#define ll long long
using namespace std;

//dynaming programming
int maxSumOfSubarray(int *arr, int n)
{
  int max_so_far = arr[0], i = 1, temp_max = arr[0];
  while (i < n)
  {
    temp_max += arr[i];
    if (arr[i] > temp_max)
      temp_max = arr[i];
    if (temp_max > max_so_far)
      max_so_far = temp_max;
    i++;
  }
  return max_so_far;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = {1, 2, 3, -2, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << maxSumOfSubarray(arr, n);
  return 0;
}