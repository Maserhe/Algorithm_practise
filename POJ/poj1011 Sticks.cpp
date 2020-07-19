#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 100;
int val[N] ;
int n , cnt , len , sum;
bool st[N];     // 记录是否使用
bool dfs( int u , int v , int start ){  // 表示使用到了 u 个 小木棍 ， 当前 木棍 剩余长度 为 v ， 枚举到了 第 w 个 小木棍

    //递归 出口 
    if( u == cnt ) return true;
    if( v == len ) return dfs( u + 1 , 0 , 0 ); // 如果当前木棍 填充满

    for( int i = start ; i < n ; i ++ ){
        if( val[i] + v > len ) continue; // 可行性 剪纸
        if( st[i]) continue;
        
        st[i] = true;
        if( dfs( u , v + val[i] , i + 1) ) return true;
        st[i] = false; // 恢复现场
        
        
        if(!v) return false;               //说明没放进去 
        if( v + val[i] == len ) return false; //说明没放成功
        
        
        // 相同情况剪枝
        int j = i + 1;
        while( val[i] == val[j] && j < n) j ++;
        i = j - 1;

    }
    
    return false;
}
int main(){

    while ( cin>> n , n)
    {   
        sum = 0 ;
        for( int i = 0 ; i < n ; i ++ )
        {
            cin>>val[i];
            sum += val[i];
        }
        sort( val, val + n);
        reverse( val , val + n);

        
        for( len = val[0]; len < sum ; len ++ ){
            if( sum%len  ) continue;
            cnt = sum / len;
            memset(st , 0 , sizeof st);
            if(dfs(0 , 0 , 0 )) break;
        }
        cout<<len<<endl;
        
    }
    
    system("pause");
    return 0;
}