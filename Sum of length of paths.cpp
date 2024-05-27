#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>>* adj;
long long* dist;
long long* f;
long long f_total = 0;
int n;

void dfs1(int node, int parent) {
    for (auto& edge : adj[node]) {
        int child = edge.first;
        int weight = edge.second;
        if (child != parent) {
            dist[child] = dist[node] + weight;
            dfs1(child, node);
        }
    }
}

void input() {
    cin >> n;
    adj = new vector<pair<int, int>>[n + 1];
    dist = new long long[n + 1];
    f = new long long[n + 1];

    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        f_total += w;
    }
    f_total /= 2; // Chia đôi tổng trọng số vì mỗi cạnh được tính hai lần
}

void dfs2(int node, int parent, long long total_weight) {
    f[node] = 0;
    for (auto& edge : adj[node]) {
        int child = edge.first;
        int weight = edge.second;
        if (child != parent) {
            dfs2(child, node, total_weight);
            f[node] += f[child] + weight; // Tính tổng khoảng cách đúng cách
        }
    }
    f[node] += total_weight - dist[node]; // Cộng khoảng cách từ các nút còn lại
}

void de_allocated() {
    delete[] adj;
    delete[] dist;
    delete[] f;
}


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();

    dfs1(1, -1);
    dfs2(1, -1, f_total);

    long long max_f = 0;
    for (int i = 1; i <= n; ++i) {
        max_f = max(max_f, f[i]);
    }

    cout << max_f << endl;

    de_allocated();

    return 0;
}
