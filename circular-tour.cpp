// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution
{
public:
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        int ds = 0, pt = 0, ans = 0, count = 0, start, end;
        for (int i = 0; i < n; i++)
        {
            ds += p[i].distance;
            pt += p[i].petrol;
        }
        if (ds < pt)
            return -1;
        pt = 0;
        start = 0;
        end = 1;
        while (start < n)
        {
            pt = p[start].petrol;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        petrolPump p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        Solution obj;
        cout << obj.tour(p, n) << endl;
    }
}
// } Driver Code Ends