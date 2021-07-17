#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
void next_permutation(int *arr, int n)
{
  int i, t = 0, j = n - 1;
  for (i = n - 1; i >= 1; i--)
  {
    if (arr[i] > arr[i - 1])
      break;
  }
  t = i - 1;
  while (j > t && t != -1)
  {
    if (arr[j] > arr[t])
    {
      swap(arr[j], arr[t]);
      break;
    }
    j--;
  }
  sort(arr + i, arr + n);
  // if (t == 0)
  //   sort(arr, arr + n);
  // else
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int arr[n], i;
  for (i = 0; i < n; i++)
    cin >> arr[i];
  next_permutation(arr, n);
  for (i = 0; i < n; i++)
    cout << arr[i] << " ";
  return 0;
}