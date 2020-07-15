#include<algorithm>
#include<cstring>
#include<iostream>


using namespace std;

const int N = 2e5 + 10;
int q[N];
int dist[N];
int n ,k ;
int bfs(){

    memset(dist , -1 , sizeof dist);

    int hh = 0 , tt = 0;
    q[0] = n;
    dist[n]= 0;

    while (hh <= tt )
    {
        if(dist[k] != -1) return dist[k];
        int t = q[ hh ++ ];
        if( t-1 >= 0 && dist[t-1] == -1) q[++tt] = t-1 , dist[t-1] = dist[t] + 1;
        if( t*2 < N && dist[t*2] == -1) q[++tt] = t*2 , dist[t*2] = dist[t] + 1;
        if( t+1 < N && dist[t+1] == -1) q[++tt] = t+1 , dist[t+1] = dist[t] + 1;
    }
}

int main(){

    cin>>n>>k;
    cout<<bfs()<<endl;
    system("pause");
    return 0;
}
