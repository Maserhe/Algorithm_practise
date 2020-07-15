#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef pair<int,int> PII;

const int N= 110;

int g[N][N];
int a[N][N];

PII q[100];
int  n , m;

int BFS(){
    memset(a,-1,sizeof a);

    int hh = 0, tt =0;

    q[0] = {0,0};

    while (hh<= tt)
    {
        PII t = q[hh++];
        int r[4] = {1,0,-1,0};
        int l[4] = {0,1,0,-1};

        for(int i = 0; i <  4 ; i++ ){
            int x = t.first + r[i];
            int y = t.second + l[i];

            if(x>0&&y>0&&x<n&&y<m&&a[x][y]==-1&&g[x][y] == 0){
                a[x][y] = a[t.first][t.second] + 1;
                q[ ++tt ] =  {x,y};

            }

        }
        return a[n-1][m-1];

    }



}

int main(){

    cin>>n>>m;
    for(int i = 0 ; i < n ; i ++ ){
        for(int j = 0 ; j < m; j ++ ){
            cin>>g[i][j];
        }
    }
    cout<<BFS();

    system("pause");
    return 0;
}
//输入样例 输出为8,为最短路径
/*
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
*/