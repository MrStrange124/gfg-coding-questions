// #include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>
#define cpp_int long long
// using boost::multiprecision::cpp_int; // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;

// } Driver Code Ends
//User function template for C++
// catalan no. = 2nCn/(n+1)
class Solution
{
public:
    //Function to find the nth catalan number.
    cpp_int binomialCoeff(unsigned int n,
                          unsigned int k)
    {
        cpp_int res = 1;

        if (k > n - k)
            k = n - k;

        for (int i = 0; i < k; ++i)
        {
            res *= (n - i);
            res /= (i + 1);
        }

        return res;
    }
    cpp_int findCatalan(int n)
    {
        cpp_int ans = binomialCoeff(2 * n, n) / (n + 1);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    while (t--)
    {

        //taking nth number
        int n;
        cin >> n;
        Solution obj;
        //calling function findCatalan function
        cout << obj.findCatalan(n) << "\n";
    }
    return 0;
}