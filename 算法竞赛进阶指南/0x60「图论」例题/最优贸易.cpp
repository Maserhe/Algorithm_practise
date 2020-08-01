#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;

int n , m ;
const int N = 200010 , M = N * 2;
int dist[N]; // 存每个城市的 水晶球的价格
int MIN[N] , MAX[N];
bool st[N];
int hs[N] , he[N] , w[N] , e[N] , ne[N] , idx ;

int q[N];   //数据范围比较大，手写队列了。

void add( int h[] , int a ,int b ){
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ; 
}

void spfa( int h[] , int type ){    //type == 0 求 最小值 ， type == 1 求最大值

    memset( st , 0 , sizeof st );
    if( type ){
        memset( MAX , -0x3f , sizeof MAX );
        MAX[n] = dist[n];
        q[0] = n;       //队列首元素
    }
    else
    {
        memset( MIN , 0x3f , sizeof MIN );
        MIN[1] = dist[1];
        q[0] = 1;
    }

    int hh = 0 , tt = 0 ; //队头 队尾
    
    while( hh <= tt ){
        int t = q[ hh ++ ];
        st[t] = false ;
        
        for( int i = h[t] ; ~i ; i = ne[i] ){
            int j = e[i];

            if( type && MAX[j] < max( dist[j] , MAX[t] ) ){     //可以更新 在 j 点的 MAX
                MAX[j] = max( dist[j] , MAX[t] );   
                if( !st[j] ){
                    q[ ++ tt ] = j;
                    st[j] = true;
                }
            }
            if( !type && MIN[j] > min( dist[j] , MIN[t] ) ){    //可以更新 在 j 点的 MIN
                MIN[j] = min( dist[j] , MIN[t] );  
                if( !st[j] ){
                    q[ ++ tt ] = j;
                    st[j] = true;
                }
            }
            
        }

    }
    
}

int main(){
    
    scanf("%d%d" , &n, &m );

    for( int i = 1 ; i <= n ; i ++ ) scanf("%d", &dist[i] );

    memset( hs , -1 , sizeof hs );
    memset( he , -1 , sizeof he );

    while ( m -- )
    {
        int  a , b , c ;
        scanf("%d%d%d", &a , &b , &c );
        add( hs , a , b );
        add( he , b , a );
        if( c == 2 ){       //双向通道 ， 两张表都要在 加一下反向的边。
            add( hs , b , a );
            add( he , a , b );
        }
    }
    spfa( hs , 0 );
    spfa( he , 1 );

    int res = -1;
    for( int i = 1 ; i <= n; i ++ ) res = max(  res , MAX[i] - MIN[i] );
    for( int i = 1 ; i <= n; i ++ ) {
        cout<<MAX[i]<<" "<<MIN[i]<<endl;
    }

    cout<<res;
    system("pause");
    return 0;
}