#include<iostream>
#include<algorithm>

using namespace std;

const  int N = 1010;
int down[N], up[N] ,  a[N];
int  n , ans; 

void dfs(int u , int su , int sd){
    if(su + sd >= ans) return;
    if(u == n ){
        ans = su + sd;
    }
    
    int k = 0 ;

    for( int i = 0 ; i < n ; i ++ ){
        while (k < su  && up[k] >= a[i]) k ++ ;
        int t  = up[k];
        up[k] = a[i];
        if(k < su) dfs(u + 1 , su , sd);
        else  dfs( u + 1 , su+1,sd);
        up[k] = t;
    }

    k= 0;
    for( int i = 0 ; i < n ; i ++ ){
        while (k < su  && down[k] <= a[i]) k ++ ;
        int t  = down[k];
        down[k] = a[i];
        if(k < sd) dfs(u + 1 , su , sd);
        else  dfs( u + 1 , su,sd + 1);
        down[k] = t;
    }



}
int main(){

    while (cin>>n , n)
    {
        for(int i = 0 ;  i < n ; i ++ ) cin>>a[i];
        ans= n;
        dfs(0,0,0);
        cout<<ans<<endl;
    }

    return 0;
}