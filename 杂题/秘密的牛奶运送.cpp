#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n , m;
const int N = 610 , M  = 1e4 + 10;
int h[N] , e[M] , ne[M] , w[M] , idx ;

struct edge
{
    int a , b , c ;
    bool f;
    bool operator< (const edge & t){
        return c < t.c;
    }
} ed[N];

int dist[N][N];// 记录任意两点间 的 路径经过的 最大边

int p[N];

int find( int x ){
    if( p[x] != x ) p[x] = find( p[x] );
    return p[x];
}
void add( int a ,int b ,int c ){
    e[idx] = b , ne[idx] = h[a] ,w[idx] = c , h[a] = idx ++ ;
}

void dfs( int start , int father , int ma , int d[] ){  //可能爆栈
    d[start] = ma;
    
    for( int i = h[start] ; ~i ; i = ne[i] ){
        int j = e[i];
        if( j != father ){
            dfs( j , start , max( ma , w[i] ), d );
        }
    }

}
int main(){
    cin>>n>>m;
    memset( h , -1 ,sizeof h );
    for( int i = 0 ; i < m ; i ++ ){
        int a , b , c;
        cin >> a >> b >> c;
        ed[i] = { a , b , c };
    }
    for( int i = 1 ; i <= n ; i++ ) p[i] = i; //并查集 初始化
    sort( ed , ed + m );

    long long res = 0;
    for( int i = 0 ; i < m ; i ++ ){
        int a = ed[i].a , b = ed[i].b , c = ed[i].c;

        if( find(a) != find(b) ){
            res += c;
            p[find(a)] = find(b);
            ed[i].f = true;
            add( a , b , c );
            add( b , a , c ); //最小生成树 新建一张图。
        }
    }
    // 记录任意两点间的 路径经过 的 最大值。
    for( int i = 1 ; i <= n ;i ++ ) dfs( i , -1 , 0 , dist[i] );

    long long ans  = 0x3f3f3f3f;
    //枚举所以的边

    for( int i = 0 ; i < m ; i ++ ){
        if( !ed[i].f && ed[i].c > dist[ed[i].a][ed[i].b]){
            ans = min( ans , res + ed[i].c - dist[ed[i].a][ed[i].b]);
        }
    }
    cout<<ans<<endl;
    system("pause") ;
    return 0;
}