#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;
typedef long long LL;
const LL N = 47;
typedef long long LL;
LL n , v , k ;
LL w[1<<25] , cnt ;
LL g[N];
LL ans;
void dfs1( LL s , LL e ){   // 枚举到 第 s 项 ， 当前和 为 e
    
    if( s == k ){
        w[cnt ++ ] = e;
        return;
    }

    dfs1( s + 1 , e ); // 不选 这个值
    //选择 ，当前点。
    if(e + g[s]  <= v ) dfs1( s + 1 , e + g[ s ]); 

    
}
void dfs2(LL s , LL e){
    if( s == n ){
        //此时说明已经迭代完了
        LL l = 0 , r = k  - 1;
        
        while ( l < r )
        {
            LL mid = l + r + 1>> 1;
            if (e +  w[mid] > v ) r = mid - 1;
            else l = mid;
        }
        ans = max(ans , e + w[l]);
        return;
    }

    dfs2( s + 1 , e );  //不旋转当前项

    if(e + g[s]  > v ) return ; // 剪枝 , 如果当前值都已经大于 最大承重
    dfs2( s + 1 , e + g[ s ]);

}
LL main(){

    cin>>v>>n;
    for( LL i = 0 ; i < n ; i ++ ) cin>>g[i];
    k = n / 2 ;

    sort( g , g + n );
    reverse( g , g  + n );

    dfs1( 0 , 0 );
    

    // 对 w[i] 进行排序 优化搜索顺序
    sort( w , w + cnt );
    k = unique( w , w + cnt ) - w;  
    dfs2( n/2  , 0 );
   
    cout<<ans;
    system("pause");
    return 0;
}