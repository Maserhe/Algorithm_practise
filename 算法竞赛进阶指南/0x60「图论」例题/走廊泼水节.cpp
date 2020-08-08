#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;
int n ;
const int N = 6010;
struct edge
{
    int a , b , w ;
    bool operator< ( const edge & t ){
        return w < t.w;
    }
} e[N];

int p[N] , Size[N];

int find( int x ){
    if( p[x] != x ) p[x] = find( p[x] );
    return p[x];
}
int main(){
    
    int T ;
    cin>>T;
    while( T -- ){
        cin>>n;
        for( int i = 0 ; i < n ; i ++ ) p[i] = i , Size[i] = i ;
        
        for( int i = 0 ; i < n - 1 ; i ++ ){
            int a , b , c ;
            cin >> a >> b >> c;
            e[i] = { a , b , c };
        }
        sort( e , e + n - 1 );

        int res = 0 ;
        for( int i = 0 ; i < n - 1 ; i ++ ){
            int a = find( e[i].a ) , b = find( e[i].b ) , c = e[i].w;
            if( a != b ){
                res += ( Size[a] * Size[b] - 1 ) * ( c + 1 );
                Size[b] += Size[a];
                p[a] = b ;
                
            }

        }
        cout<<res<<endl;
    }

    system("pause");
    return 0;
}