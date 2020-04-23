#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1000;

typedef pair<int ,int> PII;
int h[N],e[N],ne[N],w[N],idx; //表头， 节点， 指向下一节点 ， 权值 ， 下标
int dist[N];
bool st[N];
int n , m;

void add(int a, int b ,int c){

    e[idx] = a, ne[idx] = h[a], w[idx]  = c, h[a] = idx++ ;
}

int Dijkstra(){

    memset(dist , 0x3f, sizeof dist);

    priority_queue<PII, vector<PII>,greater<PII> > heap;

    dist[1] = 0;
    heap.push({0,1});
    
    while(heap.size()){

        PII t = heap.top();
        heap.pop();
        int ver =t.second;
        int distance = t.first;

        if(st[ver]) continue;
        st[ver] = true;

        for(int i = h[ver]; i != -1;  i  = ne[i] ){  //顺着节点开始往下找
            int j = e[i];

            if(dist[j] > distance + w[i]){

                dist[j] = distance + w[i];
                heap.push({dist[j],j});
            }
        }
        
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
        return dist[N];
}

int main(){
    memset(h, -1 , sizeof h);
    cin>>n>>m;
    while (m --)
    {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    int t = Dijkstra();
    cout<<t;
    system("pause");
    return 0;
}

