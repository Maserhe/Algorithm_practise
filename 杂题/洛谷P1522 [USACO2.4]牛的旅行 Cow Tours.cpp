#include<algorithm>
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<math.h>
#include<stdio.h>

#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;

int n ;
const int N = 160;

char g[N][N];
double dist[N][N];
PII p[N];
double MAX[N];
double get_dist( PII a , PII b ){
    double dx = a.x - b.x , dy = a.y - b.y;
    return sqrt( dx*dx + dy*dy );
}
int main(){
    
    cin>>n;
    for( int i = 0 ; i < n ; i ++ )cin>>p[i].x>>p[i].y;
    for( int i = 0 ; i < n ; i ++ )cin>>g[i];

    for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < n ; j ++ ){
            if( i != j ){
                if( g[i][j] == '1' ) dist[i][j] = get_dist( p[i], p[j] );
                else dist[i][j] = 0x3f3f3f3f;
            }
        }

    //floyd 算法
    for( int k = 0 ; k < n ; k ++ ){
        for( int i = 0 ; i < n ; i ++ ){
            for( int j = 0 ; j < n ; j ++ ){
                dist[i][j] = min( dist[i][j] , dist[i][k] + dist[k][j] );
            }
        }
    }
    
    for( int i = 0 ; i < n ; i ++ ) 
        for( int j = 0 ; j < n ; j ++ ){
            if( dist[i][j] != 0x3f3f3f3f ){
                MAX[i] = max( MAX[i] , dist[i][j] );
            }
        }
    double res = 0 ; 
    for( int i = 0 ; i < n ; i ++ ) res = max( res , MAX[i] );

    double ans = 0x3f3f3f3f ;
    for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < n ; j ++ )
            if( dist[i][j] > 0x3f3f3f3f/2 )
                ans = min( ans , MAX[j] + get_dist(p[i] , p[j]) + MAX[i] );


    printf("%6f", max( res , ans ));
    system("pause");
    return 0;
}