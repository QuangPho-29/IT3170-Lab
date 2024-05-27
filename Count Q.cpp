#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int row, col, sum, dif;
} mark;

int n, Count = 0;
vector<mark> safe;
vector<int> check(12, 0);

mark createMark(int row, int col) {
    mark newMark;
    newMark.row = row;
    newMark.col = col;
    newMark.sum = row + col;
    newMark.dif = row - col;
    return newMark;
}

bool isSafe(int row, int col) {
    int sum = row + col, dif = row - col;
    for (mark a : safe ){
        if (a.sum == sum || a.dif == dif || a.row == row || a.col == col) {
            return false;
        }
    }
    return true;
}

void CountSolution(int k) {

    if (k == n) {
        Count++;
        return ;
    }
    if (check[k] == 1) {
        CountSolution(k + 1);
    }
    for(int j = 0; j < n; j++) {
        if (isSafe(k, j)) {
            safe.push_back(createMark(k, j));
            CountSolution(k + 1);
            safe.pop_back();
        }
    }

    return ;
}


int main() {
    int tmp;
    cin >> n;
    if (n < 1 || n > 12) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if(tmp == 1) {
                check[i] = 1;
                safe.push_back(createMark(i, j));
            }
        }
    }

     CountSolution(0);
     cout<<Count;
    return 0;
}
