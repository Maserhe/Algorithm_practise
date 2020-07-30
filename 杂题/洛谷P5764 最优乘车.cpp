#include<iostream>
#include<cstring>
#include<algorithm>
#include<sstream>

using namespace std;
int n , m;
const int N = 600;
int g[N][N];
string s;
int xian[N];
int dist[N];
bool st[N];

int Dijskra(){
    memset( dist , 0x3f , sizeof dist );
    dist[1] = 0;
    
    for( int i = 0 ; i < n ; i ++ ){ //枚举N 个点
        
        int t = -1; //找出 剩下点 中距离 最小点的下标
        for( int j = 1 ; j <= n ; j ++ )
            if( !st[j] && ( t == -1 || dist[t] > dist[j]) )
                t = j;

        st[t] = true;
        for( int j = 1 ; j <= n ; j ++ )
            dist[j] = min( dist[j] , dist[t] + g[t][j]);
    }

    return  dist[n];
}

int main(){
    cin>>m>>n; //线路数 ， 车站数
    memset( g , 0x3f , sizeof g);
    getline( cin , s );
    while ( m -- )
    {
        getline( cin , s ); // 读入一行
        stringstream p(s);
        int cnt  = 0 , station ;
        while ( p >> station )
        {
            xian[ cnt ++ ] = station;
        }
        //将这个线路上面的点全部加入到  临界矩阵中
        for( int i = 0 ; i < cnt - 1 ; i ++ )
            for( int j = i + 1 ; j < cnt ; j ++ )
                g[ xian[i] ][ xian[j] ] = g[ xian[j] ][ xian[i] ] = 1;
    }

    int t = Dijskra();
    if( t == 0x3f3f3f3f ) puts("NO");
    else cout<< t - 1;
    system("pause");
    return 0;
}