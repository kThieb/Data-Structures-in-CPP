#include<bits/stdc++.h>
using namespace std;

// Implementation with a fixed size vector

template<typename T>
class Stack {
    vector<T> s;
    int k;
    public:
    Stack() {
        k = 0;
    }
    Stack(int n) {
        s = vector<T>(n);
        k = 0;
    }

    void push(T x) {
        if (k < n) s[k++] = x;
    }

    void pop() {
        --k;
    }

    T top() {
        return s[k - 1];
    }
};


// Implementation with a variable size vector

template<typename T> 
class Stack_vec {
    vector<T> s;
    public:
    Stack() {}

    void push(T x) {
        s.push_back(x);
    }

    void pop() {
        s.pop_back();
    }

    T top() {
        return s.back();
    }
};