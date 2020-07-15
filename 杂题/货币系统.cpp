#include<iostream>
#include<algorithm>

using namespace std;

const int N = 3010;

int f[N]; //求方案数， 完全背包求方案数
int main(){

    int n , m;
    cin>>n>>m;
    f[0] = 1;
    for( int i = 0 ; i < n ; i ++ ){
        int e;
        cin>>e;
        for( int j = e ; j <= m ; j ++ ){
            f[j]  = f[j] + f[j- e];

        }
    } 

    cout<<f[m];
    system("pause");
    return 0;
}