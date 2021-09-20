// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
private:
    list<int> l;
    int hs[1010];
    unordered_map<int, list<int>::iterator> mp;
    int csize;

public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        csize = cap;
        memset(hs, -1, sizeof(hs));
    }

    //Function to return value corresponding to the key.
    int get(int key)
    {
        if (hs[key] == -1)
            return -1;
        return *mp[key];
    }

    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if (hs[key] == -1 && csize == l.size())
        {
            auto it = mp.begin();
            while (it != mp.end())
            {
                if (it->second == l.end())
                {
                    mp.erase(it);
                    break;
                }
                it++;
            }
            l.pop_back();
        }
        else if (hs[key] != -1)
            l.erase(mp[key]);

        l.push_front(value);
        mp[key] = l.begin();
        hs[key] = value;
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