#include<iostream>
#include<algorithm>
using namespace std;

int n , m;
const int N = 1000;
int p[N];

struct edge
{
    int a , b, w;
    bool operator > (const edge & W){
        return w>W.w;
    }
}Edges[N];
bool find(int x){
    if(p[x]!= x) p[x] = find(p[x]);
    return p[x];
}
int main(){
    cin>>n>>m;
    for(int i = 0 ; i < m ; i++ ){   //m条边
        int a, b ,c;
        scanf("%d%d%d",&a,&b,&c);
        Edges[i] = {a, b, c};
    }

    sort(Edges, Edges + m); //按找 权值排好序
    for(int i = 1; i <= n; i++ ) p[i] = i; //并查集 初始化
    int res = 0, cnt = 0 ;
    for(int i =  0 ; i < m ; i ++ ){
        int a = Edges[i].a, b= Edges[i].b, w= Edges[i].w;

        if(find(a) != find(b) ){
            cnt+= 1;
            res += w;
            p[a] = find(b);
        }
    }
    if(cnt< n- 1) puts("impossible");

    else cout<<res;    
    system("pause");
    return 0;
}
/*输入数据
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
输出
6
*/