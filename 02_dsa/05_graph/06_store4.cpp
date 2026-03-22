//邻接多重表
#include <iostream>
using namespace std;

// 边结点
struct EdgeNode {
    int ivex, jvex;           // 边的两个顶点下标
    EdgeNode *ilink, *jlink;  // 分别指向依附于i、j的下一条边
};

// 顶点结点
struct VNode {
    int data;         // 顶点数据
    EdgeNode *firstedge;  // 指向第一条边
};

// 邻接多重表
struct AMLGraph {
    VNode adjmulist[100];
    int vexnum, edgenum;
};

// 创建无向图邻接多重表
void CreateAMLGraph(AMLGraph &G) {
    cout << "输入顶点数、边数：";
    cin >> G.vexnum >> G.edgenum;

    // 初始化顶点
    for (int i = 0; i < G.vexnum; i++) {
        cout << "输入顶点" << i << "数据：";
        cin >> G.adjmulist[i].data;
        G.adjmulist[i].firstedge = NULL;
    }

    // 建立边
    for (int k = 0; k < G.edgenum; k++) {
        int i, j;
        cout << "输入边(vi, vj)的下标i j：";
        cin >> i >> j;

        EdgeNode *p = new EdgeNode;
        p->ivex = i;
        p->jvex = j;

        // 头插法插入i的边表
        p->ilink = G.adjmulist[i].firstedge;
        G.adjmulist[i].firstedge = p;

        // 头插法插入j的边表
        p->jlink = G.adjmulist[j].firstedge;
        G.adjmulist[j].firstedge = p;
    }
}

// 遍历输出邻接多重表
void PrintGraph(AMLGraph G) {
    cout << endl << "-----邻接多重表遍历-----" << endl;
    for (int i = 0; i < G.vexnum; i++) {
        cout << "顶点" << i << "：";
        EdgeNode *p = G.adjmulist[i].firstedge;
        while (p) {
            if (p->ivex == i) {
                cout << G.adjmulist[p->ivex].data 
                     << "-" << G.adjmulist[p->jvex].data << "  ";
                p = p->ilink;
            } else {
                cout << G.adjmulist[p->jvex].data 
                     << "-" << G.adjmulist[p->ivex].data << "  ";
                p = p->jlink;
            }
        }
        cout << endl;
    }
}

int main() {
    AMLGraph G;
    CreateAMLGraph(G);
    PrintGraph(G);
    return 0;
}
