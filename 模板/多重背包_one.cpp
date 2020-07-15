#include<iostream>
#include<algorithm>
using namespace std;

const int N = 110;

int f[N][N];

int n , m ; //这是朴素算法
int v[N], w[N], k[N];  //容积 ， 权重 ， 最大数量 

int main(){
    
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; i ++ ) scanf("%d%d%d", &v[i],&w[i],&k[i]);
    
    for(int i =1 ; i <= n ; i ++ )
        for(int j  = 0 ; j <= m ; j ++ )
            for(int s = 0 ; s <= k[i]&& s*v[i]<= j ; s++ )
                f[i][j] = max(f[i][j], f[i - 1 ][ j - s* v[i]] + s*w[i] );
    
    cout<<f[n][m]<<endl;
    
    return 0;
}
