#include<iostream>
#include<algorithm>

using namespace std;
//就是一个完全背包问题
/*  //最下面是进行优化后的代码
const int N = 1010;
int f[N][N] , v[N] , w[N] , k[N];
int main(){
    int n, V;
    cin>>n>>V;
    for(int i = 1 ; i <= n ;i ++ )cin>>v[i]>>w[i]>>k[i];

    for(int i= 1 ; i <= n ; i ++ ){
        for(int j = 0 ; j <= V ; j ++ ){
            for( int s = 0 ; s* v[i] <= j&&s<=k[i] ; s++ )
                f[i][j] = max( f[i][j] , f[i-1][j- s*v[i]] + s*w[i]);
        }
    }
    cout<<f[n][V];
    system("pause");

}*/
/*
5 1000
80 20 4
40 50 9
30 50 7
40 30 6
20 20 1

*/
//进行优化 , 使用二进制进行优化

const int N = 25000;
int f[N] , n , m;
int v[N],w[N];
int main(){
    int idx= 1;
    cin>>n>>m;
    while (n--)
    {
        int a , b , c; //价钱 价值 数量 
        cin>>a>>b>>c;
        int t =1;
        while ( t<=c)
        {
            
            v[idx] = t*a;
            w[idx] = t*b;
            idx++;
            c-= t;
            t*=2;
        }
        if(c>0){
            
            v[idx] = c*a;
            w[idx] = c*b;
            idx++;
        }
    }
    
    for(int i = 1; i <= idx ;i ++ ){
        for(int j = m ;j >=v[i] ; j -- )
            f[j] = max(f[j] , f[j -v[i]] +  w[i]);
    }

    cout<<f[m];
    system("pause");
    return 0;
}

