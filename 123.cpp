#include<iostream>
using namespace std;

//容斥原理
//能被整除的数
const int N  = 1000;
int p[N] ;
int n,m;

int main(){
    cin>> n>>m;
    int res= 0;
    for( int i = 0 ; i < m ; i ++ ) cin >>p[i];

    for( int i = 1 ; i < 1<< m ; i ++ ){
        int t = 1 , cnt= 0;

        for(int j = 0 ; j < m ; j ++ ){

            if(i >>j & 1 ){
                if(t * p[i] > n ){
                   t = -1;
                   break;
                }
                cnt++;
                t *= p[j];
            }

        }
        if(cnt % 2 ) res += n/ t;
        else res -= n/ t; 
    }
    cout<<res;
    system("pause");
    return 0;
}
/*
输入
10 3
2 5 7

输出 7

*/