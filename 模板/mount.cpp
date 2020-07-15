#include<iostream>
#include<algorithm>
#include<cstring>
#define x first
#define y second

using namespace std;
const int N = 1010, M = N * N ;
typedef pair<int, int> PII;
PII q[M];
bool st[N][N];
int n;
int g[N][N];

void dfs(int sx , int sy , bool & high , bool & lower){

    int hh = 0 , tt = 0; //构建队列
    q[0] = {sx , sy}; //放入队头元素

    st[sx][sy] = true;
    
    while(hh <= tt){
        
        PII t = q[hh ++ ];
        for( int i = t.x - 1 ; i <= t.x + 1 ; i ++ )
            for( int j =  t.y - 1 ; j <= t.y + 1 ; j ++ ){
                if(i < 0 || i >= n || j < 0 || j >= n) continue;

                if(g[i][j] != g[t.x][t.y]){
                    if(g[i][j] > g[t.x][t.y]) high = true;
                    else  lower = true;

                }

                else if(!st[i][j]){
                    q[++tt] = {i  , j };
                    st[i][j] = true;
                }
            }
    }
}

int main(){
    cin>>n;
    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < n ; j ++ )
            cin>>g[i][j];

    int mo = 0 , gu = 0; //山峰和山谷数量。

    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < n ; j ++ ){
            if(!st[i][j]){
                bool high= false , lower = false;
                dfs(i, j , high , lower);

                if(!high) mo ++;
                if(!lower) gu ++;
            
            }    
        }
    cout<<mo<<"\n"<<gu<<endl;

    system("pause");
    return 0;
}

/*
测试数据
5
8 8 8 7 7
7 7 6 8 7
7 7 7 7 7
7 8 9 7 8
7 9 8 8 8

*/

/*
#include<iostream>
#include<algorithm>
#include<cstring>
#define x first
#define y second

using namespace std;
const int N = 1010, M = N * N ;
typedef pair<int, int> PII;
PII q[M];
bool st[N][N];
int n;
int g[N][N];

void dfs(int sx , int sy , bool & high , bool & lower){

    int hh = 0 , tt = 0; //构建队列
    q[0] = {sx , sy}; //放入队头元素

    st[sx][sy] = true;
    
    while(hh <= tt){
        
        PII t = q[hh ++ ];
        for( int i = t.x - 1 ; i <= t.x + 1 ; i ++ )
            for( int j =  t.y - 1 ; j <= t.y + 1 ; j ++ ){
                if(i < 0 || i >= n || j < 0 || j >= n) continue;

                if(g[i][j] != g[t.x][t.y]){
                    if(g[i][j] > g[t.x][t.y]) high = true;
                    else  lower = true;

                }
                
                else if(!st[i][j]){
                    q[++tt] = {i  , j };
                    st[i][j] = true;
                }
            }
    }
}

int main(){
    cin>>n;
    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < n ; j ++ )
            cin>>g[i][j];

    int mo = 0 , gu = 0; //山峰和山谷数量。

    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < n ; j ++ ){
            if(!st[i][j]){
                bool high= false , lower = false;
                dfs(i, j , high , lower);

                if(!high) mo ++;
                if(!lower) gu ++;
            
            }    
        }
    cout<<mo<<"\n"<<gu<<endl;

    system("pause");
    return 0;
}


*/