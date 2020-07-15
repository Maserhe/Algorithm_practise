#include<iostream>
#include<cstring>
using namespace std;

const int N = 1000;

int e[N],ne[N], idx, h[N];

bool st[N];
int match[N];
int n ,m ;

 void add(int a, int b){
     e[idx] = a;
     ne[idx] = h[a];
     h[a] =idx ++ ;
}
bool find(int x){

    for(int i = h[x]; i != -1 ; i = ne[i] ){
        int j = e[i];
        if(!st[j]){
            
            if(!match[j] || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin>>n>>m;

    for(int i = 0 ; i < m ; i ++ ){
        int a, b;
        scanf("%d%d", &a,&b);
        add(a,b);
    }
    int res = 0 ;
    for(int i =1; i <= n; i ++ ){
        memset(st,false, sizeof st);

        if(find(i)) res ++ ;
    }

    cout<<res;
    system("pause");
    return 0;
}
/*
输入
2 4 //两个点， 4 条边
1 1
1 2
2 1
2 2
输出
2
*/