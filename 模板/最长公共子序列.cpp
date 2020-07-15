#include<iostream>
#include<algorithm>
using namespace std;
const int N = 410;
int n , m ; // 第一和二 个 子序列 的长度

//最长 公共 子序列  
char s[N],t[N];
int f[N][N];
int main(){
    
    scanf("%d%d%s%s",&n,&m, s+1, t+1);

    for( int i = 1 ;i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ ){
            f[i][j] = max( f[i -1 ][j] , f[i][ j -1 ]);
            if(s[i]== t[j]){
                f[i][j] = max(  f[i][j], f[i -1 ][j -1] + 1);
            }  
        }
    cout<<f[n][m];
    system("pause");
    return 0;
}
