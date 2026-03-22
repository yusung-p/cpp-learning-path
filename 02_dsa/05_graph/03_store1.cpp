//图的存储结构，邻接矩阵
#include <iostream>
#include <cstring>
using namespace std;

const int MAXV = 100;
const int INF = 0x3f3f3f3f;

// 邻接矩阵存储图
struct MGraph
{
    int edges[MAXV][MAXV]; // 邻接矩阵
    int n, e;              // 顶点数，边数
};

// 初始化图
void InitGraph(MGraph &G, int n)
{
    G.n = n;
    G.e = 0;

    // 全部初始化为无穷大
    for (int i = 0; i < G.n; i++)
    {
        for (int j = 0; j < G.n; j++)
        {
            G.edges[i][j] = INF;
        }
    }

    // 对角线自己到自己为0
    for (int i = 0; i < G.n; i++)
    {
        G.edges[i][i] = 0;
    }
}

// 添加无向边
void AddEdge(MGraph &G, int v1, int v2, int w)
{
    G.edges[v1][v2] = w;
    G.edges[v2][v1] = w;
    G.e++;
}

// 打印邻接矩阵
void PrintGraph(MGraph &G)
{
    cout << "顶点数: " << G.n << endl;
    cout << "边数: " << G.e << endl;
    cout << "邻接矩阵:" << endl;

    for (int i = 0; i < G.n; i++)
    {
        for (int j = 0; j < G.n; j++)
        {
            if (G.edges[i][j] == INF)
                cout << "∞\t";
            else
                cout << G.edges[i][j] << "\t";
        }
        cout << endl;
    }
}

// 主函数
int main()
{
    MGraph G;
    // 4个顶点：0 1 2 3
    InitGraph(G, 4);

    // 加边
    AddEdge(G, 0, 1, 5);
    AddEdge(G, 0, 2, 2);
    AddEdge(G, 1, 3, 1);
    AddEdge(G, 2, 3, 3);

    PrintGraph(G);

    return 0;
}
