#include <bits/stdc++.h>
#define ll long long
using namespace std;
int getMedian(int ar1[], int ar2[], int n1, int n2)
{
    int i = 0, j = n1, k = 0, l = n2;
    while (j - i != 1)
    {
        int m1 = (i + j) / 2, m2 = (k + l) / 2;
        if (ar1[m1] == ar2[m2])
            return ar1[m1];
        else if (ar1[m1] < ar2[m2])
        {
            i = m1;
            l = m2;
        }
        else if (ar1[m1] > ar2[m2])
        {
            j = m1;
            k = m2;
        }
    }
    return (max(ar1[i], ar2[k]) + min(ar1[j], ar2[l])) / 2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ar1[] = {1, 3, 5, 7, 9};
    int ar2[] = {2, 4, 6, 8, 10};

    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    cout << getMedian(ar1, ar2, n1, n2);
    return 0;
}