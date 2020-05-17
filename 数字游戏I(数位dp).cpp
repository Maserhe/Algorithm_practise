#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std; //在区间 l 到 r 能 对 k 取模 等于零 的个数。
const int N = 40;
int f[N][10][N];
int  l  , r ,p;
int mod( int x , int y ){

    return (x%y + y)%y ;
}
int dp(int n){
    if( !n ) return 1;
    vector<int> num;

    while( n ) num.push_back( n % 10 ) , n/=10;
    int res = 0;
    int last = 0;
    for(  int i = num.size() - 1 ; i >= 0 ; i -- ){
        int x = num[i];
        for(  int j = 0 ; j < x ; j ++ ){
            res += f[i + 1][j][mod( -last, p )];
        }
        last += x;

        if(!x) res ++ ;
    }

    return res;
}
int main(){
    cin>>l>>r>>p;   
    for( int i = 0 ; i <= 9 ; i ++ ) f[1][i][i%p]++;

    for( int i = 2 ; i < N ; i ++ )
        for( int j = 0 ; j <= 9 ; j ++ )
            for( int k = 0 ; k < p ; k ++ )
                for( int x = 0 ; x <= 9 ; x ++ )
                    f[i][j][k] += f[i-1][x][mod(k-j,p)];

    cout<<dp(r)- dp(l-1)<<endl;
    

    system("pause");
    return 0;
}