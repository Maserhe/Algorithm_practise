#include<iostream>
#include<unordered_map>

using namespace std;
//给出一堆数 ， 求出他们乘积 的 约数 个数之和
const int mod = 1e5;

int main(){
    int n;
    cin>>n;
    unordered_map<int,int> prime;
    while ( n-- )
    {
        int x;
        cin>>x;
        for(int i = 2 ; i < n /i ; i ++ ){
            while (x%i== 0)
            {
                x /= i;
                prime[i]++;
            }
            if( x > 1 ) prime[x]++; 
        }
    }
    int res= 1;
    for ( auto t : prime) 
    {
        res  = res * (t.second+ 1) % mod;
    }
    
    cout<<res;
    return 0;
}