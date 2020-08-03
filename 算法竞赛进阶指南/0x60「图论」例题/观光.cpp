#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N=1010,M=10010;

int n,m,S,F,T;

int h[N],e[M],ne[M],w[M],idx;
int st[N][2],cnt[N][2],d[N][2];

struct Node{
    int ver,type,dist;//点，类型(最短路0，次短路1)，距离
    bool operator>(const Node &node)const{
        return dist>node.dist;
    }
};

void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}
int Dijstra(){
    memset(st,0,sizeof st);
    memset(d,0x3f,sizeof d);
    memset(cnt,0,sizeof cnt);
    priority_queue<Node,vector<Node>,greater<Node>>heap;//小根堆
    heap.push({S,0,0});
    d[S][0]=0;
    cnt[S][0]=1;
    while(heap.size()){
        Node t=heap.top();
        heap.pop();
        int ver=t.ver,type=t.type,dist=t.dist,count=cnt[ver][type];
        if(st[ver][type])   continue;
        st[ver][type]=1;
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dist+w[i]<d[j][0]){//如果最短路发生更新
                d[j][1]=d[j][0];
                d[j][0]=dist+w[i];
                cnt[j][1]=cnt[j][0];
                cnt[j][0]=count;
                heap.push({j,1,d[j][1]});//如果最短路发生更新，那么次短路也更新
                heap.push({j,0,d[j][0]});
            }
            else if(dist+w[i]==d[j][0]){
                cnt[j][0]+=count;
            }
            else if(dist+w[i]<d[j][1]){//如果次短路发生更新
                d[j][1]=dist+w[i];
                cnt[j][1]=count;
                heap.push({j,1,d[j][1]});
            }
            else if(dist+w[i]==d[j][1]){
                cnt[j][1]+=count;
            }
        }
    }
    int ans=cnt[F][0];
    if(d[F][1]==d[F][0]+1)   ans+=cnt[F][1];
    return ans;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        memset(h,-1,sizeof h);
        idx=0;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            add(a,b,c);
        }
        cin>>S>>F;
        cout<<Dijstra()<<endl;
    }
    system("pause");
    return 0;
}
