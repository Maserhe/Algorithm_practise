#include<algorithm>
#include<cstring>
#include<iostream>
#define x first
#define y second

using namespace std;
typedef pair<int , int > PII;
const int N = 160 , M = N*N;
PII q[M];
int n , m;
char g[N][N];
int dist[N][N];

int bfs(){
    int sx ,sy ;
    for(int i = 0 ; i < m ;i ++ )
        for( int j = 0 ; j < n ; j ++ )
            if(g[i][j] == 'K')
                sx = i, sy = j;
    
    int hh = 0, tt = 0;
    q[0] = { sx , sy};
    memset(dist , -1 , sizeof dist);
    
    dist[sx][sy] = 0;
    
    int dx[8] = {1 , 2 , 2 , 1 , -1 , -2 , -2 , -1 };
    int dy[8] = {-2 , -1 , 1 , 2 , 2 , 1 , -1 , -2 };
    
    while( hh <= tt ){ //只要队列不空
        PII t = q[ hh ++ ];
        for(int i = 0; i < 8 ; i ++ ){
            int a = t.x + dx[i];
            int b = t.y + dy[i];
    
            if(a < 0 || a >= m || b < 0 || b >= n) continue;
            if(g[a][b] == '*') continue;
            if(dist[a][b]!= -1) continue;
            
            if(g[a][b] == 'H') return dist[t.x][t.y] + 1;
            
            q[++tt] = {a , b};
            dist[a][b] = dist[t.x][t.y] + 1;
            
        }
    }
    
}
int main(){
    cin>>n>>m; // n 列 m 行
    
    for(int i = 0 ; i < m ; i ++ ) scanf("%s", g[i]);
    
    cout<<bfs()<<endl;
    
    return 0;
}