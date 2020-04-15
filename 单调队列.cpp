#include<iostream>

using namespace std;

//1，hh =0 , tt =-1;
//2，进队  q[ ++ tt ];
//3, 弹出  hh ++ 
//4, 是否为空  if(hh > tt )  empty
//5，取出头 q[ hh ] 
//6，取出尾 q[ tt ]

const int N= 1e6 + 10;

int q[N], hh, tt = -1;
int a[N];

int main(){
    
    int n,m;
    scanf("%d%d", &n,&m);
    for(int i = 0; i < n ; i ++ ) scanf("%d", &a[i]);
    
    for(int i = 0; i < n ; i ++ ) {
        
        if(hh <= tt && i - m + 1  > q[hh] ) hh++; 
        
        while(hh <= tt && a[q[tt]] >= a[i])  tt--;
        q[ ++tt ] = i;
        
        if(i >= m - 1) printf("%d ",a[q[hh]]);
    }
    
    puts(" ");
    hh = 0; tt = -1;
    for(int i = 0; i < n ; i ++ ) {
        
        if(hh <= tt && i - m + 1  > q[hh] ) hh++; 
        
        while(hh <= tt && a[q[tt]] <= a[i])  tt--;
        q[ ++tt ] = i;
        
        if(i >= m - 1) printf("%d ",a[q[hh]]);
    }
    
    puts(" ");
    
    
    return 0;
}