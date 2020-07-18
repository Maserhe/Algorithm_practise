#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;

int n, m ;
int w[20];
int sum[20];

int ans = 0x3f3f3f3f;

void dfs(int u , int k){
    
    if( k >= ans ) return;  //最优性剪枝
    if( u == n  ){
        ans = k;
        return;
    }
    //先把小猫咪放到已有的缆车中
    for( int i= 0 ; i < k ; i ++ ){
        if( w[u] + sum[i] <= m ){
            sum[i] += w[u];
            dfs(u + 1 , k );
            sum[i] -= w[u];  //恢复现场;
        }
    }
    
    sum[k] = w[u];
    dfs(u + 1 , k + 1);
    sum[k] -= w[u]; // 恢复现场
    
}
int main(){
    
    cin>>n>>m;
    for(int i = 0 ; i < n ; i ++ )cin>>w[i];
    
    sort(w , w + n );
    reverse(w , w + n);
    
    dfs(0 , 0);
    
    cout<<ans;
    return 0;
}

/*
测试数据
5 1996
1
2
1994
12
29

输出 
2

*/