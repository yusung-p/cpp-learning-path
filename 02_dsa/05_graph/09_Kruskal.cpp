//最小生成树 邻接表+Kruskal
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 105;

// 并查集
int fa[MAXN];
int find(int x) {
    if(fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

// 边结构体
struct Edge {
    int u, v, w;
    // 排序：从小到大
    bool operator < (const Edge& other) const {
        return w < other.w;
    }
};

vector<Edge> edges;

int main() {
    int n, m;
    cin >> n >> m;

    // 初始化并查集
    for(int i=1; i<=n; i++) fa[i] = i;

    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // 排序
    sort(edges.begin(), edges.end());

    int sum = 0;
    int cnt = 0;

    for(auto e : edges) {
        int u = e.u;
        int v = e.v;
        int w = e.w;

        int fu = find(u);
        int fv = find(v);

        if(fu != fv) {
            fa[fu] = fv;    // 合并
            sum += w;       // 累加权值
            cnt++;
            if(cnt == n-1) break; // 够n-1条就结束
        }
    }

    cout << "最小生成树权值和：" << sum << endl;
    return 0;
}
