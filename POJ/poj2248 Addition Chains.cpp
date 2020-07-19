#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;// 超级剪枝

const int N = 110;
int path[N];
int n ;
bool dfs(int u , int d ){ //u代表当前深度 ， d 代表最大深度

    if( u > d ) return false;
    if( path[u - 1] == n) return true;

    bool st[110] = {0};

    for( int i = u - 1 ; i >= 0 ; i -- )
        for( int j = i ; j >= 0 ; j -- ){
            int t = path[i] + path[j];
            if( t <=  path[u - 1]  || t > n  || st[t]) continue;
            st[t] = true;
            path[u] = t; 
            if(dfs(u + 1 , d)) return true;
            path[u] = 0; //可以省掉， 因为 下次会直接被复制覆盖掉。 不用恢复现场。
        }

    return false;
}
int main(){

    while (cin>>n , n)
    {
        path[0] = 1;
        int dept = 1;

        while ( !dfs(1 , dept)) dept++; 
        for( int i = 0 ; i < dept ; i ++ ) cout<<path[i]<<" ";
        cout<<endl;
    }

    system("pause");    
    return 0;
}
