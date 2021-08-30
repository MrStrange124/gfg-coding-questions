#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
  vector<int> ans;
  int i = 0, j = 0, k = 0;
  int temp;
  while (i < n1 && j < n2 && k < n3)
  {
    if (i > 0 && A[i] == A[i - 1])
    {
      i++;
      continue;
    }
    temp = A[i++];
    while (j < n2 && B[j] < temp)
      j++;
    while (k < n3 && C[k] < temp)
      k++;
    if (j >= n2 || k >= n3)
      break;
    else if (temp == B[j] && temp == C[k])
    {
      ans.push_back(temp);
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