#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;    //差分约束, 区间

const int N = 5e6 + 10;
int e[N], ne[N], h[N], w[N], idx;
bool st[N];
int dist[N];
int q[N];
int n;

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
}
void spfa(){

    memset(dist, -0x3f, sizeof dist);

    int hh = 0, tt =1;
    q[0] = 0;
    dist[0] = 0;

    while (hh != tt)
    {
        int t = q[hh ++];
        st[t] = false;
        if(hh == N) hh = 0;
        
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            
            if(dist[j] < dist[t] + w[i]){
                dist[j] = dist[t] + w[i];  
                
                if(!st[j]){
                    q[tt ++ ] = j;
                    st[j] = true;
                    if (tt == N) tt = 0;
                    
                }
            }
        }
    }
    
}
int main(){
    
    cin>>n;

    memset(h, -1, sizeof h);
    for (int i = 1;i <= 50001; i ++ ) add(i, i - 1, -1), add(i - 1, i, 0);

    while (n -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        a ++ , b ++ ;
        add(a - 1, b, c);
    }
    spfa();
    
    cout << dist[50001];
    system("pause");
    return 0;
}