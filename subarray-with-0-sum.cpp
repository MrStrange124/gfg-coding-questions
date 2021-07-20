#include <iostream>
#include <algorithm>
#include <unordered_set>
#define ll long long
using namespace std;
bool subArrayExists(int *arr, int n)
{
  int tmin = 0;
  int temp;
  int i;
  for (i = 0; i < n; i++)
  {
    if (arr[i] < 0)
      tmin -= arr[i];
    else if (!arr[i])
      return true;
  }
  for (int j = 0; j < n - 1; j++)
  {
    temp = 0;
    for (i = j; i < n; i++)
    {
      temp += arr[i];
      if (temp > tmin)
        break;
      if (temp == 0)
        return true;
    }
  }
  return false;
}
bool subArrayExists2(int *arr, int n)
{
  unordered_set<int> sumset;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
    if (sum == 0 || sumset.find(sum) != sumset.end())
      return true;

    sumset.insert(sum);
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = {4, 2, -3, 1, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << subArrayExists2(arr, n);
  return 0;
}