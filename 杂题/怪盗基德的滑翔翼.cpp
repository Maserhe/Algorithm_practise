#include<iostream>
#include<algorithm>
using namespace std;

const int N = 110;
int f[N], a[N];

int main(){
    int  n, m;
    while (n--)
    {
        cin>>m;

        for( int  i = 1 ;i <= m; i ++) cin>>a[i];
        int res =1;
        for( int i =  1 ; i <= m ; i ++ ){
            f[i] =1;
            for( int  j = 1; j < i ; j ++ ){

                if(a[i] > a[j]){
                    f[i] = max(f[i],f[j] + 1 );
                }

            }
            res = max( res, f[i]);
        }
        for( int i =  m ; i ; i -- ){
            f[i] =1;
            for( int  j = m; j > i ; j -- ){

                if(a[i] > a[j]){
                    f[i] = max(f[i],f[j] + 1 );
                }

            }
            res = max( res, f[i]);
        }
        cout<<res<<endl;
    }

    
    return 0;
}