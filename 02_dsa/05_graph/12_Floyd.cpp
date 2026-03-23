#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=105;
const int INF=0x3f3f3f3f;
int d[MAXN][MAXN];
int n,m;
void Floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                d[i][j]=0;
            }else{
                d[i][j]=INF;
            }
        }
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        d[u][v]=w;
    }
    Floyd();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}