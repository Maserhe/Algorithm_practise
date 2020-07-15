#include<iostream>
#include<algorithm>
using namespace std; //将多重背包 划分成  01背包

const int N =  25000;   //使用二进制进行优化  

int f[N], n ,m  ;
int v[N], w[N];
int main(){ 
    
    cin>>n>>m;
    int cnt =0;
    for(int i= 1 ; i <= n ; i ++ ){
        int a, b ,s;
        cin>>a>>b>>s;
        int k = 1;
        
        while(k<=s){
            cnt++;
            v[cnt] = a*k;
            w[cnt] = b*k;
            s-= k;
            k*=2;
        }
        if(s>0){
            cnt++;
            v[cnt] = a*s;
            w[cnt] = b*s;
        }
    }
    for( int i = 1 ; i <= cnt ; i ++ )
        for(int j = m ; j >=v[i] ; j -- )
            f[j] = max(f[j], f[j-v[i]]+w[i]);
    cout<<f[m];
    return 0;
}
