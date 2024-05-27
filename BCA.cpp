#include <bits/stdc++.h>

using namespace std;

vector <int> teacher [10];
int subNum, cNum, tNum;
int maxLoad = INT_MAX;
int course [31];
bool confl[31][31];
int load [10];

bool isValid (int sub, int t) {
    for (int s : teacher[t]) {
        if (s == sub) {
            for (int i = 1; i < sub; i++) {
                if (course[i] == t && confl[i][sub]) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

void input () {
    cin >> tNum >> subNum;
    for (int i = 1; i <= subNum; i++) {
        course[i] = -1;
    }

    int k, tmp;
    for (int i = 0; i < tNum; i++) {
        cin >> k;
        for (int j = 0; j < k ; j++) {
            cin >> tmp;
            teacher[i].push_back(tmp);
        }
    }

    cin >> cNum;
    int x, y;
    for (int i = 0; i < cNum; i++) {
        cin >> x >> y;
        confl[x][y] = confl[y][x] = true;
    }
}

void TRY(int k) {
    if (k > subNum) {
        int curLoad = *max_element(load, load + tNum);
        maxLoad = min(curLoad, maxLoad);
        return;
    }


    for (int t = 0; t < tNum; t++) {
        if (isValid(k, t)) {

            course[k] = t;
            load[t]++;
            if (load[t] < maxLoad) {
                TRY(k + 1);
            }
            load[t]--;
        }
    }
    return;
}

int main() {
  input();
  TRY(1);
  cout << maxLoad;
  return 0;
}
