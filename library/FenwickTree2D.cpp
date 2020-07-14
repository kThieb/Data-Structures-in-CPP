#include<bits/stdc++.h>
using namespace std;

class FenwickTree2D {
    vector<vector<int>> bit;
    int m, n;
public:
    FenwickTree2D(vector<vector<int>> arr) {
        int m = arr.size(), n = arr[0].size();
        bit.assign(m + 1, vector<int> (n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                update(i, j, arr[i][j]);
            }
        }
    }

    void update(int i, int j, int val) {
        ++i, ++j;
        for (; i <= m; i += (i & (-i))) {
            for (; j <= n; j += (j & (-j))) {
                bit[i][j] += val;
            }
        }
    }

    int get_sum(int i, int j) {
        ++i, ++j;
        int sum = 0;
        for (; i > 0; i -= (i & (-i))) {
            for (; j > 0; j -= (j & (-j))) {
                sum += bit[i][j];
            }
        }
        return sum;
    }
};