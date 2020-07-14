#include<bits/stdc++.h>
using namespace std;

// Implementation using a fixed size vector

template<typename T>
class Queue {
    vector<T> q;
    int front, back, n;

    public:
    Queue(int _n) {
        q = vector<T>(_n);
        front = -1, back = -1, n = _n;
    };

    void enqueue(T x) {
        if ((back + 1) % n == front) return;
        back = (back + 1) % n;
        q[back] = x;
        if (front < 0) ++front;
    }

    void dequeue() {
        if (front == back) {
            front = -1;
            back = -1;
        }
        else front = (front + 1) % n;
    }

    T front() {
        return q[front];
    }
};