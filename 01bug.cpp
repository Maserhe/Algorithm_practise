#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1000;
int f[N][N];
int v[N],w[N];

int main(){
    int n , m; //n 种为物品 ， 最大提及不超过 m;
    cin>>n>>m;

    for(int  i = 1 ; i <= n ; i++ ) cin>>v[i]>>w[i];

    //是 f[0][0~m] 全部 默认为 0;
    //全局 变量 不需要设置

    for( int i = 1 ; i <= n ; i ++ ){  
        for(int j = 0 ; j <= m ; j ++ ){

            f[i][j] = f[i -1] [j];
            if(j >= v[i]) f[i][j] = max(f[i][j],f[i-1][j - v[i]] + w[i]);
        }

    }
    cout<<f[n][m]<<endl;
    system("pause");
    return 0;
}
/*输入

4 5 
1 2
2 4
3 4
4 5

输出
8
*/