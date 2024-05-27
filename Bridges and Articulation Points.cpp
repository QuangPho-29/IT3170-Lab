#include <bits/stdc++.h>

using namespace std;

int v, e;
vector <pair <int, int>> bridge_list;
vector <int>* adj;
int* low, * num;
bool* articulation_points;
int cur_num = 1, articu_num = 0;

void input() {
    cin >> v >> e;

    adj = new vector <int>[v + 1];
    low = new int[v + 1];
    num = new int[v + 1];
    articulation_points = new bool[v + 1];

    for (int i = 0; i <= v; i++) {
        low[i] = -1;
        num[i] = -1;
        articulation_points[i] = false;
    }

    int u1, u2;
    for (int i = 0; i < e; i++) {
        cin >> u1 >> u2;
        adj[u1].push_back(u2);
        adj[u2].push_back(u1);
    }
}

void de_allocated() {
    delete[] low;
    delete[] num;
    delete[] adj;
    delete[] articulation_points;
}

void dfs(int v, int pv) {
    low[v] = num[v] = cur_num++;
    int child = 0;

    for (int u : adj[v]) {
        if(u == pv) continue;

        if(num[u] == -1) {
            dfs(u, v);
            child++;

            low[v] = min(low[u], low[v]);

            if (pv == -1 && child > 1) articulation_points[v] = true;
            if(low[u] >= num[v] && pv != -1) articulation_points[v] = true;
            if(low[u] > num[v]) bridge_list.push_back({v, u});
        } else {
            low[v] = min(num[u], low[v]);
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();

    for (int i = 1; i <= v; i++) {
        if (num[i] == -1) {
            dfs(i, -1);
        }
    }

    for (int i = 1; i <= v; i++) {
        if (articulation_points[i]) articu_num++;
    }

    cout << articu_num << ' ' << bridge_list.size();
    de_allocated();

    return 0;
}
