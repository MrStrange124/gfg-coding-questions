// C++ program to find minimum number of
// operations required to transform one string to other
#include <bits/stdc++.h>
using namespace std;

// Function to find minimum number of operations required to transform
// A to B.
int minOps(string &A, string &B)
{
    int n = A.length();
    if (n != B.length())
        return -1;
    int ch[256] = {0};
    for (int i = 0; i < n; i++)
        ch[A[i]]++;

    for (int i = 0; i < n; i++)
    {
        ch[A[i]]--;
        if (ch[A[i] < 0])
            return -1;
    }
    int i, j, ans = 0;
    i = j = n - 1;
    while (i >= 0)
    {
        while (i >= 0 && A[i] != B[j])
        {
            i--;
            ans++;
        }
        if (i >= 0)
        {
            i--;
            j--;
        }
    }
    return ans;
}

// Driver program
int main()
{
    string A = "EACBD";
    string B = "EABCD";
    cout << "Minimum number of operations "
            "required is "
         << minOps(A, B);
    return 0;
}
