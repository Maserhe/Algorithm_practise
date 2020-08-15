#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;

const int N = 700, M = 100010;
int n;
int h[N], e[M], ne[M], w[M], idx;
double dist[N];
int q[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ; 
}
bool check(double mid)  //判断是否有负环
{
    memset(st, false, sizeof st);
    memset(cnt, 0, sizeof cnt);
    memset(dist, 0,sizeof dist);

    int hh = 0, tt = 0;//循环队列
    for (int i = 1; i <= 676 ;i ++ )
    {
        q[tt ++ ] = i;
        st[i] = true;
    }
    while (hh != tt)
    {
        int t = q[hh ++ ];
        if(hh == N) hh = 0;
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = ne[i];
            if (dist[j] > dist[t] + w[i] - mid)
            {
                dist[j] = dist[t] + w[i] - mid;
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= N) return true;    //说明有负环。
                if(!st[j])
                {
                    st[j] = true;
                    q[tt ++ ] = j;
                    if(tt == N) tt = 0;
                }

            }
        }
    }
    
    return false;
}
int main(){

    char str[1010];
    while (cin >> n, n)
    {
        memset(h, -1, sizeof h);
        idx = 0;
        for (int i = 0; i < n; i ++ )
        {
            cin >> str;
            int len = strlen(str);
            if (len >= 2)
            {
                int left = (str[0] - 'a') * 26 + str[1] - 'a';
                int right = (str[len -2] - 'a') * 26 + str[len - 1] - 'a';
                add(left, right, len);
            }
        }   
        
        if (!check(0)) cout<<"NO Solution."<<endl;
        else
        {
            double l = 0, r = 1000;

            while (r - l > 1e-4)
            {
                double mid = (l - r) / 2;
                if (check(mid)) l = mid;
                else r = mid;
            }
            printf("%.2lf\n", l);
        }
        
    }

    system("pause");
    return 0;
}