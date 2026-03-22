//图的定义
#include <iostream>
#include <vector>
using namespace std;

// 图的类型枚举
enum GraphType {
    UNDIRECTED,  // 无向图
    DIRECTED      // 有向图
};

// 边的结构体（无向/有向通用）
struct Edge {
    int u;      // 起点
    int v;      // 终点
    int weight; // 权值（默认1表示无权图）

    Edge(int u_, int v_, int w_ = 1) : u(u_), v(v_), weight(w_) {}
};

// 图的基础定义类
class Graph {
public:
    int n;                  // 顶点数
    int m;                  // 边数
    GraphType type;         // 图类型
    vector<Edge> edges;     // 边集合

    Graph(int n_, GraphType t_ = UNDIRECTED) : n(n_), m(0), type(t_) {}

    // 添加边
    void addEdge(int u, int v, int w = 1) {
        edges.emplace_back(u, v, w);
        m++;
        // 无向图需要添加反向边
        if (type == UNDIRECTED) {
            edges.emplace_back(v, u, w);
            m++;
        }
    }

    // 打印图的基本信息
    void printInfo() {
        cout << "图类型: " << (type == UNDIRECTED ? "无向图" : "有向图") << endl;
        cout << "顶点数: " << n << ", 边数: " << m << endl;
        cout << "边列表:" << endl;
        for (const auto& e : edges) {
            cout << "(" << e.u << ", " << e.v << ") 权值: " << e.weight << endl;
        }
    }
};

// 测试主函数
int main() {
    // 创建一个5个顶点的无向图
    Graph g(5, UNDIRECTED);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    g.printInfo();
    return 0;
}
