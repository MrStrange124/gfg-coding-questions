#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int minJumps(int *arr, int n)
{
	int step = 0, p = n - 1, temp;
	while (p != 0)
	{
		temp = -1;
		for (int i = p - 1; i >= 0; i--)
		{
			if ((p - i) <= arr[i])
				temp = i;
		}
		if (temp == -1)
		{
			step = -1;
			break;
		}
		p = temp;
		step++;
	}
	return step;
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
	cout << minJumps(arr, n);
	return 0;
}