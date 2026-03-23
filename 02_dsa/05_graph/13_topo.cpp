#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 1005;
const int MAXM = 10005;

// 邻接表
int head[MAXN], edge[MAXM], nxt[MAXM], idx;
// 入度
int in[MAXN];
int n, m;

// 加边
void add(int u, int v)
{
    edge[idx] = v;
    nxt[idx] = head[u];
    head[u] = idx++;
    // 入度+1
    in[v]++;
}

void topoSort()
{
    queue<int> q;

    // 1. 把所有入度为0的点入队
    for(int i = 1; i <= n; i++)
    {
        if(in[i] == 0)
        {
            q.push(i);
        }
    }

    // 记录拓扑序的点数
    int cnt = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        // 输出拓扑序（u就是当前排到的点）
        cout << u << " ";
        cnt++;

        // 遍历u的所有后继
        for(int i = head[u]; i != -1; i = nxt[i])
        {
            int v = edge[i];
            // 入度-1
            in[v]--;

            // 如果入度变成0，入队
            if(in[v] == 0)
            {
                q.push(v);
            }
        }
    }

    cout << endl;

    // 如果点数不等于n，说明有环，无法拓扑排序
    if(cnt != n)
    {
        cout << "有环" << endl;
    }
    else
    {
        cout << "拓扑排序正常" << endl;
    }
}

int main()
{
    memset(head, -1, sizeof(head));
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // u -> v 有一条边
        add(u, v);
    }

    topoSort();

    return 0;
}
