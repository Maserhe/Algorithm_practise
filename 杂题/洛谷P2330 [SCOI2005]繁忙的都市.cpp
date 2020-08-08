#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int n , m ;
const int N = 310 , M = 1e5 + 10 ;
int p[N] ; //并查集

struct edge{
    int a , b , c ;
    bool operator<( const edge & t )const{
        return c < t.c;
    }
    
}k[M];

int find( int x ){
    if( p[x] != x ) p[x] = find(p[x]);
    return p[x]; 
}

int main(){

    cin>>n>>m;
    for( int i = 1 ; i <= n ; i ++ ) p[i] = i ; //并查集初始化

    for ( int i = 0 ; i < m ; i ++  ){
        int a , b , c ;
        cin>>a>>b>>c;
        k[i] = { a , b , c };
    }
    
    sort( k , k + m );

    int res = 0 ;
    for( int i = 0 ; i < m ; i ++ ){
        int a = find( k[i].a ) , b  = find( k[i].b ) , c = k[i].c;

        if( a != b ) {
            p[ a ] = b ;
            res = c;
        }
    }

    cout << n-1 << " "<<res; //因为就n 个点， 则最小生成树为 n-1 条边

    system("pause");
    return 0;
}