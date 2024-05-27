#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll *arr;

void input() {
    cin >> n;

    arr = new ll[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void de_allocated() {
    delete[] arr;
}

int max_subsequence() {
    ll local_max = arr[0], global_max = arr[0];

    for (int i = 1; i < n; i++) {
        local_max = max(arr[i], local_max + arr[i]);
        global_max = max (local_max, global_max);
    }

    return global_max;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    cout << max_subsequence();
    de_allocated();

    return 0;
}
