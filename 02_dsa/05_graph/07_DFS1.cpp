//邻接矩阵深度优先算法
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 105;
int g[MAXN][MAXN]; // 邻接矩阵
bool vis[MAXN];
int n, m;

void dfs(int u) {
    cout << u << " ";
    vis[u] = true;
    for (int v = 1; v <= n; v++) {
        if (g[u][v] == 1 && !vis[v]) {
            dfs(v);
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

    cout << "邻接矩阵DFS: ";
    dfs(1);
    return 0;
}
