#include<iostream>
#include<cstring>
using namespace std;


//蒙德里安 的梦想 
const long long  M= 1<<12 , N = 12 ;
int n , m;

long long  f[N][M];
bool st[M];

int main(){
    
    while( cin>>n>>m &&( n || m )){
        memset(f , 0 , sizeof f );
        for(int i = 0; i < 1<<n ; i ++  ){
            int cnt = 0 ;
            st[i] = true;
            for( int k = 0 ;k < n ;k ++ ){
                if( i >> k &1 ){
                    if( cnt &1) st[ i ] = false ;
                    cnt = 0;
                }        
                else cnt ++ ;
            }
            if(cnt& 1) st[i] = false;
            
        }
         
        f[0][0] = 1;
        for( int i  = 1 ; i <= m ; i ++ )  //因为有 i-1 所以从 开始
            for( int j =0 ; j < 1<<n ; j++ )
                for( int k = 0 ; k < 1<<n ; k ++ )
                    if((j&k) == 0&& st[j|k] ) 
                        f[i][j] += f[i -1][k];
        
        
        
    cout<<f[m][0]<<endl; 
        
    }
    return 0;
}