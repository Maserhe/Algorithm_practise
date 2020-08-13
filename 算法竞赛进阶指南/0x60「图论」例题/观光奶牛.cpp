#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;
const int N = 1010, M = 5000;
int h[N], ne[M], e[M], wt[M], wf[M], idx;
int dist[N];
bool st[N];
int q[M];   //循环队列
int n , m;
int Size[N];
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], wt[idx] = c, h[a] = idx ++ ;
}
bool spfa(int mid){
    memset(st, 0, sizeof st);
    memset(dist, 0, sizeof dist);

    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i ++ ) q[tt ++ ] = i, st[i] = true;
    
    while (hh != tt)
    {
        int t = q[hh ++ ];
        if(hh == M) hh = 0;
        st[t] = false;
        
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] + wf[i] - mid * wt[i]){
                dist[j] = dist[t] + wf[i] - mid * wt[i];
                Size[j] = Size[i] + 1;
                if (Size[j] >= n) return true;
                if (!st[j]){
                    q[tt ++ ] = j;
                    st[j] = true;
                    if (tt == M) tt = 0;
                }
           }
       }
    }
    
    return false;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> wf[i];

    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c; 
        add(a, b, c);
    }
    double l = 0, r = 1000;
    while (r - l > 1e-4)
    {
        double mid = (l + r) / 2;
        if (spfa(mid)) l = mid;
        else r = mid;
    }
    
    printf("%.2lf", l);
    
    system("pause");
    return 0;
}
/*
5 7
30
10
10
5
10
1 2 3
2 3 2
3 4 5
3 5 2
4 5 5
5 1 3
5 2 2
*/