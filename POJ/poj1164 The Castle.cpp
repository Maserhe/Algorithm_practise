#include<iostream>
#include<algorithm>
#include<cstring>

#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;
const int N = 55 , M= N*N;
PII q[M];
bool st[N][N];
int n , m;
int g[N][N];

int dfs(int sx , int sy){ //返回联通块的面积
    q[0].x = sx, q[0].y = sy;
    st[sx][sy]= true;

    int hh = 0 , tt =0; 
    int area = 0;
    //定义四种方向
    int tx[4] = {0 , -1 , 0 , 1}, ty[4] = {-1 , 0 , 1, 0 };
    while (hh <= tt)//如果队列不为空的话
    {
        PII t = q[hh++];
        area++;
        for(int i = 0 ; i < 4 ; i ++ ){
            int a = t.x + tx[i], b = t.y + ty[i]; //代表几种坐标
            if(g[t.x][t.y]>>i&1)continue;
            if(a<0 || a >=n || b < 0 || b >=m )continue;
            if(st[a][b])continue;
            q[++tt].x = a;  //poj 好像不支持 q[++tt] = {a , b} ; 这种写法
            q[tt].y = b;
            st[a][b] = true;
        }
    }
    return area;
}
int main(){
    cin>>n>>m;
    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < m ; j ++ )
            cin>>g[i][j];
    
    int cnt = 0 , area = 0;
    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < m ; j ++ )
            if(!st[i][j]){
                area = max(area , dfs(i, j));
                cnt ++;
            }
    
    cout<<cnt<<endl;
    cout<<area<<endl;
    system("pause");
    return 0;
}