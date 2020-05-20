#include<iostream>

using namespace std;
const int N = 1e5+10;

int a[N],n,m;

int find(int x){
    if(a[x]!=x) a[x] = find(a[x]);//加入路径优化

    return a[x];
}

int main(){


    scanf("%d%d",&n,&m);
    
    for(int i = 1 ; i <= n ; i ++ ) a[i]= i;

    while(m--){
        char s[2];

        int x, y;

        scanf("%s%d%d",s,&x,&y);

        if(s[0] == 'M'){

            if(find(x)==find(y)) break;

            a[find(x)] = find(y);


        }else if( s[0] == 'Q'){

            if(find(x)==find(y)) printf("YES\n");

            else printf("NO\n");


        }


    }





    system("pause");
    return 0;
}