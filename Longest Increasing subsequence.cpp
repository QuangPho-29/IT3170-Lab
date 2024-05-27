#include <bits/stdc++.h>

using namespace std;

int n;
int* arr;
int* tmp;

void input() {
    cin >> n;
    arr = new int [n];
    tmp = new int [n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int longestIncreSub() {
    tmp[0] = 1;
    int result = 1;
    for (int i = 1; i < n; i++) {
        tmp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                if (tmp[i] < tmp[j] + 1) {
                    tmp[i] = tmp[j] + 1;
                }
            }
        }
        result = max(result, tmp[i]);
    }
    return result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    cout << longestIncreSub();

    delete [] arr;
    delete [] tmp;

    return 0;
}
