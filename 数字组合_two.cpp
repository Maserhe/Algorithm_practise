#include<iostream>
#include<algorithm>

using namespace std;

const int N =10010;
int n , m , f[N];  //使用滚动数组进行优化。
int main(){
    f[0] = 1;
    cin>>n>>m;
    for(int i = 0 ; i < n ; i++ )
    {
        int v ;
        cin>>v;
        for(int j = m; j >= v ; j -- )
            f[j] += f[j -v];
    }
    
    cout<<f[m];
    return 0 ;
}
