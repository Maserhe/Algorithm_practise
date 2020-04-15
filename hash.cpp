#include<iostream>

using namespace  std;
typedef unsigned long long ull;//如果数据类型为 ull 对2^64取模，如果溢出就相当于取模
const int N  =1e5+10;

int n, m;

int p = 131;//这个哈希的进制为131进制
ull q[N],h[N];//h[n]存取哈希值， q[h]存储第N位的权值
char str[N];
 
ull get(int l,int r){


    return h[r] - h[l] * q[ r-l+1];
}
int main(){

    scanf("%d%d%s",&n,&m,str+1);// 

    q[0]= 1;

    for(int i = 1 ; i <= n ; i ++ ) {
        q[i] = q[i -1]* p;

        h[i] = h[i -1] *p + str[i];
    }

    while(m -- ){ //进行m次询问
        int x1,y1,x2,y2;

        scanf("%d%d%d%d",&x1,&y2,&x2,&y2);

        if(get(x1,y1)!= get(x2,y2)) puts("Yes");

        else puts("No");

    }
    return 0 ;
}
