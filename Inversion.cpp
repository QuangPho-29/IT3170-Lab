#include <bits/stdc++.h>

using namespace std;

int* arr;
int n;
long long int q = 0;

void mergeArr(int l, int m, int r) {
    int k = l;
    int n1 = m - l + 1;
    int n2 = r - m;

    int lArr[n1];
    int rArr[n2];

    for (int i = l; i <= m; i++) {
        lArr[i - l] = arr[i];
    }
    for (int i = m + 1; i <= r; i++) {
        rArr[i - m - 1] = arr[i];
    }

    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (lArr[i] <= rArr[j]) {
            arr[k] = lArr[i];
            i++; k++;
        } else {
            arr[k] = rArr[j];
            j++; k++;
            q += n1 - i;
        }
    }

    while (i < n1) {
        arr[k] = lArr[i];
        i++; k++;
    }

    while (j < n2) {
        arr[k] = rArr[j];
        j++; k++;
    }
}

void mergeSort(int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        mergeArr(l, m, r);
    }
}

void input() {
    cin >> n;
    arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    mergeSort(0, n - 1);

    cout << (q % (long long int)(7 + 1e9));

    return 0;
}
