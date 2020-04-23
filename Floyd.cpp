#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 210; //Floyed的算法时间复杂度时O(n^3)的

int n, m , Q;
int dist[N][N];

int g[N][N]; //邻接矩阵

void floyd(){
    for(int k = 1; k <= n ; k ++ )
        for( int i = 0 ; i <= n; i ++ )
            for( int j = 0 ; j <= n ; j ++ )
                dist[i][j] = min(dist[i][k] + dist[k][j] , dist[i][j]);

}
int main(){
    cin>>n>>m>>Q;
    memset(dist , 0x3f, sizeof dist);
    for(int i = 1; i<= n ; i ++ ) g[i][i] = 0;
    int a, b ,c;
    
    while (m -- )
    {
        int a, b ,w;
        scanf("%d%d%d",&a,&b,&c);
        dist[a][b] = min(dist[a][b],w); //如果重边，直接去最小的边就行
    }
    

    while (Q--) //进行Q次询问
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(dist[l][r]> 1e9) puts("impossible");
        else printf("%d",dist[l][r]);

    }
    system("pause");
    return 0;
}

