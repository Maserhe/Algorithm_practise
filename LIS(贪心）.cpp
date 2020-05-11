//时间复杂度 O(nlgn)

#include<iostream>
#include<algorithm>

using namespace std;

const int N =1000;
int g[N] , a[N];

int n ;
int main(){

    cin>>n;
    for(int i = 0; i< n ; i ++ ) cin>>a[i];
    int res = 0; //记录答案
    for( int i = 0 ; i < n ; i ++ ) //从前往后 遍历 一遍 数组
    {
        int k = 0 ;
        while ( k < res && g[k] >a[i] ) k++ ; //找到序列中最小的 大于当前值最小 的 一个元素
        g[k] = a[i]; //进行替换
        if(k >= res) res++ ;
    }
    
    cout<<res;
    return 0;
}