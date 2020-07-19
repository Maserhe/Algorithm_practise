#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath> 
using namespace std;// 超级剪枝

int H[25] , R[25]; //分别存储 高和半径
int ans = 1e9;  //表面积
int n , m; // 体积 和 层数
int minv[25], mins[25]; // 前i 层的最小 体积和面积 和

void dfs( int u , int v , int s){  // u 代表 当前层数（还剩下多少层没有算） ， v 已经使用过的体积 ， s已经使用过的面积、
    if( v + minv[u] > n ) return;
    if( s + mins[u] >= ans ) return; //代表当前情况已经小于 当前已经搜索到的最优解 ，直接进行剪枝
    if( s + 2*(n- v)/R[u + 1] >= ans ) return; //把剩下的 体积 全部直接 接到 上一层上面

    if(!u){
        if(n == v) ans = s;
        return;
    }
    for( int r = min(R[u + 1] - 1 ,(int)sqrt( (double)(n-v)));  r >= u ; r --){  // 这个有点坑， 使用sqrt 要自己转换成double型。不然编译不过。
        for( int h = min((n-v)/r/r, H[u+1] - 1 ); h >= u ; h -- ){
            int t = 0 ;
            R[u] = r;
            H[u] = h;
            if( u == m) t = r * r; //圆的表面积
            dfs( u - 1 , v + r*r*h ,  s + 2*r*h + t);
        }
    }
}

int main(){

    cin>>n>>m;
    for( int i = 1 ; i <= m ; i ++ ){
        minv[i] +=  i * i * i ;
        mins[i] +=  2 * i * i ;
    }
    // 需要 与 自己下面的 一层  作比较 ， 当前半径要小于 脚下一层。
   
    H[m + 1] = R[m + 1] =1e8;//初始化 一个较大值。


    dfs(m , 0 ,0 );
    if(ans == 1e9) cout<<0;
    else cout<<ans;
    system("pause");
    
    return 0;
}