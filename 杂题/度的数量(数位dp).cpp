#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
const int N = 35;

int f[N][N];
int l , r , k, b;
 
int dfs(int x ){

    if(! x ) return 0;
    vector<int> num;

    while( x ){
        
        num.push_back( x%b );
        x/= b; 
    }
    int last = 0;
    int res = 0;

    for( int i = num.size()- 1 ; i >= 0 ; i -- ){
        int t = num[i];

        if( t ){
            
            res += f[i][ k - last ];

            if( t > 1 ) {

                if(  k - last - 1 >= 0 )  res += f[i][k - last -1 ];
                break;
            }

            else {
                last ++ ;
                if( last > k ) break;
            }

        }
        if( !i && res == k ) res ++  ;
    }

    return res;
}
void init(){
    for( int i = 0 ; i <= N ; ++ i ){
        for( int j = 0 ; j <= i ; j ++ ){
            if( !j ) f[i][j] = 1;
            else f[i][j] = f[i - 1 ][j] + f[i-1][j-1];
        }
    }

}
int main(){

    init();
    cin>>l>>r>>k>>b;

    cout<<dfs(r) - dfs( l - 1 )<<endl;
    system("pause");
    return 0;
}

/*
489199
894799999
15
3
*/