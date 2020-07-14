#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Max_heap {
    int size;
    vector<T> pq;
    
    public:
    Max_heap(int n){
        pq = vector<T>(n);
        size = -1;
    }

    int get_parent(int i) {
        if (i % 2 == 0) return i / 2 - 1;
        else return i / 2;
    }

    pair<int, int> get_children(int i) {
        return pair<int, int> {2 * i + 1, 2 * i + 2};
    }

    void heapify_down(int i) {
        pair<int, int> children = get_children(i);
        int left = children.first;
        int right = children.second;
        int largest = i;
        if (left < size && pq[left] > pq[i])
            largest = left;
        if (right < size && pq[right] > pq[largest])
            largest = right;
        if (largest != i) {
            swap(pq[largest], pq[i]);
            heapify_down(largest);
        }
    }

    void heapify_up(int i) {
        if (i == 0) return;
        int parent = get_parent(i);
        if (pq[parent] < pq[i]) {
            swap(pq[parent], pq[i]);
            heapify_up(parent);
        }
    }

    void push(T x) {
        if (size == pq.size() - 1) return;
        pq[++size] = x;
        int cur = size;
        heapify_up(cur);
    }

    T pop() {
        T ans = pq[0];
        swap(pq[0], pq[size]);
        heapify_down(0);
        return ans;
    }

    int gsize() {
        return size + 1;
    }

    bool empty() {
        return size + 1 == 0;
    }
};

int main() {
    Max_heap<int> pq(10);
    pq.push(1);
    pq.push(9);
    pq.push(7);
    pq.push(8);
    pq.push(4);
    pq.push(6);

    cout << pq.pop() << endl;
    cout << pq.pop() << endl;


    return 0;
}