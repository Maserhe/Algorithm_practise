#include<iostream>
#include<algorithm>

//LIS问题变形
using namespace std;
const int N =1010;
int n , f[N] , a[N];

int main(){

    cin>>n;

    for(int i = 0 ; i <  n ;  i ++ ) cin>>a[ i ];

    int res = 0;
    for( int i = 0; i < n ; i ++ ){
        f[i] = a[i] ;
        for( int j = 0 ; j < i ; j ++ ){

                if(a[i] > a[j] ){

                    f[i] = max( f[i] , f[j] + a[i]);

                }
        }
        res = max(res, f[i]);
    }
    cout<<res;
    return 0;
}
