//最小生成树 Prim
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;

int g[MAXN][MAXN];
int dist[MAXN];
bool vis[MAXN];
int n, m;

int prim() {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, false, sizeof(vis));
    
    dist[1] = 0;
    int sum = 0;
    
    for (int i = 1; i <= n; i++) {
        // 找最小的dist[u]
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        
        vis[u] = true;
        sum += dist[u];
        
        // 用u更新其他点
        for (int v = 1; v <= n; v++) {
            if (!vis[v] && g[u][v] < dist[v]) {
                dist[v] = g[u][v];
            }
        }
    }
    return sum;
}

int main() {
    memset(g, 0x3f, sizeof(g));
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    
    cout << prim() << endl;
    return 0;
}
