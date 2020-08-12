#include<algorithm>
#include<iostream>
#include<cstring>
// spfa 判断负环
using namespace std;

int n , m , k ;
const int N = 510 , M = 6000;
int h[N] , w[M] , e[M] , ne[M] , idx ;
int cnt[N];
bool st[N];
int dist[N];
int q[M]; // 队列

void add( int a , int b , int c ){
    e[idx] = b , ne[idx] = h[a] , w[idx] = c , h[a] = idx ++;
}

bool spfa(){

    memset( cnt , 0 , sizeof cnt );
    memset( dist , 0 , sizeof dist );
    memset( st , 0 , sizeof st );

    int hh = 0  , tt = 0; //循环队列
    for( int i = 1 ; i <= n ; i ++ ){
        q[ tt ++ ] = i;
        st[i] = true;
    }
    while (hh != tt )
    {
        int t = q[ hh ++ ];
        if( hh == N ) hh = 0;
        st[t] = false;
        
        for( int i = h[t] ; ~i ; i = ne[i] ){
            int j = e[i];
            
            if( dist[j] > dist[t] + w[i] ){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1 ; //走到当前点经过了几个点
        
                if( cnt[j] >= n ) return true;

                if( !st[j] ){
                    q[ tt ++ ] = j;
                    if( tt == N ) tt = 0;
                    st[j] = true;
                }
            }
        }
    }

    return false;
}
int main(){
    int T;
    cin >> T ;
    while ( T -- )
    {
        memset( h , -1 , sizeof h );
        idx = 0 ;
        cin >> n >> m >> k ; //n 个点 ，m 条 小路 ，k 条虫洞
        for( int i = 0 ; i < m ; i ++ ){
            int a , b , c;
            cin >> a >> b >> c ;
            add( a , b , c );
            add( b , a , c );

        }
        for( int i = 0 ; i < k ; i ++ ){
            int a , b , c ;
            cin >> a >> b >> c;
            add( a , b , -c );
        }
        
        if( spfa() ) cout<<"YES" <<endl;
        else cout<<"NO"<<endl;

    }
    
    system("pause");
    return 0;
}