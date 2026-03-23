#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int MAXM = 10005;
const int INF = 0x3f3f3f3f;

// 邻接表
int head[MAXN], edge[MAXM], w[MAXM], nxt[MAXM], idx;
int in[MAXN];           // 入度
int n, m;

int ve[MAXN];   // 事件最早发生时间
int vl[MAXN];   // 事件最晚发生时间

// 加边
void add(int u, int v, int weight)
{
    edge[idx] = v;
    w[idx] = weight;
    nxt[idx] = head[u];
    head[u] = idx++;
    in[v]++;
}

// 拓扑排序（同时求ve）
bool topoSort(int topo[], int &cnt)
{
    queue<int> q;
    cnt = 0;
    memset(ve, 0, sizeof(ve));

    for(int i = 1; i <= n; i++)
        if(in[i] == 0)
            q.push(i);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        topo[cnt++] = u;

        for(int i = head[u]; ~i; i = nxt[i])
        {
            int v = edge[i];
            int weight = w[i];

            // 更新事件最早时间
            if(ve[v] < ve[u] + weight)
                ve[v] = ve[u] + weight;

            in[v]--;
            if(in[v] == 0)
                q.push(v);
        }
    }
    return cnt == n;   // 无环返回true
}

// 求关键路径
void criticalPath()
{
    int topo[MAXN], cnt;

    // 第一步：拓扑排序 + 求ve[]
    if(!topoSort(topo, cnt))
    {
        cout << "有环，不存在关键路径" << endl;
        return;
    }

    // 第二步：初始化vl[] 为 终点ve
    int max_ve = ve[topo[cnt-1]];
    for(int i = 1; i <= n; i++)
        vl[i] = max_ve;

    // 第三步：逆拓扑序求vl[]
    for(int k = cnt-1; k >= 0; k--)
    {
        int u = topo[k];
        for(int i = head[u]; ~i; i = nxt[i])
        {
            int v = edge[i];
            int weight = w[i];

            // 更新最晚时间
            if(vl[u] > vl[v] - weight)
                vl[u] = vl[v] - weight;
        }
    }

    // 第四步：找关键活动（边）
    cout << "关键路径上的边(u->v 权值):" << endl;
    for(int u = 1; u <= n; u++)
    {
        for(int i = head[u]; ~i; i = nxt[i])
        {
            int v = edge[i];
            int weight = w[i];
            // 关键活动满足 ve[u] + w == vl[v]
            if(ve[u] + weight == vl[v])
            {
                cout << u << " -> " << v << "  " << weight << endl;
            }
        }
    }
    cout << "总工期: " << max_ve << endl;
}

int main()
{
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        add(u, v, weight);
    }
    criticalPath();
    return 0;
}
