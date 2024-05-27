#include <bits/stdc++.h>

using namespace std;

int v, e;
vector <int>* graph;
bool* visited;

void input() {
    cin >> v >> e;
    graph = new vector<int>[v + 1];
    visited = new bool[v + 1];
    memset(visited, false, (v + 1) * sizeof(bool));

    int tmp1, tmp2;
    for (int i = 0; i < e; i++) {
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }
}

void de_allocated() {
    delete[] graph;
    delete[] visited;
}

void bfs(int a) {
    queue <int> q;
    priority_queue <int, vector <int>, greater <int>> pq;
    q.push(a);
    visited[a] = true;
    int tmp;

    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        cout << tmp << ' ';

        for (int i : graph[tmp]) {
            if (!visited[i]) {
                pq.push(i);
                visited[i] = true;
            }
        }
        while (!pq.empty()) {
            q.push(pq.top());
            pq.pop();
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            bfs(i);
        }
    }
    de_allocated();

    return 0;
}
