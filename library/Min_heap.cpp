#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Min_heap {
    vector<T> pq;
    int n;
    public:
    Min_heap(int size) {
        pq = vector<T>(size);
        n = 0;
    }

    int get_parent(int i) {
        return i % 2 == 0 ? i / 2 - 1 : i / 2;
    }

    vector<int> get_children(int i) {
        return vector<int> {2 * i + 1, 2 * i + 2};
    }

    void heapify_down(int i) {
        int smallest = i;
        vector<int> children = get_children(i);
        int left = children[0], right = children[1];
        if (left < n && pq[i] > pq[left]) smallest = left;
        if (right < n && pq[smallest] > pq[right]) smallest = right;
        if (smallest != i) {
            swap(pq[smallest], pq[i]);
            heapify_down(smallest);
        }
    }

    void heapify_up(int i) {
        if (i == 0) return;
        int parent = get_parent(i);
        if (pq[parent] > pq[i]) {
            swap(pq[parent], pq[i]);
            heapify_up(parent);
        }
    }

    void push(T x) {
        pq[n] = x;
        heapify_up(n++);
    }

    T pop() {
        T ans = pq[0];
        swap(pq[0], pq[--n]);
        heapify_down(0);
        return ans;
    }
};

int main() {
    Min_heap<int> pq(10);
    pq.push(1);
    pq.push(2);
    pq.push(9);
    pq.push(5);
    pq.push(3);
    cout << pq.pop() << " " << pq.pop() << " " << endl;
    return 0;
}