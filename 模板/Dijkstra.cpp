#include<iostream>
#include<cstring>
using namespace std;

const int N = 500;

int g[N][N];
int dist[N]; //存取第i个点的最小距离
bool st[N]; //判断第i个点的最小距离是否确定

int n , m;

int Dijkstra(){
    memset(dist,0x3f,sizeof dist); //使记录值全部初始化为最大

    dist[1] =0;

    for(int i = 0 ; i < n ; i ++ ){
        
        int t =-1;
        for(int j = 1; j <= n; j++ ){

            if(!st[j]&&(t==-1||dist[t]>dist[j])){
                t = j;
            }
        }
        st[t] =true;
        for(int j = 1; j <= n ; j++ ){

            dist[j] = min(dist[j],dist[t]+g[t][j]);
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    
    return dist[n]; 
}
int main(){

    scanf("%d%d",&n,&m);

    memset(g,0x3f,sizeof g); //使邻接矩阵 初始化为最大

    while ( m-- )
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b] = min(g[a][b],c); //去除重环，以及重边        
    }
    int t = Dijkstra();
    cout<<t;
    system("pause");
    return 0;
}
/*测试数据

3 3
1 2 2
2 3 1
1 3 4

输出
3

*/
