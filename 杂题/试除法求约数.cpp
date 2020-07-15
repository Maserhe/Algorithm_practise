#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//试除法求所有约数 , 约数 大于 等于1的. 素数是从二开始的
vector<int> get_divisors(int n){
    vector<int> res;
    for( int  i = 1; i < n/i ; i ++ ){
        if( n % i == 0 ) {
            res.push_back(i);
            if( i != n/i ) res.push_back(n/i); //i如果等于 n/i的话 只加一个
        } 
    }
    sort(res.begin(),res.end());
    return res;

}
int main( ){

    int n;
    cin>>n;
    while ( n--)
    {
        int x ;
        cin>> x;
        auto t = get_divisors(x);
        for( auto res : t) cout<<res<<" "<< endl;
    }

    return 0;
}