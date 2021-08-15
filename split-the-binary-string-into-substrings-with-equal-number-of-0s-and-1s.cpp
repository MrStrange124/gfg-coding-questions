// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the count
// of maximum substrings str
// can be divided into
int maxSubStr(string str, int n)
{
    int cnt = 0, count0 = 0, count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
            count0++;
        else
            count1++;
        if (count0 == count1)
            cnt++;
    }
    if (cnt == 0)
        return -1;
    return cnt;
}

// Driver code
int main()
{
    string str = "0100110101";
    int n = str.length();

    cout << maxSubStr(str, n);

    return 0;
}
