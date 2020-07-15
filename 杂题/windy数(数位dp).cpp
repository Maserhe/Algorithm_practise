#include<algorithm>
#include<cstring>
#include<iostream>
#include<math.h>
#include<vector>
//不包含前导零。 相邻两个元素的差 ，不能超过 2；就是Windy数

using namespace std;

const int N = 40;
int f[N][N] ;

int l , r ;

int  dp( int n ){
    if(!n) return 0;
    vector<int> num;

    while( n ) num.push_back( n% 10 ) , n /= 10;

    int res = 0;
    int last =  -2 ;

    for( int i = num.size() - 1 ; i >= 0 ; i -- ){

        int x = num[i];
        for( int j = i == num.size() - 1 ; j < x ; j ++ )
        {
            if(fabs( j - last ) >= 2 ) 
                res += f[i+ 1][j];
            
            
        }
        if(abs(x-last) >= 2 ) last = x;
        else break;
        if(!x) res ++;
    }
    for( int i = 1 ; i <= num.size() - 1 ; i ++ )
        for( int j = 1 ; j <= 9 ;j ++ )
            res += f[i][j];

    return res;
}

int main(){

    cin>>l>>r;

    for( int i = 0 ; i <= 9 ; i ++ ) f[1][i] = 1;
    
    for( int i = 2 ; i < N ; i ++ ){
        for( int j = 0 ; j <= 9 ; j ++ ){
            for( int k = 0 ; k <= 9 ; k ++ ){
                if(fabs(j-k) >= 2 ){
                    f[i][j] += f[i-1][k];
                }
            }
        }
    }

    cout<<dp( r ) - dp( l - 1 )<<endl;
    system("pause");
    return 0;
}