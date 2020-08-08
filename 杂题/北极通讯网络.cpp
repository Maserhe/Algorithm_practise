#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define x first
#define y second

using namespace std;

int n , k ;
const int N = 1e6 + 5;
typedef pair<int , int> PII;

PII q[N]; //存坐标
int p[N]; //并查集

struct edge{
    int a , b ;
    double c ;
    bool operator<(const edge& t ) const {
        return c < t.c;
    }
}e[N];

double get_path( PII a , PII b ){
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt( dx*dx + dy*dy );    
}

int find( int x ){
    if( p[x] != x ) p[x] = find( p[x] );
    return p[x];
}

int main(){

    cin >> n >> k;
    for( int i = 0 ; i < n ; i ++ ) p[i] = i; //并查集初始化


    for( int i = 0 ; i < n ; i ++ ) {
        int a , b ;
        cin >> a >> b;
        q[i] = { a , b }; 
    }

    int m = 0 ;    
    for( int i = 0 ; i < n ; i ++ ){
        for( int j = 0 ; j < i ; j ++ ){
            e[m ++ ] = { i , j , get_path( q[i] , q[j] )};
        }
    }
    sort( e, e + m );

    double res = 0 ;
    int cnt = n;

    
    for( int i = 0 ; i < m ; i ++ ){
        if( cnt == k ) break;

        int a = find( e[i].a ) , b = find( e[i].b ) ;
        double c = e[i].c;

        if( a != b ) {
            p[a] = b ;
            res = c;
            cnt -- ;
        }    
    }
    printf("%.2lf" , res );
    system("pause");
    return 0;
}

