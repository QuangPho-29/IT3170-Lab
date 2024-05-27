#include <bits/stdc++.h>

using namespace std;

int n;
int* arr;

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

void print() {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}

void merge_s(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *l_arr = new int[n1];
    int *r_arr = new int[n2];

    int i = 0, j = 0, k = l;

    for (int x = 0; x < n1; x++) {
        l_arr[x] = arr[l + x];
    }
    for (int x = 0; x < n2; x++) {
        r_arr[x] = arr[m + 1 + x];
    }

    while ((i < n1) && (j < n2)) {
        if(l_arr[i] <= r_arr[j]) {
            arr[k++] = l_arr[i++];
        } else {
            arr[k++] = r_arr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = l_arr[i++];
    }

    while (j < n2) {
        arr[k++] = r_arr[j++];
    }

    delete[] l_arr;
    delete[] r_arr;
}

void merge_sort(int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(l, m);
        merge_sort(m + 1, r);
        merge_s(l, m, r);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();

    merge_sort(0, n - 1);
    print();

    de_allocated();

    return 0;
}
