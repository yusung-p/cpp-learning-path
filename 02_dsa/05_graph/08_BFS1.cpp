//邻接矩阵广度优先算法
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 105;
int g[MAXN][MAXN];
bool vis[MAXN];
int n, m;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v = 1; v <= n; v++) {
            if (g[u][v] == 1 && !vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(g, 0, sizeof(g));
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }

    cout << "邻接矩阵BFS: ";
    bfs(1);
    return 0;
}
