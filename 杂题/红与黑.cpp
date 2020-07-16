#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;  // 求能够连通的小点的个数   用的 深搜
const int N = 500;
char g[N][N];
int n , m;
bool st[N][N];
int dx[4] = { 0 , 1 , 0 , -1 };
int dy[4] = { 1 , 0 , -1 , 0 };

int dfs(int sx , int  sy){
    int cnt = 1 ;
    st[sx][sy] = true;
    for( int i = 0 ; i < 4 ; i ++ ){
        int a = sx + dx[i];
        int b = sy + dy[i];
        
        if(a < 0 || a >= n || b < 0 || b >= m) continue;
        if(st[a][b]) continue;
        if(g[a][b] != '.') continue;
        cnt += dfs(a , b);

    }
    return cnt;
}
int main(){

    cin>>n>>m;
    for( int i = 0 ; i < n ; i ++ ) cin>>g[i];
    int x, y;
    for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < m ; j ++ )
            if(g[i][j] == '@'){
                x = i;
                y = j;
            }

    cout<<dfs(x , y );
    system("pause");
    return 0;
}

/*

9 6 
....#.
.....#
......
......
......
......
......
#@...#
.#..#.

//统计 从 @ 出发有多少 个 . 
*/