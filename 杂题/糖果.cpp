#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std; //差分约束
const int N = 1e5;
int dist[N];
int e[N], ne[N*2], w[N*2], h[N*2], idx;
bool st[N];
int q[N];
int n, m;
int cnt[N];
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

bool spfa(){
    int hh  = 0, tt = 1;
    memset(dist, -0x3f, sizeof dist);
    dist[0] = 0;

    q[0] = 0;
    st[0] = true;

    while (hh != tt)
    {
        int t = q[hh ++ ];
        if (hh == N*2) hh = 0;

        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];

            if (dist[j] < dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] > n) return false;
                if(!st[j]){
                    q[tt ++ ] = j;
                    if(tt == N*2) tt = 0;
                    st[j] = false;
                }
            }

        }

    }
    

    return true;
}
int main(){

    cin >> n >> m;
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 1) add(a, b, 0) ,add(b, a, 0);
        else if (c == 2) add(a, b, 1);
        else if (c == 3) add(b, a , 0);
        else if (c == 4) add(b, a, 1);
        else add(a, b, 0);
    }
    
    for(int i = 1; i <= n; i ++ )add(0, i, 1);

    if (!spfa())cout<<"NO Solution"<<endl;
    else
    {
        int ans = 0;
        for(int i = 0; i <= n;i ++ ) ans += dist[i];
        cout << ans;
    }
    
    system("pause");
    return 0;
}