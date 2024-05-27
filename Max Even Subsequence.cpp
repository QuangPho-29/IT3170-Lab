#include <bits/stdc++.h>

using namespace std;

int n;
int *arr;

void input() {
    cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void de_allocated() {
    delete[] arr;
}

int max_subsequence(int l, int r) {
    if (l >= r) return arr[r];

    int m = (l + r) / 2;

    int w_left = max_subsequence(l, m);
    int w_right = max_subsequence(m + 1, r);

    int w_mid_l = arr[m], w_mid_r = arr[m + 1];

    int tmp = arr[m];
    for (int i = m - 1; i >= l; i--) {
        tmp += arr[i];
        w_mid_l = max(tmp, w_mid_l);
    }

    tmp = arr[m + 1];
    for (int i = m + 2; i <= r; i++) {
        tmp += arr[i];
        w_mid_r = max(tmp, w_mid_r);
    }

    return max(max(w_left, w_right), max(max(w_mid_l, w_mid_r), w_mid_l + w_mid_r));
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    cout << max_subsequence(0, n - 1);
    de_allocated();

    return 0;
}
