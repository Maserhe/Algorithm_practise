#include<iostream>
#include<algorithm>

// LIS问题

using namespace std;

const int N = 1010;
int a[N], f[N], g[N];

int main(){

    int n;
    cin>>n;
    for(int i = 1; i <= n; i ++ ) cin>>a[i];

    for(int i =1 ; i <= n ; i ++ ){
        f[i] = 1;
        for( int j = 1 ; j < i  ; j ++ ){
            if(a[i] > a[j]){
                f[j] = max( f[j] , f[i] + 1);
            }
        }
    }
    for(int i =n ; i  ; i -- ){
        g[i] = 1;
        for( int j = n ; j > i  ; j -- ){
            if(a[i] > a[j]){
                g[j] = max( g[j] , g[i] + 1);
            }
        }
    }
    int res= 1;
    for( int i = 1 ;i <= n ; i++ ) res= max(res,f[i] + g[i] -1);
    cout<<res;
    return 0;
}