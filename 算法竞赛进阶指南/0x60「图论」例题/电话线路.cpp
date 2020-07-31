#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int n , m , k ;
const int N = 10010 , M = N * 2;
int dist[N];
bool st[N];
int  h[M] , w[M] , e[M] , ne[M] , idx ;
int  q[N];
void add( int a , int b , int c ){
    e[idx] = b , ne[idx] = h[a] , w[idx] = c , h[a] = idx ++ ;
}

bool check( int x ){

    memset( st , 0 , sizeof st );
    memset( dist , 0x3f , sizeof dist );

    dist[1] = 0 ;
    int hh  = 0  , tt = 0;
    q[hh] = 1;

    while ( hh <= tt )
    {
        int t = q[ hh ++ ];
        st[t] = false;

        for( int i = h[t] ; ~i ; i = ne[i] ){
            int j = e[i];
            if( w[i] > x && dist[j] > dist[t] + 1 ){
                dist[j] = dist[t] + 1;
                if( !st[j] ){
                    st[j] = true;
                    q[ ++ tt ] = j;
                }
            }
            if( w[i] <= x && dist[j] > dist[t] ){
                dist[j] = dist[t];
                if( !st[j] ){
                    st[j] = true;
                    q[ ++ tt ] = j;
                }
            }
        }

    }
    

    return dist[n] < k + 1;
}
int main(){
    cin>>n>>m>>k ;
    memset( h , -1 , sizeof h );
    for( int i = 0 ; i < m ; i ++ ){
        int a , b , c  ;
        cin>>a>>b>>c;
        add( a , b , c );
        add( b , a , c );
    }

    int l = 0 , r = 1e6 + 1;
    while( l < r ){
        int mid = l + r >> 1;
        if( check( mid ) ) r = mid ;
        else l = mid + 1;
    }
    if( l == 1e6 + 1 ) l = -1;
    cout<<l<<endl;

    
    system("pause");
    return 0;
}