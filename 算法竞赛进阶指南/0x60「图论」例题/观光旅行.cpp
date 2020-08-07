#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;

const int N = 110;
int g[N][N];    //图
int dist[N][N];    //floyd的
int path[N][N];

int n , m ;
int cnt , p[N];
void get_path( int i , int j ){

    if( path[i][j] == 0 ) return ;
    int k = path[i][j];

    get_path( i , k );
    p[ cnt ++ ] = k;
    get_path( k , j );
}

int main(){

    cin>>n>>m;
    memset( g , 0x3f , sizeof g );
    for( int i = 1 ; i <= n ; i ++ ) g[i][i] = 1 ;

    while ( m -- )
    {
        int a , b , c ;
        cin>>a>>b>>c;
        g[a][b] = g[b][a] = min( g[a][b] , c );
    }
    
    //floyd
    int ans = 0x3f3f3f3f;

    memcpy( dist , g , sizeof dist );
    for( int k = 1 ; k <= n ; k ++ )
    {
        for( int i =  1 ; i < k ; i ++ ){
            for( int j = i + 1 ; j < k ; j ++ ){
                if( ans > dist[i][j] + g[i][k] + g[k][j] ){
                    ans = dist[i][j] + g[i][k] + g[k][j];

                    cnt = 0 ;
                    p[cnt ++ ] = k;
                    p[cnt ++ ] = i;
                    get_path(i , j );
                    p[cnt ++ ] = j;
                }
            
            }
        }

        for( int i = 1 ; i <= n ; i ++ ){
            for( int j = 1 ; j <= n ; j ++ ){
                if( dist[i][j] > dist[i][k] + dist[k][j] ){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k ;
                }
            }
        }
    
    }

    if( ans == 0x3f3f3f3f ) cout<<"No solution";
    else for( int i = 0 ; i < cnt ; i ++ ) cout<<p[i]<<" ";

    system("pause");
    return 0;
}