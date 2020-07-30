#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int n , m;
const int N = 1e5 + 10;
int dist[6][N];
bool st[N];
int source[6];
int g[7][7]; //代表任意
int e[N] , ne[N] , w[N] , h[N] , idx ;
int q[N * 5];
bool ss[6];


void add( int a , int b , int c ){
    e[idx] = b , ne[idx] = h[a] , w[idx] = c , h[a] = idx ++ ;
}

inline void spfa(int start,int dist[])
{
    memset(dist,0x3f,N*4);
    dist[start]=0;

    int hh=0,tt=1;
    q[0]=start;

    while(hh!=tt)
    {
        int t=q[hh++];
        if(hh==N) hh=0;

        st[t]=false;
        for (int i= h[t] ; i != -1 ; i = ne[i] )
        {
            int v=e[i];
            if(dist[v]>dist[t]+ w[i])
            {
                dist[v]=dist[t]+w[i];
                if(!st[v])
                {
                    st[v]=true;
                    q[tt++]=v;
                    if(tt==N) tt=0;
                }
            }
        }
    }
}

int dfs( int start , int zou , int distance ){ // 从第一个点开始搜 ，从第i 个点开始 ， 现在的距离
    if( start == 6 ) return distance;
    int res = 0x3f3f3f3f;
    for( int i = 1 ; i < 6 ; i ++ ) //走剩下的五个点。
    {
        if( !ss[i] ){
            ss[i] = true ;
            res = min( res , dfs( start + 1 , i , distance + dist[zou][source[i]]));
            ss[i] = false;
        }
    }
    return res;
}



int main(){
    cin>>n>>m;
    source[0] = 1;
    for( int i = 1 ; i < 6 ; i ++ ) cin>>source[i];

    memset( h , -1 , sizeof h );

    for( int i = 0 ; i < m ; i ++ ){
        int a , b , c ;
        cin>>a>>b>>c;
        add( a , b , c );
        add( b , a , c );
    } 
    
    for( int i = 0 ; i < 6 ; i ++ ) spfa( source[i] , dist[i] );

    cout<<dfs( 1 , 0 , 0 );;
    system("pause");
    return 0;
}