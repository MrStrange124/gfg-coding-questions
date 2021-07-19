#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int maxProfit(int *arr, int n)
{
  int i, temp_max = 0, tmin = INT_MAX, flag = 1;
  int max_so_far = 0;
  for (i = n - 1; i >= 0; i--)
  {
    temp_max = max(arr[i], temp_max);
    if (arr[i] < temp_max)
    {
      max_so_far = max(max_so_far, temp_max - arr[i]);
    }
  }
  return max_so_far;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int prices[] = {4, 3, 6, 1, 5};
  int n = sizeof(prices) / sizeof(prices[0]);
  cout << maxProfit(prices, n);

  return 0;
}