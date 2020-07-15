#include<iostream>
#include<algorithm>

using namespace std;
/*
动态规划
*/
const int N =100;
int f[N][N] ;

int main(){

    int n , V ,W ;
    cin>>n>>V>>W;
    
    for(int i = 0 ; i < n ; i ++ ){
        int a , b , c;  //体积、重量和价值。
        cin>>a>>b>>c;

        for(int j = V; j >=a ; j--){
            for(int k = W ; k>=b ; k--){

                f[j][k] = max(f[j][k] , f[j-a ][k-b] + c);
            }
        }

    }

    cout<<f[V][W];
    system("pause");
    return 0;
}