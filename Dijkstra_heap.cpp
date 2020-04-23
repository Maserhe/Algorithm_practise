#include<cstring>
#include<iostream>
#include<queue>

using namespace std;
const int N = 100;

typedef pair<int,int> PII;
int h[N],idx,e[N],ne[N],w[N];

int dist[N];
bool st[N];
int n , m; //n个点，m条边

void add(int a, int b, int c){
    e[idx] = b;  //创建节点
    ne[idx] = h[a];  //在头部插入节点
    w[idx] = c;
    h[a] = idx++;

}
int Dijkstra(){

    priority_queue<PII,vector<PII>,greater<PII> > heap;

    heap.push({1,0});
    dist[1] = 0;
    memset(dist,0x3f,sizeof dist);

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.first;
        int distance = t.second;

        if(st[ver]) continue;

        for(int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];

            if(dist[j]>distance+w[i]) //这里权值
            {
                dist[j] = w[i] + distance;
                heap.push({j,dist[j]});
               
            }

        }
        
        
    }

    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];

}
int main(){
    cin>>n>>m;

    memset(h,-1,sizeof h); //表头全部初始化为-1

    while (m--)
    {
        int a, b , c;
        cin>>a>>b>>c;
        add(a,b,c);
    }

    int t = Dijkstra();
    
    cout<<t;


    system("pause");
    return 0;
}