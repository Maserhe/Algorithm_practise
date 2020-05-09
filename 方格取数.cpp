#include<iostream>
#include<algorithm>
using namespace std;

const int N =15;
int w[N][N];

int f[N*2][N][N];
int a , b , c;

int main(){
    int n;
    cin>>n;

    while (cin>>a>>b>>c && a||b||c) cin>>w[a][b];

    for( int k =2 ; k <= n*2 ; k++ ){
        for( int i1= 1; i1 <= k ; i1++)
            for(int i2 = 1 ; i2 <= k ; i2 ++ ){
                int j1 = k -i1 ;
                int j2 = k - j2;
                if(j1>0 &&j2>0 && j1<=n && j2<=n){
                     int t = w[i1][k-i1];
                    if(i1 != i2 ) t+=  + w[i2][k-i2];
                    int &x = f[k][i1][i2];
                    x= max(x  , f[k-1][i1][i2] +  t);
                    x=max(x,f[k-1][i1-1][i2] + t);
                    x= max(x, f[k-1][i1][i2-1] + t);
                    x= max(x , f[k-1][i1-1][i2-1] + t);
                }
            }
    }
    cout<<f[n*2][n][n];
    return 0;
}