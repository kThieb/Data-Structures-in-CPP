#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Deque {
    vector<T> dq;
    int front, back, n;
    
    public:
    Deque(int _n) {
        this->n = _n;
        dq = vector<T>(_n);
        front = -1, back = -1;
    }

    void push_front(T x) {
        if (full()) {
            cout << "Overflow" << endl;
            return;
        }
        if (empty()) {
            front = 0;
            back = 0;
        }
        else if (front == 0)
            front = n - 1;
        else 
            front = front - 1;
        dq[front] = x;
    }

    void push_back(T x) {
        if (full()) {
            cout << "Overflow" << endl;
            return;
        }
        if (empty()) {
            front = 0;
            back = 0;
        }
        else if (back == n - 1)
            back = 0;
        else 
            back = back + 1;
        dq[back] = x;
    }

    void pop_back() {
        if (empty()) {
            cout << "Underflow" << endl;
            return;
        }

        if (front == back) {
            front = -1;
            back = -1;
        }
        else if (back == 0)
            back = n - 1;
        else 
            back = back - 1;
    }


    void pop_front() {
        if (empty()) {
            cout << "Underflow" << endl;
            return;
        }

        if (front == back) {
            front = -1;
            back = -1;
        }
        else if (front = n - 1)
            front = 0;
        else 
            front = front + 1;
    }

    T f() {
        return dq[front];
    }

    T b() {
        return dq[back];
    }

    bool empty() {
        return (front == -1);
    }

    bool full() {
        return ((front == 0 && back == n - 1) || front == back + 1);
    }
};