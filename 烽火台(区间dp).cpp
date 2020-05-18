#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 10010;
int n, m;
int w[N];
int f[N];
int q[N];

int main(){

    cin>>n>>m;
    for( int i = 1 ;i <= n ;i ++ ) cin>>w[i];

    int hh = 0;
    int tt = 0;
    
    for( int i = 1 ;i <= n ;i ++ ){

        if(q[hh] < i - m ) hh++ ;
         
        f[i] +=  f[q[hh]] + w[i];

        while ( hh <= tt && f[q[tt]] > w[i] ) tt --;

        q[++tt] = w[i];

    }
    int res = 1000000000;
    for( int i = n - m +  1 ; i <= n ;i ++ ) res = min(res ,f[i]);
    cout<<res;
    
    system("pause");
    return 0;
}
/*
输入
5 3 
1 2 5 6 2
输出
4

*/