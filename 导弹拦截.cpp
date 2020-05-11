#include<iostream>
#include<algorithm>

using namespace std;
const int N = 10010;
int g[N] ,f[N] ,a[N] , n;

//Dilworth定理
//一个序列 的 最大上升子序列  的 个数 等于最大下降子序列的个数

int main(){

    while(cin>>a[n]) n++;

    int res= 0;
    for( int i= 0 ; i < n ; i ++ ){
        f[i] = 1;
        for( int j  = 0; j < n ; j ++ ){
            if(a[i] >= a[j]){
                f[i] = max(f[i] , f[j] + 1);
            }
        }
        res= max(res, f[i]);
    }
    int reb;
    for( int i= 0 ; i < n ; i ++ ){
        g[i] = 1;
        for( int j  = 0; j < n ; j ++ ){
            if(a[i] < a[j]){
                g[i] = max(g[i] , g[j] + 1);
            }
        }
        reb= max(reb, g[i]);
    }

    return 0;
}