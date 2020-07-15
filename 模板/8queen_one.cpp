#include<iostream>

using namespace std;

const int N= 10;

char queen[N][N];

bool col[N], dg[N], udg[N];

int n;

void dfs(int x){
    if(x == n){
        for(int i = 0 ; i < n ; i ++ ){
            for(int j = 0 ; j < n ; j ++ ){
                cout<<queen[i][j];
            }
            puts("");
        }
        puts("");
        return;
    }
    for(  int i = 0; i < n ; i ++ ){
        if(!col[i]&&!dg[x+i]&&!udg[n-x+i]){

            queen[x][i] = 'Q';

            col[i]=dg[x+i]=udg[n-x+i] = true;

            dfs(x+1);

            col[i]=dg[x+i]=udg[n-x+i] = false;

            queen[x][i] = '.';

        }


    }

}

int main(){

    cin>>n;
    for(int i= 0 ; i < n ; i ++ ){
        for( int j = 0 ; j < n ; j ++ ){
            queen[i][j]= '.';
        }
    }


    dfs(0);

    system("pause");
    return 0;
}