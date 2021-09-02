// C++ program to find number of customers who couldn't get a resource.
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_CHAR 26

// n is number of computers in cafe.
// 'seq' is given sequence of customer entry, exit events
int runCustomerSimulation(int n, const char *seq)
{
    char seen[MAX_CHAR] = {0};
    int count = 0, i = 0, ans = 0;
    while (seq[i] != '\0')
    {
        if (seen[seq[i] - 'A'] && count <= n)
        {
            seen[seq[i] - 'A']--;
            count--;
        }
        else if (count < n)
        {
            seen[seq[i] - 'A']++;
            count++;
        }
        else
            ans++;
        i++;
    }
    return ans / 2;
}

// Driver program
int main()
{
    cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation(1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
    return 0;
}
