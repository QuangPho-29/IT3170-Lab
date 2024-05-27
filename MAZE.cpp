#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, int n, int m, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !visited[x][y]);
}

int shortestPath(vector<vector<int>>& maze, int n, int m, int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[startX][startY] = true;

    if (startX == 0 || startX == n - 1 || startY == 0 || startY == m - 1) {
        return 0;
    }

    int shortest = 1;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> current = q.front();
            q.pop();

            int x = current.first;
            int y = current.second;

            if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
                return shortest;
            }

            for (int dir = 0; dir < 4; dir++) {
                int newX = x + dx[dir];
                int newY = y + dy[dir];

                if (isValid(newX, newY, n, m, maze, visited)) {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        shortest++;
    }

    return -1;
}

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    vector<vector<int>> maze(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    int shortest = shortestPath(maze, n, m, r - 1, c - 1);

    cout << shortest;

    return 0;
}
