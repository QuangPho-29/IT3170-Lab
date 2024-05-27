#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const ull MOD = 1e9 + 7;

ull expmul(ull a, ull b) {
    if (b == 0) return 0;
    if (b == 1) return a;
    ull tmp = expmul(a, b/2);
    tmp = ((tmp % MOD) * 2) % MOD;
    if (b % 2 == 0) return tmp;
    return (tmp + a) % MOD;
}


ull expmod(ull a, ull b) {
    if ( b == 0) return 1;
    ull tmp = expmod(a, b/2);
    tmp = expmul(tmp, tmp) % MOD;
    if (b % 2 == 0) {
        return tmp;
    }
    return expmul(tmp, a) % MOD;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ull a, b;
    cin >> a >> b;

    cout << expmod(a, b);
    return 0;
}
