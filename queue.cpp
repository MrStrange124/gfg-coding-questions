#include <bits/stdc++.h>
#define ll long long
using namespace std;
class Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;

public:
    Queue(int x)
    {
        front = size = 0;
        capacity = x;
        array = new int[x];
        rear = x - 1;
    }
    bool isFull()
    {
        return size == capacity;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(int i)
    {
        if (isFull())
            return;
        rear = (rear + 1) % capacity;
        array[rear] = i;
        size++;
    }
    int dequeue()
    {
        if (isEmpty())
            return INT_MAX;
        int i = array[front];
        front = (front + 1) % capacity;
        size--;
        return i;
    }
    int Front()
    {
        if (isEmpty())
            return INT_MAX;
        return array[front];
    }
    int Rear()
    {
        if (isEmpty())
            return INT_MAX;
        return array[rear];
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Queue q(5);
    cout << q.isEmpty() << endl;
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.Front() << endl;
    cout << q.Rear() << endl;

    return 0;
}