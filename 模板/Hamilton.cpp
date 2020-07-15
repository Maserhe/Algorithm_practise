#include<iostream>
#include<cstring>

using namespace std;

const int M = 1<<20;
const int N= 20;
int n , f[M][N];
int a[N][N];
int main(){
    cin>>n;
    for( int i = 0 ; i < n ; i++  )
        for( int j = 0 ;j < n ; j ++ )
            cin>>a[i][j];   
            
    memset( f, 0x3f , sizeof f) ;
    f[1][0] = 0;
    for( int i =0 ; i<1<< n ;i ++ )
        for( int j =0 ; j < n ;j ++ )
               if( i >>j & 1) //走到第j个点
                   for( int k = 0; k < n ;  k ++ ) //假设是由第k个状态转移过来的
                        if((i - ( 1<<j)) >> k & 1)  //j 和k不能相同

                            f[i][j] = min( f[i][j] , f[i - (1 <<j)][k] + a[k][j]);  //不包括第j个点转移过来
                       
    cout<<f[(1<<n)-1][n-1];
    system("pause");
    return 0;
}
/*输入
5
0 2 4 5 1
2 0 6 5 3
4 6 0 8 3
5 5 8 0 5
1 3 3 5 0

输出18
*/
