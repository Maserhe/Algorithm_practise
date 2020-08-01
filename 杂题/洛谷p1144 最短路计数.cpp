#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int n , m;
const int N = 1e6 + 10 , M = N*2;
int h[N] , e[M] , ne[M] , idx ;
int dist[N];
int cnt[N];
int q[N];

void add( int a , int b ){
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

void bfs(){
    
    memset( dist , 0x3f , sizeof dist );

    dist[1] = 0 ;
    cnt[1] = 1;

    int tt = 0  , hh = 0 ;
    q[0] = 1;
    

    while ( hh <= tt )
    {
        int t = q[ hh ++ ];

        for( int i = h[t] ; ~i ; i = ne[i] ){
            int j = e[i];

            if( dist[j] > dist[t] + 1 ){
                dist[j] = dist[t] + 1;
                cnt[j] = cnt[t];
                q[ ++ tt ] = j;
        
            }

            else if( dist[j] == dist[t] + 1 ){ // 这里一定要是 else if , 不能是 if 
                cnt[j] = ( cnt[t] + cnt[j] ) % 100003;
            }
        }
    }


}
int main(){
    cin>>n>>m;
    memset( h , -1 , sizeof h );
    for( int i = 0 ; i < m ; i ++ ){
        int a , b ;
        cin>>a>>b ;
        add( a , b );
        add( b , a );
    }
    bfs();
    
    for( int i = 1 ; i <= n ; i ++ ) cout<< cnt[i] <<endl;
    system("pause");

    return 0;
}