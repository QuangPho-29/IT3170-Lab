#include <bits/stdc++.h>

using namespace std;

int v, e;
vector <int>* adj;
int* mark;

void input() {
    cin >> v >> e;
    adj = new vector <int>[v + 1];
    mark = new int[v + 1];

    int u_tmp, v_tmp;
    for (int i = 0; i < e; i++) {
        cin >> u_tmp >> v_tmp;
        adj[u_tmp].push_back(v_tmp);
        adj[v_tmp].push_back(u_tmp);
    }

    for (int i = 1; i <= v; i++) {
        mark[i] = -1;
    }
}

void de_allocated() {
    delete[] adj;
    delete[] mark;
}

bool check_dipartite() {
    queue <int> q;
    q.push(1);
    for (int start = 1; start <= v; start++) {
        if (mark[start] == -1) {
            q.push(start);
            mark[start] = 1;

            while (!q.empty()) {
                int tmp = q.front();
                q.pop();

                for (int i : adj[tmp]) {
                    if (mark[i] == -1) {
                        q.push(i);
                        mark[i] = 1 - mark[tmp];
                    } else if (mark[i] == mark[tmp]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    cout << check_dipartite();
    de_allocated();

    return 0;
}
