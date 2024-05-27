#include <bits/stdc++.h>

using namespace std;

int n1, n2;
int* arr1, *arr2;
int** s;

void input() {
    cin >> n1 >> n2;
    arr1 = new int[n1 + 1];
    arr2 = new int[n2 + 1];

    s = new int*[n1 + 1];
    for (int i = 0; i <= n1; i++) {
        s[i] = new int[n2 + 1];
        s[i][0] = 0;
    }
    for (int i = 0; i <= n2; i++) {
        s[0][i] = 0;
    }

    for (int i = 1; i <= n1; i++) {
        cin >> arr1[i];
    }
    for (int i = 1; i <= n2; i++) {
        cin >> arr2[i];
    }
    return;
}

int longestCommonSub() {

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (arr1[i] == arr2[j]) {
                s[i][j] = s[i - 1][j - 1] + 1;
            }
            else s[i][j] = max(s[i - 1][j], s[i][j - 1]);
        }
    }
    return s[n1][n2];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    cout << longestCommonSub();

    delete[] arr1;
    delete[] arr2;

    return 0;
}
