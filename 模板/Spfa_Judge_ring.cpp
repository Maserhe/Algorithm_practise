#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N =1000;

int n, m; //n个点， m条边

int h[N],e[N],ne[N],w[N],idx;  //邻接表

int dist[N], cnt[N];
bool st[N];
void add(int a, int b ,int c){

    e[idx] = b;
    ne[idx] =h[a];
    w[idx] = c;
    h[a] = idx++;
}

bool spaf(){
    queue<int> q;
    for( int i = 1; i <= n ; i ++ ){ //将所有点都放入队列
        q.push(i);
        st[i] = true;
    }
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for( int i = h[t] ; i != -1 ; i = ne[i] ){

            int j = e[i];
            
            if(dist[j] > dist[t] + w[i]){
                cnt[j] = cnt[t] + 1;

                dist[j] = dist[t] + w[i];
// 如果从1号点到x的最短路中包含至少n个点（不包括自己），则说明存在环
                if(cnt[j]>=n) return true;

                if(!st[j]){
                    q.push(j);
                    st[j] =true;
                }

            }
        }
    }  
    return false;
}
int main(){
    cin>>n>>m;
    memset(h , -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }

    if(spaf()) puts("Yes"); //存在负环

    else puts("No"); //不存在    
    system("pause");
    return 0;
}
/*样例输入
3 3
1 2 -1
2 3 4
3 1 -4
输出
Yes
*/