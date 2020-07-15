#include<iostream>
#include<algorithm>
#include<cstring>
#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;

const int N = 101 , M = N*N;
PII q[M];
bool st[N][N];
char g[N][N];
int n , m;
void dfs( int sx , int sy ){
    int hh = 0, tt = 0;
    q[0].x = sx;
    q[0].y = sy;
    st[sx][sy]= true;

    while (hh <= tt ) //只要队列不空
    {
        PII t = q[hh++]; //出队
        for( int i = t.x-1 ; i <= t.x + 1 ; i ++ )
            for( int j = t.y - 1 ; j <= t.y + 1 ; j ++ ){
                if( i == t.x && j == t.y ) continue;
                if( i < 0 || i >= n || j < 0 || j >= m ) continue;
                if( g[i][j] == '.'|| st[i][j] ) continue;
                q[++tt].x = i;
                q[tt].y = j;
                st[i][j] = true; //将连接的点置为True
            }
    }
     
}
int main(){
    
    cin>>n>>m;
    for(int i = 0 ; i < n ; i ++ ) scanf("%s",g[i]); //读取一行字符串
    
    int cnt = 0;
    for(int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < m ; j ++ ){
            if(g[i][j] == 'W' && !st[i][j]){
                dfs(i , j );
                cnt ++;
            }
        }
    cout<<cnt<<endl;
    system("pause");
    return 0;
}
