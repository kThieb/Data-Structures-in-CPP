#include<bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> BITree;
    int n;

public:
    FenwickTree(vector<int> arr, int _n) {
        BITree = vector<int>(n + 1);
        n = _n;
        for (int i = 1; i <= n; ++i) {
            BITree[i] = 0;
        }

        for (int i = 0; i < n; ++i) {
            update(i, arr[i]);
        }
    }

    int get_sum_from_0(int index) {
        ++index;
        int sum = 0;
        while (index > 0) {
            sum += BITree[index];
            index -= (index & (-index));
        }
        return sum;
    }

    int get_sum(int i, int j) {
        return get_sum_from_0(j) - get_sum_from_0(i);
    }

    void update(int index, int val) {
        ++index;
        while (index <= n) {
            BITree[index] += val;
            index += (index & (-index));
        }
    }
};

int main() { 
    vector<int> freq = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int n = freq.size(); 
    FenwickTree ft(freq, n); 
    cout << "Sum of elements in arr[0..5] is " << ft.get_sum(0, 5); 
  
    freq[3] += 6; 
    ft.update(3, 6); 
  
    cout << "\nSum of elements in arr[0..5] after update is " << ft.get_sum(0, 5); 
  
    return 0; 
} 