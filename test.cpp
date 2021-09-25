#include <bits/stdc++.h>
#define ll long long
using namespace std;
int partition(int l, int h, int *arr)
{
  int pivot = arr[l];
  int i = l, j = h;
  while (i < j)
  {
    do
    {
      i++;
    } while (arr[i] < pivot);

    do
    {
      j--;
    } while (arr[j] >= pivot && j > l);
    if (i < j)
      swap(arr[i], arr[j]);
  }
  swap(arr[l], arr[j]);
  return j;
}
void quicksort(int i, int j, int *arr)
{
  if (i < j)
  {
    int k = partition(i, j, arr);
    quicksort(i, k, arr);
    quicksort(k + 1, j, arr);
  }
}
int main()
{
  int arr[] = {1, 15, 9, 30, 2, 45};
  quicksort(0, 5, arr);
  for (int i = 0; i < 6; i++)
    cout << arr[i] << " ";
}