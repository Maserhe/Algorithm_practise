#include<algorithm>
#include<cstring>
#include<iostream>
#define x first
#define y second
using namespace std;
int n;
const int N = 1010 , M = N * N;
typedef pair<int , int> PII;
PII before[N][N];  //记录上一次走过的 点 

int g[N][N];
bool st[N][N];
PII q[N];
void bfs(int sx ,int sy){
    int hh = 0 , tt =0;
    q[0] = { sx , sy };
    int dx[4] = { -1 , 0 , 1 , 0 };
    int dy[4] = { 0 , -1 , 0 , 1 };

    while (hh <= tt)
    {
        PII t = q[ hh ++ ];
        for( int i = 0 ; i < 4 ;i ++ ){
            int a = t.x + dx[i] , b = t.y + dy[i];
            
            if(a<0 || a >= n || b < 0 || b >= n ) continue;
            if(g[a][b]) continue;  //说明是墙
            
            //if( before[a][b].x != -1 ) continue; //如果上一个点没有被遍历过
            if(st[a][b]) continue;

            q[++tt] = {a, b};
            before[a][b] = t ;
            st[a][b] = true;
        }
        
    }
    

}
int main(){
    cin>>n;
    for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < n ; j ++ )
            cin>>g[i][j];
    
    bfs( n - 1 , n - 1 );

    PII end(0 , 0 );

    while (1)
    {
        cout<<end.x<<" "<<end.y<<endl;
        if(end.x == n-1 && end.y == n-1 ) break;
        end = before[end.x][end.y];
    }
    
    system("pause");    
    return 0;
}
/*

测试数据
5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
*/