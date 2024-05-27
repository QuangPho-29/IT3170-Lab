#include <bits/stdc++.h>

using namespace std;

vector <int>* adj;
bool* visited;
int* match;
int n, m;

void input() {
    cin >> n >> m;

    match = new int[n + m + 1];
    adj = new vector<int> [n + 1];
    visited = new bool[n + 1];

    for (int i = 1; i <= n + m; i++) {
        match[i] = -1;
    }

    for (int i = 1; i <= n; i++) {
        int k, staff;
        cin >> k;
        while (k--) {
            cin >> staff;
            adj[i].push_back(staff + n);
        }
    }
}

void de_allocated() {
    delete[] adj;
    delete[] visited;
    delete[] match;
}

bool dfs(int u) {
    if (visited[u]) return false;
    visited[u] = true;

    for (int v : adj[u]) {
        if (match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }

    return false;
}

int bipartite_match() {
    int result = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visited[j] = false;
        }
        if (dfs(i)) result++;
    }

    return result;
}


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    cout << bipartite_match();
    de_allocated();

    return 0;
}
