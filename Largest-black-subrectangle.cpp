#include <bits/stdc++.h>

using namespace std;

/*int areaCalc(vector<int> inp, int col, int row) {
    int maxArea = 0, i = 1;
    inp.insert(inp.begin(), 0); inp.push_back(0);

    vector<int> l (col); vector<int> r (col);

    stack <int> sL;
    stack <int> sR;
    sL.push(0);
    sR.push(0);
    for (i; i <= col; i++) {
        while (inp[i] <= sL.top()){
            sL.pop();
        }
        l[i - 1] = sL.top();
        sL.push(i);
    }
    for (i; i >= 1; i--) {
        while (inp[i] <= sR.top()){
            sR.pop();
        }
        r[i - 1] = sR.top();
        sR.push(i);
    }
    for (i; i <= col; i++) {
        int area = (r[i] - l[i]) * inp[i - 1];
        maxArea = (maxArea < area)?area:maxArea;
    }
    return maxArea;
}*/

int areaCalc(vector<int> inp, int col) {
    int maxArea = 0;
    stack<int> s;
    inp.push_back(0);

    for (int i = 0; i <= col;) {
        if (s.empty() || inp[i] >= inp[s.top()]) {
            s.push(i++);
        } else {
            int top = s.top();
            s.pop();
            maxArea = max(maxArea, inp[top] * (s.empty() ? i : i - s.top() - 1));
        }
    }
    return maxArea;
}

int solve(vector<vector<int>>& inp, int row, int col) {
    int maxArea = areaCalc(inp[0], col);

    for (int i = 1; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (inp[i][j] != 0) {
                inp[i][j] += inp[i - 1][j];
            }
            else {
                inp[i][j] = 0;
            }
        }
        int area = areaCalc(inp[i], col);
        if (maxArea < area) {
            maxArea = area;
        }
    }

    return maxArea;
}

int main () {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> inp (row, vector<int> (col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> inp[i][j];
        }
    }
    cout << solve(inp, row, col);
    return 0;
}
