#include<iostream>

using namespace std;
//筛选素数
const int N = 1e5;
int prime[N] ，cnt;
bool st[N];

void get_prime(int n){
    for(int i = 2; i < n / i; i ++ ){
        if(!st[i]){

            prime[cnt ++ ] = n;
            for( int j = i  + i  ; j <= n ; j += i ){
                st[j ]  =  true;
            }
        }

    }

}
int main(){
    int n;
    cin>>n;
    get_prime(n)；

    cnt<<cnt<<endl;


    return 0;
}

//线性筛法 , n只会被他的最小质因数 筛掉
void get_primes( int n ){
    for( int i = 2 ; i < n/ i ; i ++ ){
        if(!st[i]) prime[cnt++ ] = i;

        for( int j = 0; prime[j] < n/i ; i ++ ){ //从小到大枚举所有的素数
            st[prime[j]  * i ] =true;
            if( i % prime[j ] == 0 ) break; //prime[j ] 一定是 n的最小质因子
        }

    } 

}
