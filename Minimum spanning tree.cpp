#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u1, u2;
    int w;

    edge() {};

    edge(int v1, int v2, int weight) {
        u1 = v1;
        u2 = v2;
        w = weight;
    }
};

int v, e, total_weight = 0;
vector <edge> edge_set;
int* parent, *deep_level;

void input() {
    cin >> v >> e;

    parent = new int[v + 1];
    deep_level = new int[v + 1];
    for (int i = 0; i <= v; i++) {
        parent[i] = i;
        deep_level[i] = 0;
    }

    int v1, v2, weight;
    for (int i = 0; i < e; i++) {
        cin >> v1 >> v2 >> weight;
        edge_set.push_back(edge(v1, v2, weight));
    }

    sort(edge_set.begin(), edge_set.end(), [](edge &a, edge&b) {
            return (a.w < b.w);
        });
}

void de_allocated() {
    delete[] parent;
}

int find_root(int a) {
    return parent[a] == a ? a : find_root(parent[a]);
}

bool check(edge e) {
    int v1 = find_root(e.u1);
    int v2 = find_root(e.u2);

    if (v1 == v2) return false;
    if (deep_level[v1] > deep_level[v2]) swap(v1, v2);
    if (deep_level[v1] == deep_level[v2]) deep_level[v2]++;
    parent[v1] = v2;
    return true;
}

void kruskal() {
    for (edge e : edge_set) {
        if (check(e)) {
            total_weight += e.w;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();

    kruskal();
    cout << total_weight;

    de_allocated();

    return 0;
}
