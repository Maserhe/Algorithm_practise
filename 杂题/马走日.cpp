#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;  // 马走日 算法。统计一共有多少种走法。
const int N = 510;

bool st[N][N];
int n , m ;
int cnt = 0;

int dx[8] = { 1 ,2 , 2 , 1, -1 , -2 , -2 , -1 };  
int dy[8] = { -2 , -1 , 1 , 2 , 2 ,1 , -1 , -2};

void dfs( int x , int y , int sum){
    
    if(sum == n*m ){
        cnt ++;
        return;
    }

    st[x][y] = true;

    for( int i = 0; i < 8 ; i ++ ){
        int a = x + dx[i];
        int b = y + dy[i];

        if( a < 0 || a >= n || b < 0 || b >= m ) continue;
        if(st[a][b]) continue;
        
        dfs(a , b , sum + 1);
    }

    st[x][y] = false;
}

int main(){

    int x, y;
    cin>>n>>m>>x>>y;
    
    dfs(x , y , 1);
    cout<<cnt;
    
    system("pause");
    return 0;
}

/* 测试数据
5 4 0 0 
结果 32
*/