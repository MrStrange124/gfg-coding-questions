#include <bits/stdc++.h>
#define ll long long
#define inf INT_MAX
using namespace std;
class kStacks
{
    int *arr;
    int *top;
    int *next;
    int n, k, free;

public:
    kStacks(int k1, int n1)
    {
        k = k1;
        n = n1;
        arr = new int[n];
        next = new int[n];
        top = new int[k];
        memset(top, -1, sizeof(top));
        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;
        next[n - 1] = -1;
        free = 0;
    }
    bool isFull()
    {
        return free == -1;
    }
    bool isEmpty(int sn)
    {
        return top[sn] == -1;
    }
    void push(int sn, int item)
    {
        if (isFull())
            return;
        int i = free;
        free = next[i];
        next[i] = top[sn];
        top[sn] = i;

        arr[i] = item;
    }
    int pop(int sn)
    {
        if (isEmpty(sn))
            return inf;
        int i = top[sn];
        top[sn] = next[i];
        next[i] = free;
        free = i;
        return arr[i];
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    kStacks ks(3, 10);
    ks.push(2, 15);
    ks.push(2, 45);
    ks.push(3, 50);
    cout << ks.pop(2);
    stack<int> s;
    return 0;
}