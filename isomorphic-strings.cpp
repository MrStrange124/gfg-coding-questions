// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include <iostream>
#include <string.h>

using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();
        if (n != m)
            return 0;
        bool ch[256] = {false};
        int map[256];
        memset(map, -1, sizeof(map));
        for (int i = 0; i < n; i++)
        {
            if (!ch[str1[i]])
            {
                if (map[str2[i]] != -1)
                    return 0;
                ch[str1[i]] = true;
                map[str2[i]] = str1[i];
            }
            else if (map[str2[i]] != str1[i])
                return 0;
        }
        return 1;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin >> t;
    string s1, s2;
    while (t--)
    {
        cin >> s1;
        cin >> s2;
        Solution obj;
        cout << obj.areIsomorphic(s1, s2) << endl;
    }

    return 0;
} // } Driver Code Ends