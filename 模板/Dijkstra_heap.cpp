#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int,int> PII;
const int N =1000;
int h[N], e[N], ne[N],idx, w[N];
int n, m;
int dist[N];
bool st[N];
int Dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;

    heap.push({0,1});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second;
        int distance = t.first;

        if(st[ver]) continue;
        st[ver] = true;

        for(int i  = h[ver]; i != -1 ; i = ne[i] ){
            int j = e[i];

            if(dist[j] > w[i] + distance){
                dist[j] = w[i] + distance;
                heap.push( { dist[j], j } );
            }

        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];

}
void add(int a, int b ,int c){
    e[idx] =b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
int main(){
    memset(h, -1, sizeof h);
    cin>>n>>m;

    while (m--)
    {
        int a, b ,c;
        scanf("%d%d%d",&a,&b,&c);

        add(a,b,c);
    }
    
    int t = Dijkstra();
    cout<<t;

    system("pause");
    return 0;
}