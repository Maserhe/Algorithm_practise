#include<iostream>
#include<algorithm>

using namespace std;

const int N =1100;
int n , m , f[N][N] , w[N];
int main(){
    cin>>n>>m;
    for(int i =1; i<= n ; i ++ ) cin>>w[i];
    f[0][0] = 1;
    for(int i =1; i <= n ; i ++ ){
        for(int j = 0 ; j <= m ; j ++ ){
            f[i][j] = f[i -1][j];
            if(j>= w[i])  f[i][j] += f[i-1][j - w[i]];            
        }
    }
    cout<<f[n][m];
    system("pause");
    return 0 ;
}



