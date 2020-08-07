#include<iostream>
#include<cstring>
using namespace std;
const int N=30;
int g[N][N],d[N],temp[N];
int n,m,flag;//flag=1:有序 flag=-1:不确定
int q[N];

int TopoSort() //拓扑排序
{
    flag=1;
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++)
    {
        temp[i]=d[i];//一边输入一边拓扑排序，所有入度数组不能改变    
    }  
    int m=0,cnt=0;
    for(int i=1;i<=n;i++)//查找入度为零的顶点个数，若>1，拓扑序不确定 
        if(temp[i]==0)
        {
            q[++tt]=i;
            cnt++;
        }
    if(cnt==0) return 0; //有环
    if(cnt>1) flag=-1; //不确定
    while(hh <= tt)
    {
        cnt=0;
        int t=q[hh++];
        for(int i=1;i<=n;i++)
            if(g[t][i])
            {
                temp[i]--;
                if(!temp[i])
                {
                    q[++tt]=i;
                    cnt++;
                }
            }
        if(cnt>1) flag=-1; //不确定        
    }
    if(tt < n-1)
        return 0;
    return flag;
}

int main()
{
    int sign;  //当sign=1时，已得出结果
    string str;
    while(cin>>n>>m)
    {
        if(m==0&&n==0) break;
        memset(g,0,sizeof g);
        memset(d,0,sizeof d);
        sign=0;
        for(int i=1;i<=m;i++)
        {
            cin>>str;
            if(sign) continue; //一旦得出结果，对后续的输入不做处理
            int x=str[0]-'A'+1;
            int y=str[2]-'A'+1;
            g[x][y]=1;
            d[y]++;
            int s=TopoSort();
            if(s==0) //有环
            {
                printf("Inconsistency found after %d relations.\n",i);
                sign=1;
            }
            if(s==1) //有序
            {
                printf("Sorted sequence determined after %d relations: ",i);
                for(int j=0;j<n;j++)
                    cout<<char(q[j]+'A'-1);
                printf(".\n");
                sign=1;
            }
        }
        if(!sign) //不确定
            printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}

