//邻接表
#include <iostream>
using namespace std;

const int MAXV = 100;

// 边结点结构
struct ArcNode {
    int adjvex;          // 邻接点的下标
    int weight;          // 权值
    ArcNode *nextarc;    // 指向下一条边
};

// 顶点结构
struct VNode {
    int data;            // 顶点信息
    ArcNode *firstarc;   // 指向第一条边
};

// 邻接表
struct ALGraph {
    VNode adjlist[MAXV]; // 顶点数组
    int n, e;            // 顶点数，边数
};

// 初始化邻接表
void InitGraph(ALGraph &G, int n) {
    G.n = n;
    G.e = 0;
    for (int i = 0; i < G.n; i++) {
        G.adjlist[i].firstarc = NULL;
    }
}

// 添加无向边
void AddEdge(ALGraph &G, int v1, int v2, int w) {
    // 先加 v1 -> v2
    ArcNode *p1 = new ArcNode;
    p1->adjvex = v2;
    p1->weight = w;
    p1->nextarc = G.adjlist[v1].firstarc;
    G.adjlist[v1].firstarc = p1;

    // 再加 v2 -> v1（无向图）
    ArcNode *p2 = new ArcNode;
    p2->adjvex = v1;
    p2->weight = w;
    p2->nextarc = G.adjlist[v2].firstarc;
    G.adjlist[v2].firstarc = p2;

    G.e++;
}

// 打印邻接表
void PrintGraph(ALGraph &G) {
    cout << "顶点数: " << G.n << endl;
    cout << "边数: " << G.e << endl;
    cout << "邻接表:" << endl;

    for (int i = 0; i < G.n; i++) {
        cout << i << ": ";
        ArcNode *p = G.adjlist[i].firstarc;
        while (p != NULL) {
            cout << "->" << p->adjvex << "(" << p->weight << ")";
            p = p->nextarc;
        }
        cout << endl;
    }
}

// 主函数
int main() {
    ALGraph G;
    // 4个顶点：0 1 2 3
    InitGraph(G, 4);

    AddEdge(G, 0, 1, 5);
    AddEdge(G, 0, 2, 2);
    AddEdge(G, 1, 3, 1);
    AddEdge(G, 2, 3, 3);

    PrintGraph(G);

    return 0;
}