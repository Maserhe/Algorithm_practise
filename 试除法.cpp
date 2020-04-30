#include<iostream> 
using namespace std;

bool is_prime(int  x){   //判断一个数是否是素数

    if( x < 2) return false;
    for( int i = 2 ; i < x/i; i ++ ){
        if( x % i == 0 ) return false;
    }
    return true;
}
