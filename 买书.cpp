/*买书*/

#include<iostream>
#include<algorithm>

using namespace std;

const int N =1010;
int f[5][N];

int n ;
int main(){ //书的价格为 10 ， 20 ， 50 ，100 ；
    int a[5] = {0,10, 20 , 50 , 100 };

    while (cin>>n ,n )
    {
        
        f[0][0] = 1;
        for( int i =1 ; i <= 4 ;i ++ )
            for( int j = 0; j <= n; j ++ )
               for(int k = 0 ; k*a[i] <= j; k++)
                    f[i][j] +=f[i-1][j-k*a[i]];
        cout<<f[4][n]<<endl;   
    }
    system("pause");
    return 0;
}
//进行优化后的情况
/*
    while (cin>>n ,n )
    {
        
        f[0][0] = 1;
        for( int i =1 ; i <= 4 ;i ++ )
            for( int j = 0; j <= n; j ++ )
               f[i][j] = f[i-1][j] + f[i-1][j-v]; 
        cout<<f[4][n]<<endl;   
    }

 */

