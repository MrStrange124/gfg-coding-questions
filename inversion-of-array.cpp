#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll merge(ll *arr, ll *temp, ll left, ll mid, ll right)
{
  ll i = left, j = mid, k = left, inv_count = 0;
  while (i <= mid - 1 && j <= right)
  {
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else
    {
      temp[k++] = arr[j++];

      inv_count += mid - i;
    }
  }

  while (i <= mid - 1)
    temp[k++] = arr[i++];

  while (j <= right)
    temp[k++] = arr[j++];

  for (i = left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}

ll mergesort(ll *arr, ll *temp, ll left, ll right)
{
  ll mid, inv_count = 0;
  if (right > left)
  {
    mid = (right + left) / 2;
    inv_count += mergesort(arr, temp, left, mid);
    inv_count += mergesort(arr, temp, mid + 1, right);
    inv_count += merge(arr, temp, left, mid + 1, right);
  }
  return inv_count;
}

ll inversionCount(ll *arr, ll n)
{
  ll temp[n];
  return mergesort(arr, temp, 0, n - 1);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll arr[] = {10, 9, 8}, n = 3;
  cout << inversionCount(arr, n);
  return 0;
}