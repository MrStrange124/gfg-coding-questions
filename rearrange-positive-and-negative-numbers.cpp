#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

void rearrange(int *arr, int n)
{
  int p = -1, i = 0;
  for (i = 0; i < n; i++)
  {
    if (arr[i] < 0)
    {
      p++;
      swap(arr[i], arr[p]);
    }
  }
  i = 0;
  p++;
  while (arr[i] < 0 && p < n && i < p)
  {
    swap(arr[i], arr[p]);
    i += 2;
    p++;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = {-1, 2, -3, 4, -5, 6, -7, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  rearrange(arr, n);
  for (auto i : arr)
    cout << i << " ";
  return 0;
}