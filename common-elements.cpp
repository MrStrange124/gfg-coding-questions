#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
  vector<int> ans;
  int i = 0, j = 0, k = 0;
  int temp = 0;
  int prev = A[0] + 1;
  while (i < n1 && j < n2 && k < n3)
  {
    temp = max(A[i], B[j]);
    temp = max(temp, C[k]);
    while (A[i] < temp && i < n1)
      i++;
    while (B[j] < temp && j < n2)
      j++;
    while (C[k] < temp && k < n3)
      k++;
    if (A[i] == B[j] && B[j] == C[k])
    {
      if (A[i] != prev)
      {
        ans.push_back(A[i]);
        prev = A[i];
      }
      i++;
      j++;
      k++;
    }
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n1 = 7, A[] = {1, 10, 20, 40, 80, 120, 120};
  int n2 = 6, B[] = {6, 20, 80, 120, 120};
  int n3 = 9, C[] = {3, 15, 20, 30, 70, 80, 100, 120, 120};
  vector<int> v1 = commonElements(A, B, C, n1, n2, n3);
  for (auto i : v1)
    cout << i << " ";
  return 0;
}