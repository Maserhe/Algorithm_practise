#include<iostream>
#include<algorithm>

using namespace std;

const int N = 300010;  //滑动窗口进行优化

int s[N];
int q[N];
int hh = 0, tt=0;

int main(){
    int n, m;
    cin>>n>>m;
    int t;

    for( int i = 1 ; i <= n ; i ++ ){
        cin>>t;
        s[i] += s[i-1] + t;
    }
   int res =-0x3f3f3f3f;
   for( int i  = 1 ; i <= n ;i ++ ){
       
       if(q[hh] < i - m ) hh++;
       res = max( res , s[i] - s[q[hh]] );
       while( hh<= tt && s[q[tt]] >= s[i]) tt -- ;
       q[ ++ tt ] = i;
       
   }
    cout<<res;
    
    system("pause");

    return 0;
}
