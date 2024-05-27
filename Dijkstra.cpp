#include <bits/stdc++.h>

using namespace std;

int* dist;
vector <pair <int, int>>* adj;
int v, e, s, t;

void input() {
    cin >> v >> e;
    dist = new int[v + 1];
    for (int i = 1; i <= v; i++) {
        dist[i] = INT_MAX;
    }

    adj = new vector <pair <int, int>>[v + 1];

    int from, to, weight;
    for (int i = 0; i < e; i++) {
        cin >> from >> to >> weight;
        adj[from].push_back({weight, to});
    }

    cin >> s >> t;
}

void de_allocated() {
    delete[] adj;
    delete[] dist;
}

void dijkstra() {
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    dist[s] = 0;

    pq.push({0, s});
    int cur_dist, cur_ver;
    while (!pq.empty()) {
        cur_dist = pq.top().first;
        cur_ver = pq.top().second;
        pq.pop();

        if (cur_ver == t) return;

        int w_tmp, v_tmp;
        for (pair <int, int> tmp : adj[cur_ver]) {
            w_tmp = tmp.first;
            v_tmp = tmp.second;

            if (cur_dist + w_tmp < dist[v_tmp]) {
                dist[v_tmp] = w_tmp + cur_dist;
                pq.push({dist[v_tmp], v_tmp});
            }
        }

    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    dijkstra();
    if (dist[t] == INT_MAX) cout << -1;
    else cout << dist[t];
    de_allocated();

    return 0;
}
