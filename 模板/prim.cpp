#include<iostream>
#include<cstring>
using namespace std;

const int N = 1000;

int g[N][N];
int dist[N]; // 存储其他点到当前最小生成树的距离
bool st[N]; // 存储每个点是否已经在生成树中
int n, m ;  //时间复杂度是O(n^2 + m )
int prim(){
    memset(dist,0x3f,sizeof dist);
    int res = 0 ;
    for(int i = 0 ; i < n ; i ++ ){

        int t = -1;
        for(int j = 1; j <= n ; j ++ ){

            if(!st[j]&&(t==-1||dist[t] > dist[j])){
                t= j;
            }
        }
        if(i&&dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;
        if(i) res += dist[t];
        st[t] = true;
        for(int j =1 ; j <= n ; j ++ ){
            dist[j] = min(dist[j], g[t][j]);
        }

    }
    return res;



}
int main(){
    cin>>n>>m;
    memset(dist , 0x3f, sizeof dist);
    memset(g,0x3f,sizeof g);
    while ( m -- )
    {
        int a , b , c;
        scanf("%d%d%d", &a,&b,&c);

        g[a][b] = g[b][a] = min(g[a][b],c); //因为时无向图
        

    }
    int t = prim();
    if(t == 0x3f3f3f3f) puts("-1");
    else cout<<t;
    
    system("pause");
    return 0;
}