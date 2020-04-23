#include<iostream>
#include<cstring>
using namespace std;

const int M=10010;

int dist[M],backup[M];
int n, m,k;

struct Edge{

    int a,b,w;
}Edges[M];
int Bellman(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    // 如果第n次迭代仍然会松弛三角不等式，就说明存在一条长度是n+1的最短路径，由抽屉原理，路径中至少存在两个相同的点，说明图中存在负权回路。
    for(int i = 0 ; i < k ; i ++ ){
        memcpy(backup,dist,sizeof dist);

        for(int j = 0 ; j < m; j ++ ){
            int a = Edges[j].a, b = Edges[j].b, w = Edges[j].w;
            dist[b] = min(dist[b],backup[a] + w);

        }

    }
    if(dist[n] > 0x3f3f3f3f / 2) return -1;

    return dist[n];
}


int main(){

    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0 ; i < m ;i ++ ){
        int a, b ,w;
        scanf("%d%d%d",&a,&b,&w);
        Edges[i].a=a;
        Edges[i].b=b;
        Edges[i].w=w;

    }
    int t = Bellman();
    if(t==-1) puts("impossible");
    printf("%d",t);
    system("pause");
    return 0;
}