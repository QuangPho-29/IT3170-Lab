#include <bits/stdc++.h>

using namespace std;

vector <int> inp;
int n, m, sum = 0, c = 0;

void solveEquation(int k, int maxV) {
    if (k == n - 1) {
        int tmp = m - sum;
        if (tmp > 0 && tmp % inp[k] == 0) {
            c++;
            return;
        }
    }

    for (int i = 1; i <= maxV; i++) {
        int tmp = i * inp[k];
        sum += tmp;
        if (sum > m - i * inp[n - 1]) {
            sum -= tmp;
            continue;
        }
        maxV = (m - sum) / inp[k]);
        solveEquation(k + 1, maxV);
        sum -= tmp;
    }
}

int main() {
    cin >> n >> m;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        inp.push_back(tmp);
    }

    int maxV = m; // Initialize maxV with the initial m value.
    solveEquation(0, maxV);
    cout << c;
    return 0;
}
