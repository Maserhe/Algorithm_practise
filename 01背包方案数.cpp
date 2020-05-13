#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010 , mod = 1e9+ 7;
int f[N] , g[N];

int main(){
    int n, m;
    cin>>n>>m;
    for( int i = 0 ; i < m ; i ++ ) g[i] = 1;
    while( n-- ){
        
        int a , b;
        cin>>a>>b;
        for( int j = m ; j >= a ; j -- ){
            
            if( f[j] == f[j- a] +b ){  //当前体积数 
                g[j] = (g[j] + g[j -a ]) %mod;
               
            }
            else if(f[j] < f[j- a] +b ){
                f[j] = f[j - a] +b ;
                g[j] = g[ j - a ];   
                
            }
        }
    }
    cout<<g[m]%mod;
    
    return 0;
}

