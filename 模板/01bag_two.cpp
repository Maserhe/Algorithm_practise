#include<iostream>
using namespace std;

const int N = 1000;

int f[N];
int n , m;
int v[N], w[N];

int main(){  //优化后的 01 背包问题

    cin>>n>>m;
    for(int i = 1 ;  i <= n ; i ++ ) cin>>v[i]>>w[i];

    for(int i = 1 ; i  <= n ; i ++ )
        for( int j = m ;  j >= v[i] ; j -- )
            f[j] = max(f[j] , f[j-v[i]]+ w[i]);

    cout<<f[m]<<endl;
    system("pause");
    return 0;
}
/*输入

4 5 
1 2
2 4
3 4
4 5

输出
8
*/