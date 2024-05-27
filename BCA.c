#include <bits/stdc++.h>

using namespace std;

vector <int> teacher [10];
int subNum, cNum, tNum;
int maxLoad = INT_MAX;
int course[30];
bool confl[30][30];
int load [10];

bool isValid (int sub, int t) {

  for (int i = 0; i < subNum; i++) {
    if (course[i] == t) {
      return !confl[sub][i];
    }
  }
  return true;
}

void input () {
  cin >> tNum >> subNum;

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
    confl[x][y] = true;
  }
}

void TRY(int k) {
  for (int t : teacher[k]) {
    if (isValid(t, k)) {
      course[t] = k;
      load[k]++;
      if (k == tNum) {
        for (int i = 0; i < k; i++) {
          maxLoad = min(maxLoad, load[i]);
        }
        return;
      }
      if (load[k] >= maxLoad) {
        return;
      }
      TRY(k + 1);
      load[k]--;
      course[t] = -1;

    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  input();
  TRY(0);
  cout << maxLoad;
  return 0;
}
