#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;

const int N = 20;
int f[N][10];
int l , r;
int dp(int n){
    if(!n ) return 1;
    vector<int> num;

    while( n ) num.push_back( n % 10 ) , n/= 10;
    int res = 0 ;
    int last = 0;
    for( int i = num.size() - 1 ; i >= 0 ; i -- ){
        int x = num[i];
        for( int j = 0 ; j < x ; j ++ ){
            if(  j == 4 ||  last == 6 && j== 2 ) continue;
            
            res += f[ i + 1 ][j];

        }
        if(  x == 4 || last == 6 && x== 2 ) break;
        last = x; 
        if(! i) res ++ ;
    }
    return res;
}
int main(){
    
    cin>>l>>r;

    for( int i = 0 ; i <= 9 ; i ++ ) f[1][i] = 1;
    f[1][4] = 0;

    for( int i = 2 ; i  < N ; i ++ ){
        for( int j = 0 ; j <= 9 ; j ++ ){
           if( j == 4 ) continue ;
           for( int k = 0 ; k <= 9 ; k ++ ){
               if( k == 4 || j==6 && k == 2) continue;
               f[i][j] += f[i-1][k];
           }
        }
    }    

    cout<<dp(r) - dp(l-1) ;

    system("pause");
    return 0;
}
/*
8654
31058
*/