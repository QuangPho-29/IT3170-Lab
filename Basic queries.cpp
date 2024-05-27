#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return 0; // Outside the query range
        }
        if (l <= start && r >= end) {
            return tree[node]; // Node is completely inside the query range
        }
        int mid = (start + end) / 2;
        int leftSum = query(2 * node + 1, start, mid, l, r);
        int rightSum = query(2 * node + 2, mid + 1, end, l, r);
        return leftSum + rightSum;
    }

public:
    SegmentTree(vector<int>& input) {
        arr = input;
        n = input.size();
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    int query(int left, int right) {
        if (left < 0 || right >= n || left > right) {
            return -1; // Invalid input range
        }
        return query(0, 0, n - 1, left, right);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    int left = 1, right = 4;
    int sum = st.query(left, right);
    if (sum != -1) {
        cout << "Sum of elements from index " << left << " to " << right << ": " << sum << endl;
    } else {
        cout << "Invalid query range." << endl;
    }

    return 0;
}
