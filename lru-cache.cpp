// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
private:
    list<int> l;
    unordered_map<int, list<int>::iterator> mp;
    int csize;

public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        csize = cap;
    }

    //Function to return value corresponding to the key.
    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        return *mp[key];
    }

    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if (mp.find(key) == mp.end() && csize == l.size())
        {
            // mp.erase();
            l.pop_back();
        }
        else
            l.erase(mp[key]);

        l.push_front(value);
        mp[key] = l.begin();
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends