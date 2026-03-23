//邻接表深度优先算法
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 105;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int u) {
    cout << u << " ";
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "邻接表DFS: ";
    dfs(1);
    return 0;
}
