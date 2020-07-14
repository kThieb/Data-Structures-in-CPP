#include<bits/stdc++.h>
using namespace std;

class Ft {
    vector<int> bit;
    int n;
public:
    Ft(vector<int> arr) {
        n = arr.size();
        bit.assign(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            update(i, arr[i]);
        }
    }

    void update(int i, int val) {
        ++i;
        for (; i <= n; i += (i & (-i))) {
            bit[i] += val;
        }
    }

    int get_sum(int i) {
        ++i;
        int sum = 0;
        for (; i > 0; i -= (i & (-i))) {
            sum += bit[i];
        }
        return sum;
    }
}