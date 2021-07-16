#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int minJumps(int *arr, int n)
{
	int i = 0, j, step = 0, tmax = 0, k, l;
	while (i < n - 1)
	{
		tmax = 0;
		for (j = i + 1, k = 1; j <= i + arr[i]; j++, k++)
		{
			if (tmax < arr[j] + k && arr[j] != 0)
			{
				tmax = arr[j] + k;
				l = k;
			}
		}
		if (tmax == 0)
			return -1;
		i += l;
		step++;
	}
	return step;
}
int minJumps1(int *arr, int n)
{
	int *jumps = new int[n];
	int i, j;
	jumps[0] = 0;
	if (arr[0] == 0)
		return -1;
	for (i = 1; i < n; i++)
	{
		jumps[i] = INT_MAX;
		for (j = 0; j < i; j++)
		{
			if (i <= j + arr[j] && jumps[j] != INT_MAX)
			{
				jumps[i] = min(jumps[i], jumps[j] + 1);
				break;
			}
		}
	}
	return jumps[n - 1];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int arr[n], i = 0;
	while (i < n)
		cin >> arr[i++];
	// cout << minJumps(arr, n);
	cout << minJumps1(arr, n);
	return 0;
}