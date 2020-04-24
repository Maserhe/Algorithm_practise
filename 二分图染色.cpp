#include<iostream>
#include<cstring>

using namespace std;
int n ,m; //n个点 ， m 条边

const int N = 1000;
int e[N], ne[N], idx,h[N];
int color[N]; //用来记录染的颜色 ，0 未染色 ， 1 代表一号色 ，2 代表2号色

//这里用DFS来搜索进行染色

bool DFS(int u , int c){
    
    color[u] = c;

    for( int i = h[u]; i != -1 ; i = ne[i] ){

        int j = e[i];
        if(!color[j]){
            if(!DFS(j , 3 - c)) return false;
        }
        else if( color[j] == c) return false;

    }
    
    return true;
}
void add(int a, int b ){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;

}
int main(){

    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i = 0 ; i < m ; i++ ){
        int a,b;
        cin>>a>>b;
        add(a,b); //因为图使无向图，
        add(b,a);        
    }
    bool flag = true;
    for(int i = 1; i<= n ; i++ ){ //从第一个点开始， 往下搜索
        
        if(!color[i]){
            flag = DFS(i ,1); //第i 个点染成 1号色
        }
        if(flag == false ) break;

    }
    if(flag) puts("YES");
    else puts("NO");
    system("pause");
    return 0;
}
/*输入数据

4 4
1 3
1 4
2 3
2 4

输出
YES
*/