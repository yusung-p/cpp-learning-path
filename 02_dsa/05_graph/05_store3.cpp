//十字链表
#include <iostream>
using namespace std;

// 弧结点（边结点）
struct ArcNode {
    int tailvex;   // 弧尾（起点）下标
    int headvex;   // 弧头（终点）下标
    ArcNode *hlink; // 指向同弧头的下一条弧（入边）
    ArcNode *tlink; // 指向同弧尾的下一条弧（出边）
};

// 顶点结点
struct VNode {
    int data;              // 顶点数据
    ArcNode *firstin;      // 第一个入边
    ArcNode *firstout;     // 第一个出边
};

// 十字链表图
struct OLGraph {
    VNode xlist[100];      // 顶点数组
    int vexnum, arcnum;    // 顶点数、弧数
};

// 创建十字链表
void CreateOLGraph(OLGraph &G) {
    cout << "输入顶点数和边数：";
    cin >> G.vexnum >> G.arcnum;

    // 初始化顶点
    for (int i = 0; i < G.vexnum; i++) {
        cout << "输入顶点" << i << "的数据：";
        cin >> G.xlist[i].data;
        G.xlist[i].firstin = NULL;
        G.xlist[i].firstout = NULL;
    }

    // 建立边
    for (int k = 0; k < G.arcnum; k++) {
        int i, j;
        cout << "输入弧(尾 头)下标：";
        cin >> i >> j;

        ArcNode *p = new ArcNode;
        p->tailvex = i;
        p->headvex = j;

        // 头插法插入出边表
        p->tlink = G.xlist[i].firstout;
        G.xlist[i].firstout = p;

        // 头插法插入入边表
        p->hlink = G.xlist[j].firstin;
        G.xlist[j].firstin = p;
    }
}

// 输出所有顶点的出边
void PrintOutArc(OLGraph G) {
    cout << endl << "-----各顶点出边-----" << endl;
    for (int i = 0; i < G.vexnum; i++) {
        cout << "顶点" << i << "出边：";
        ArcNode *p = G.xlist[i].firstout;
        while (p != NULL) {
            cout << p->tailvex << "->" << p->headvex << "  ";
            p = p->tlink;
        }
        cout << endl;
    }
}

// 输出所有顶点的入边
void PrintInArc(OLGraph G) {
    cout << endl << "-----各顶点入边-----" << endl;
    for (int i = 0; i < G.vexnum; i++) {
        cout << "顶点" << i << "入边：";
        ArcNode *p = G.xlist[i].firstin;
        while (p != NULL) {
            cout << p->tailvex << "->" << p->headvex << "  ";
            p = p->hlink;
        }
        cout << endl;
    }
}

int main() {
    OLGraph G;
    CreateOLGraph(G);
    PrintOutArc(G);
    PrintInArc(G);
    return 0;
}
