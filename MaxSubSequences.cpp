#include <bits/stdc++.h>

using namespace std;

int n;
int* arr;

int subsequenceMax (int l, int r) {
    if (l >= r) return arr[r];

    int m = l + (r - l) / 2;

    int wL = subsequenceMax(l, m);
    int wR = subsequenceMax(m + 1, r);

    int wML = arr[m], wMR = arr[m + 1];

    int s = arr[m];
    for (int i = m - 1; i >= l; i--) {
        s += arr[i];
        wML = max(s, wML);
    }
    s = arr[m + 1];
    for (int i = m + 2; i <= r; i++) {
        s += arr[i];
        wMR = max(s, wMR);
    }

    return max(max(wL, wR), (wML + wMR));
}

void input() {
    cin >> n;
    arr =  new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    cout << subsequenceMax(0, n - 1);

    return 0;
}
