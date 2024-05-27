#include <bits/stdc++.h>

using namespace std;

int n;
int* arr;

void input() {
    cin >> n;
    arr =  new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int maxEvenSubSequence (){
    int sum = arr[0] ;
    int minOdd = INT_MAX;
    bool found = false;

    for (int i = 0; i < n ; i++) {
        sum = max (sum, max (arr[i], sum + arr[i]));
        if (arr[i] % 2 != 0 && arr[i] > 0) {
            minOdd = (minOdd > arr[i]) ? arr[i] : minOdd;
            found = true;
        }
    }
    if (sum % 2 == 0) {
        return sum;
    }

    if (found) {
        return sum - minOdd;
    }

    return -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();

    int result = maxEvenSubSequence();
    if (result == -1) cout << "NOT_FOUND";
    else cout << result;

    delete [] arr;
    return 0;
}
