//图的抽象数据类型
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

// 图的抽象数据类型接口
class GraphADT {
public:
    virtual ~GraphADT() = default;

    // 基本操作
    virtual void createGraph(int n) = 0;          // 创建n个顶点的空图
    virtual void insertEdge(int u, int v, int w) = 0; // 插入边(u,v)，权值w
    virtual void removeEdge(int u, int v) = 0;   // 删除边(u,v)
    virtual bool existEdge(int u, int v) = 0;    // 判断边是否存在
    virtual int getVertexNum() = 0;              // 获取顶点数
    virtual int getEdgeNum() = 0;                // 获取边数
    virtual void printGraph() = 0;               // 打印图结构
};

// 邻接矩阵实现图ADT
class MGraph : public GraphADT {
private:
    vector<vector<int>> adjMatrix;
    int n; // 顶点数
    int m; // 边数

public:
    void createGraph(int n_) override {
        n = n_;
        m = 0;
        adjMatrix.assign(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) adjMatrix[i][i] = 0;
    }

    void insertEdge(int u, int v, int w) override {
        if (u < 0 || u >= n || v < 0 || v >= n) return;
        if (adjMatrix[u][v] == INF) {
            adjMatrix[u][v] = w;
            adjMatrix[v][u] = w; // 无向图
            m++;
        }
    }

    void removeEdge(int u, int v) override {
        if (u < 0 || u >= n || v < 0 || v >= n) return;
        if (adjMatrix[u][v] != INF) {
            adjMatrix[u][v] = INF;
            adjMatrix[v][u] = INF; // 无向图
            m--;
        }
    }

    bool existEdge(int u, int v) override {
        if (u < 0 || u >= n || v < 0 || v >= n) return false;
        return adjMatrix[u][v] != INF;
    }

    int getVertexNum() override { return n; }
    int getEdgeNum() override { return m; }

    void printGraph() override {
        cout << "邻接矩阵（顶点数=" << n << "，边数=" << m << "）：\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjMatrix[i][j] == INF) cout << "∞\t";
                else cout << adjMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

// 测试主函数
int main() {
    MGraph g;
    g.createGraph(5);
    g.insertEdge(0, 1, 1);
    g.insertEdge(0, 2, 1);
    g.insertEdge(1, 3, 1);
    g.insertEdge(2, 4, 1);
    g.insertEdge(3, 4, 1);

    g.printGraph();
    cout << "边(0,1)是否存在: " << (g.existEdge(0, 1) ? "是" : "否") << endl;
    return 0;
}
