#include<iostream>

using namespace std;

const int N = 10;
int n;

bool col[N],row[N],dg[N],udg[N];

char queen[N][N];
void dfs(int x ,int y ,int s){
    if(y==n) {
        y=0;
        x++;
    }

    if(x==n){
        if(s==n){
            for(int i = 0 ; i < n; i ++ ) puts(queen[i]);
            puts(""); 
        }
        return;
    }
    //不放皇后
    dfs(x,y+1,s);
    //放皇后
    if(!col[x]&&!row[y]&&!dg[x+y]&&!udg[x-y+n]){

        queen[x][y]='Q';

        col[x]=row[y]=dg[x+y]=udg[x-y+n] = true;

        dfs(x,y+1,s+1);

        col[x]=row[y]=dg[x+y]=udg[x-y+n] = false;

        queen[x][y]='.';


    }




}

int main(){
    cin>>n;
    for(int i = 0 ; i < n ; i ++ ){
        for(int j = 0 ; j < n ; j ++ ){

            queen[i][j]='.';
        }
    }

    dfs(0,0,0);

    system("pause");

    return 0 ;
}