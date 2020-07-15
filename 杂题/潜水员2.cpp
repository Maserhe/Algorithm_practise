#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100 ,V =100 , W = 100; // 罐 氧气 氮气
int f[V][W] ;

int main(){
    int  A, B , n;
    cin>>A>>B>>n;
    memset( f , 0x3f, sizeof f);
    f[0][0] = 0;

    while (n -- )
    {
        int a, b , w;
        cin>>a>>b>> w;
        for( int i = A; i >= 0; i -- ){   
            for( int j = B; j >=0; j --)
                f[i][j] = min( f[i][j] , f[max( 0 , i -a )][max( 0 , j - b )] + w ); 
        }       
    }
    cout<<f[A][B];
    

    system("pause");
    return 0;
}
/*

for (int i = 0; i < n; i++) {
    for (int j = A; j >= 0; j--) {
        for (int k = B; k >= 0; k--) {
            f[j][k] = min(f[j][k], f[max(0, j - a[i])][max(0, k - b[i])] + w[i]);
        }
    }
}
5 60 5
3 36 120
10 125 129
5 50 250
1 45 130
4 20 119


249

*/

