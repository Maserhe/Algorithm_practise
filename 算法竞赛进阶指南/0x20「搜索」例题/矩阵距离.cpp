#include<cstring>
#include<algorithm>
#include<iostream>
#define x first
#define y second

using namespace std;
const int N = 1010 , M = N * N ;
typedef pair<int , int > PII;
PII q[M];
char g[N][N];
int dist[N][N];
int n ,m;

void bfs(){
    int hh = 0 , tt = -1 ;
    
    memset(dist , -1 , sizeof dist);
    
    for(int i = 0 ; i < n ; i ++ ){
        for(int j = 0 ;j < m ; j ++ ){
            if(g[i][j] == '1'){
                q[++tt] = {i , j};
                dist[i][j] = 0;
            }
        }
    }
    
    int dx[4] = { 0 , 1 , 0 ,-1 };
    int dy[4] = { 1 , 0 , -1 ,0 };
    
    while( hh <= tt){ //只要队列不空
        PII t = q[ hh ++ ];
        for(int i = 0 ; i < 4 ;i ++ ){
            int a = t.x + dx[i];
            int b = t.y + dy[i];
            if(a< 0 || a >= n || b < 0 || b >= m)continue;
            if(dist[a][b] == -1){
                dist[a][b] = dist[t.x][t.y] + 1;
                q[++tt] = {a, b};
            }           
        }
    }
    
}
int main(){
    cin>>n>>m;
    for(int i = 0 ; i < n ; i ++ ) cin>>g[i]; //这个题的输入是字符串，一开没看清， 操了。
    
    bfs();
    
    for(int i = 0 ; i < n ;i ++ ){
        for(int j = 0 ; j < m ; j ++ )
            cout<<dist[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}