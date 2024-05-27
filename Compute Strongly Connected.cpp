#include <bits/stdc++.h>

using namespace std;

int v, e, id = 0, num = 0;
vector <int>* adj;
int* ids, *low;
bool* visited;
bool* on_stack;

stack <int> s;

void input() {
    cin >> v >> e;

    adj = new vector <int>[v + 1];
    visited = new bool[v + 1];
    ids = new int[v + 1];
    low = new int[v + 1];
    on_stack = new bool[v + 1];

    for (int i = 0; i <= v; i++) {
        visited[i] = false;
        on_stack[i] = false;
    }

    int u_tmp, v_tmp;
    for (int i = 0; i < e; i++) {
        cin >> u_tmp >> v_tmp;
        adj[u_tmp].push_back(v_tmp);
    }
}

void de_allocated() {
    delete[] adj;
    delete[] visited;
}

void dfs(int a) {
    s.push(a);
    on_stack[a] = true;
    visited[a] = true;
    ids[a] = low[a] = ++id;

    for (int to : adj[a]) {
        if (!visited[to]) {
            dfs(to);
        }
        if (on_stack[to]) {
            low[a] = min(low[a], low[to]);
        }
    }

    if (ids[a] == low [a]) {
        while(true) {
            int tmp = s.top();
            s.pop();
            on_stack[tmp] = false;
            if (tmp == a) {
                break;
            }
        }
        num++;
    }
}

void compute_strongly_connected() {
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            visited[i] = false;
            dfs(i);
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    compute_strongly_connected();
    cout << num;

    de_allocated();

    return 0;
}
