#include<iostream>

using namespace std;

const int N = 10010;

int a[N];

int stk[N], tt;

//栈的一些基本操作
//1，插入 stk[ ++ tt ]  =  x ;
//2, 弹出 tt -- ;
//3，栈顶元素  stk[ tt ]
//4,是否为空  if( tt > 0)  not empty 
int main(){
    // 输入 5
    // 3 4 2 7 5 
    int n;
    cin>>n;
    for(int i =0 ;i < n ; i ++ ) scanf("%d",&a[i]);
    
    for( int i = 0 ; i < n ; i ++ ){
        while(tt && stk [ tt ] >= a[i]) tt--; // 只要下一个 元素 比他 更小 就出栈

        if(tt) cout<<stk[tt]<<" ";
        else cout<<-1;              

        stk[ ++ tt ] = a[i]; //更优秀的直接压入栈内
    }



    system("pause");
    return 0;
}