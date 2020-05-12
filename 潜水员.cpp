//二维背包，潜水员问题

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N  = 60 , M = 100;

int f[N][M]; //代表氧气， 氮气 恰好为 N , M 时最小的重量
/*从文本文件gas.in中读入数据。 
 第一行有2整数t，a（1<=t<=21，1<=a<=79）
 。它们表示氧，氮各自需要的量。  
 第二行为整数n （1<=n<=1000）表示气缸的个数。
 此后的n行，每行包括
ti，ai，wi（1<=ti<=21，1<=ai<=79，1<=wi<=800）3整数。
这些各自是：第i个气缸里的氧和氮的容量及汽缸重量。 */
int main(){
    memset(f, 0x3f,sizeof f);  
    f[0][0] = 0; 
    int  O , N , n;
    cin>>O>>N>>n;
    int o , n2 , w; //氧气 ， 氮气 ， 重量
    for( int i = 1; i <= n ; i ++ ){
        cin>>o>>n2>>w;
        for(int j =N-1 ; i>=o ; i -- ){ //数组下表最多是 N-1
            for( int k = M- 1 ; k >=n2 ; k -- ){
                f[j][k] = min(f[j][k] , f[j - o][k - n2 ] + w );
            }
        }
    }
    int res = 0x3f3f3f3f;
    for(int i = O ; i <= N - 1 ; i ++ )
        for( int j = N ; j <= M - 1 ; j ++ )
            res = min(res, f[i][j]);


    cout<<res;
    return 0;
}



