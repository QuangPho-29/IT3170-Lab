#include <bits/stdc++.h>
using namespace std;

int getMid(int s, int e) { return s + (e -s)/2; }

int RMQ(int *st, int ss, int se, int qs, int qe, int index) {
	if (qs <= ss && qe >= se)
		return st[index];

	if (se < qs || ss > qe)
		return INT_MAX;

	int mid = getMid(ss, se);
	return min(RMQ(st, ss, mid, qs, qe, 2*index+1), RMQ(st, mid+1, se, qs, qe, 2*index+2));
}

int RMQStart(int *st, int n, int qs, int qe) {
	if (qs < 0 || qe > n-1 || qs > qe) {
		return -1;
	}

	return RMQ(st, 0, n-1, qs, qe, 0);
}

int build(int arr[], int ss, int se, int *st, int si) {
	if (ss == se) {
		st[si] = arr[ss];
		return arr[ss];
	}

	int mid = getMid(ss, se);

	st[si] = min(build(arr, ss, mid, st, si*2+1), build(arr, mid+1, se, st, si*2+2));
	return st[si];
}

int *allocatedTree(int arr[], int n) {
	int x = (int)(ceil(log2(n)));

	int max_size = 2*(int)pow(2, x) - 1;

	int *st = new int[max_size];

	build(arr, 0, n-1, st, 0);

	return st;
}

int main(){
    ios_base :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);
	int n, i = 0;
	cin >> n;
	int arr[n];
	for (i; i < n; i++) {
        cin >> arr[i];
	}
	int *st = allocatedTree(arr, n);
	int num, Q = 0;
	cin >> num;
	for (i  = 0; i < num; i++) {
        int qs, qe;
        cin >> qs >> qe;
        Q +=RMQStart(st, n, qs, qe);
	}
    cout << Q;
	return 0;
}
