#include<iostream>
#include<algorithm>

using namespace std; //最大上升子序列
const int N = 410;

int f[N], a[N];

int n ;
int main(){
    cin>>n;
    for(int i= 1 ; i <= n ; i ++ ) cin>>a[i];

    for( int i =1 ; i <= n ; i ++ ){
        f[1] = 1;
        for( int j = 0 ; j <i ; j  ++ ){
            if(a[j] < a[i]){
                f[i] = max( f[i ] , f[j] + 1);
            }
        }

    }
    int res = 0;
    for( int i =1 ; i <= n ; i ++ ) res = max( res , f[i]); 
    cout<<res;
    system("pause");
    return 0;
}