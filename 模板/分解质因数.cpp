#include<iostream>

using namespace std;

// n中最多包含一个 大于n 的 质数  O(sqrt(n))

void divide( int x){
        int res= 0;
        for(int i = 2; i < x/i ; i ++ ){
            
            if( x % i == 0){
                while( x % i == 0 ){
                    x /= i;
                    res++;
                }
            printf("%d  %d \n", i , res );

          }
      }
      if(x >1 ) printf("%d  %d \n", x , res+1 );
}


int main(){

    system("pause");
    return 0;
}