#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int g[8][7] = {  //用于记录每种情况的下标
    { 0, 2 ,6 , 11 , 15 , 20 , 22 },
    { 1, 3 ,8 , 12 , 17 , 21 , 23 },
    { 10 , 9 , 8 , 7 , 6 , 5 , 4 },
    { 19 , 18 , 17 , 16 , 15 , 14 ,13 },
    { 23 , 21 , 17 , 12 , 8, 3 ,1 },
    { 22 , 20 , 15 , 11 , 6 , 2 , 0 },
    { 13 , 14 , 15 , 16 , 17 , 18 , 19 },
    { 4 , 5 , 6 , 7 , 8 , 9 , 10 }
};
int opposite[8] = { 5 , 4 , 7 , 6 , 1 , 0 , 3 , 2 };
int center[8] = { 6 , 7 , 8 , 11 , 12 , 15 , 16 , 17 };
int path[100]; // 用于记录路径
int start[25]; // 存储 开始数据
int cnt;

int count(){  // 估价函数

    int c[4] = {0};
    for( int i = 0 ; i < 8 ; i ++ ) c[ start[center[i]] ] ++ ;  //用于记录 中间 八个值 的 情况。
    
    return  8 - max( max( c[1] , c[2]) , c[3]);

}
void mov( int x ){  // 移动第 x 列

    int t = start[ g[x][0]] ;  //记录 第 x 列的首元素
    for( int i = 0 ; i < 6 ; i ++ )
        start[g[x][i]] = start[g[x][i + 1]];
    start[g[x][6]] = t; 

}
bool dfs( int s , int e , int last ) // 当前迭代， 最大迭代 ， 上一次迭代的 步骤
{
    if( count() + s > e) return false;
    if( count() == 0 ) return true;
    
    for( int i = 0 ; i < 8 ; i ++ ){
        if( opposite[i] == last ) continue;
        
        mov(i);
        path[s] = i;
        if(dfs( s + 1 , e , i ) ) return true ;
        mov(opposite[i]);
       
    }
    return false;
}
int main(){

    
    while ( cin>> start[0] , start[0])
    {
        for( int i = 1 ; i < 24 ; i ++ ) cin>>start[i];
       

        int dept = 0;
        while ( !dfs( 0 , dept , -1 ) ) dept ++ ;

        if( dept) {
            for( int i = 0 ; i  < dept ; i ++ )
                printf("%c", path[i] + 'A');
            cout<<endl;
            cout<<start[6]<<endl;
        }
        else {
            cout<<"No moves needed"<<endl;
            cout<<start[6]<<endl;
        }
    }

    system("pause");
    return 0;
}