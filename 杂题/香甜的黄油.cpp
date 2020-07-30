#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;
const int N = 2000 ;
int  e[N] , ne[N] , h[N] , w[N] , idx ;  //一定要记得初始化，表头，
int n , m , o ; // 奶牛数， 牧场数， 牧场间道路
int dist[N];
bool st[N];
int sum[N]; //代表每个牧场的奶牛数目。
int spfa( int s ){
    //到每个牛的最短距离;
    
    memset( st , 0 ,sizeof st );
    memset( dist , 0x3f , sizeof dist );

    queue<int> q;    
    dist[s] = 0;
    q.push(s);
    st[s] = true;

    while (q.size())
    {
        int t = q.front(); //在队列里面的元素 置为true
        q.pop();
        st[t] = false;

        for (int i  = h [t] ; i != -1 ; i = ne[i] ){

            int j = e[i];
            if(dist[j] > dist[t] + w[i]){

                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
            
        }
    }

    int count = 0;
    for( int i = 1 ; i <= m ; i ++ ){
        count += (sum[i] * dist[i]);
    }
    
    return count;
}
void add( int a, int b , int c ){
    e[idx] = b , ne[idx] = h[a] , w[idx] = c , h[a] = idx ++ ;
}
int main(){
    cin>>n>>m>>o;
    for( int i = 0 ; i < n ; i ++ ){ //牧场号
        int a;
        cin>>a;
        sum[a] ++ ;
    }
    memset( h , -1 , sizeof h );
    for( int i = 0 ; i < o ; i ++ ){
        int a , b , c;
        cin>>a>>b>>c;
        add(a , b , c );
        add(b , a , c );
    }

    int ans = 0x3f3f3f3f;
    for( int i = 1 ; i <= m ; i ++ ){ //枚举每个牧场作为起点
        ans = min(ans , spfa(i));
    }
    cout<<ans;
    system("pause");
    return 0;
}
