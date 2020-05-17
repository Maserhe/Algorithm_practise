#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1e6 + 10;
int s[N], q[N];
int tt =0 , hh =1;
int main(){
    
    int n , m;
    cin>>n>>m;
    for( int i = 1 ;i <= n ; i ++ ) cin>>s[i] ;
    
    
    for( int i = 1 ;i <= n ; i ++ ){
        
        if(hh <= tt && i - m >= q[hh] ) hh++ ;
        
        while( hh <= tt && s[q[tt]] >= s[i] ) tt--;
        
        q[ ++ tt ] = i;
        
        if(i >= m  )cout<<s[q[hh]]<<" ";
    }
    puts("");
    
    hh = tt =1;

    for( int i = 1 ;i <= n ; i ++ ){
        
        if(hh <= tt && i - m >= q[hh] ) hh++ ;
        
        while( hh <= tt && s[q[tt]] <= s[i] ) tt--;
        
        q[ ++ tt ] = i;
        
        if(i >=  m )cout<<s[q[hh]]<<" ";
    }
    
    system("pause");
    return 0;
}