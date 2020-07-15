#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1010;
int f[N][N];
int s[N], t[N];
int t;
int main(){
    int n , m ;//两个序列的长度
    cin>>n>>m;
    for(int i = 1 ; i <= n; i ++ ) cin>>s[i];
    for(int i = 1 ; i <= m ; i ++) cin>>t[i];
    
    for( int i = 1 ; i <= n ; i ++ ){
        for(int j = 1; j <= m ; j ++ ){
            f[i][j] = f[i- 1][j];

            if(s[i] == s[j] ){
                f[i][j] = max(f[i][j] ,1);

                for(int k = 0 ; k < j ; k ++ ){
                    if(t[k] < t[j]){
                        f[i][j] = max(f[i][j] , f[i-1][j-1] + 1);
                    }

                }
            }
        }
    }
    int res =0;
    for(int i = 0 ; i < n ; i ++ ) max(res, f[n][i]);
    cout<<res<<endl;
    return 0;
}