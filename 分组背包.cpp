#include<iostream>
#include<algorithm>
using namespace std;

const int N = 110;

int v[N][N] , w[N][N],s[N];
int n , m,f[N];
int main(){
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i ++ ){
        
         cin>>s[i];
         for( int j = 0 ; j < s[i]; j ++ ){
             cin>>v[i][j]>>w[i][j];
         }
    }
    
    for( int i = 1 ; i <= n ; i ++ )  //枚举 每一组
        for( int j = m ; j >= 0; j--)  //枚举 所有 体积 ， 从大到小
            for(int k =0 ; k <s[i] ; k ++ ) //枚举 所有 选择
                if(v[i][k]<=j)
                    f[j] = max(f[j] , f[j - v[ i][k]] + w[i][k]);
    cout<<f[m];

    system("pause");
    return 0;
}