#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
void merge(int *arr1, int n, int *arr2, int m)
{
	int i, j, last;
	for (i = m - 1; i >= 0; i--)
	{
		last = arr1[n - 1];
		for (j = n - 2; j >= 0 && arr1[j] > arr2[i]; j--)
		{
			arr1[j + 1] = arr1[j];
		}
		if (j != n - 2 || last > arr2[i])
		{
			arr1[j + 1] = arr2[i];
			arr2[i] = last;
		}
	}
}
void merge1(int *arr1, int n, int *arr2, int m)
{
	int i = 0, j = 0, k = n - 1;
	while (i <= k && j < m)
	{
		if (arr1[i] < arr2[j])
			i++;
		else
			swap(arr2[j++], arr1[k--]);
	}
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + m);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 4, M = 5;
	int arr1[] = {1, 3, 5, 7};
	int arr2[] = {0, 2, 6, 8, 9};
	merge1(arr1, N, arr2, M);
	for (int i = 0; i < N; i++)
		cout << arr1[i] << " ";
	for (int i = 0; i < M; i++)
		cout << arr2[i] << " ";
	return 0;
}