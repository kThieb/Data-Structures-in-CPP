#include<bits/stdc++.h>
using namespace std;

class Disjoint_sets {
    vector<int> parent;
    vector<int> size;

    public:
    Disjoint_sets (int n) {
        parent = vector<int>(n);
        size = vector<int>(n);

        for(int x = 0; x < n; ++x) {
            parent[x] = x;
            size[x] = 1;
        }
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    void union_sets(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y]) 
                swap(x, y);
            parent[y] = x;
            size[x] += size[y];
        }
    }
};