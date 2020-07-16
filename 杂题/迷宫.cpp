#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;
const int N = 110;
char g[N][N];
bool st[N][N];
int n ;
int sx ,sy , ex ,ey;
int dx[4] = {1, 0 , -1 , 0 };
int dy[4] = {0 , 1, 0 , -1 };
bool dfs(int sx, int sy){
    
    if(sx == ex && sy == ey ) return true;
    if(g[sx][sy] == '#') return false;
    st[sx][sy] = true;

    for(int i = 0 ; i < 4 ; i ++ ){
        int a = sx + dx[i];
        int b = sy + dy[i];

        if( a < 0 ||  a >= n || b < 0 || b >= n)continue;
        if( st[a][b]) continue;
        if( dfs(a , b )) return true;
    }
    return false;
}

int main(){
    cin>>n; 
    for(int i= 0 ; i < n ;i ++ ) cin>>g[i];

    cin>>sx>>sy>>ex>>ey;
    if(dfs(sx, sy))puts("YES");
    else puts("NO");
    system("pause");
    return 0;
}

/*

3
.##
..#
#..
0 0 2

*/