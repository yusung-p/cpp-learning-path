#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=1005;
//无穷大
const int INF=0x3f3f3f3f;
//邻接矩阵存图
int g[MAXN][MAXN];
//dist[i]：起点到i点最短距离
int dist[MAXN];
//vis[i]：标记i点是否已经确定最短路径
bool vis[MAXN];
int n,m;
//start是起点
void Dijkstra(int start){
    //初始化：所有距离设为无穷大
    memset(dist,0x3f,sizeof(dist));
    //都没访问过
    memset(vis,false,sizeof(vis));
    //起点到自己距离0
    dist[start]=0;
    //循环n次确定n个点的最短路径
    for(int i=1;i<n;i++){
        //找dist最小的点u
        int u=-1;
        for(int j=1;j<=n;j++){
            //找没被访问过，且距离最小的点
            if(!vis[j]&&(u==-1||dist[j]<dist[u])){
                u=j;
            }
        }
        //标记u已确定最短路径
        vis[u]=true;
        //用u更新所有邻居v
        for(int v=1;v<=n;v++){
            if(dist[v]>dist[u]+g[u][v]){
                dist[v]=dist[u]+g[u][v];
            }
        }
    }
}
int main(){
    cin>>n>>m;
    memset(g,0x3f,sizeof(g));
    for(int i=0;i<m;i++){
        int u,v,w;
        g[u][v]=w;
    }
    Dijkstra(1);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<endl;
    }
    return 0;
}