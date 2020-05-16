#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;
const int N = 35;

int f[N][N];
int l , r ;
int dp(int n){

    if(!n) return 0;
    vector<int> num;
    int length = 0;
    while( n ) {
        num.push_back( n%10 );
        n /= 10;
        length ++ ;
        }
    int res = 0;
    int last = 0;

    for( int i = num.size() - 1; i >= 0 ; i -- ){
        int x = num[i];

        for( int j = last ; j < x ; j ++ ){
            res += f[length - last][j];
        }
        if( x < last ) break;
        last = x;
        
        if(!x) res ++ ;
    }
   
    return res ;
}
int main(){
    
    cin>>l>>r;
    for( int i = 0 ; i <= 9 ; i ++ ) f[1][i] = 1;

    for( int i = 0 ; i < N ; ++i ){
        for( int j = 0 ; j <= 9 ; j ++ )
            for( int k = j ; k <= 9 ;k ++ ){
                f[ i ][ j ] += f[ i - 1 ][k];
            }
    }
    
    cout<<dp(r) - dp( l-1)<<endl;
    
    system("pause");
    return 0;
}