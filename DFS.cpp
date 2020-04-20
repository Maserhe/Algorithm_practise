#include<iostream>
using namespace std;

const int N=10;

int n;
int answer[N];

bool f[N];
void dfs(int x){

    if(x==n){
        for(int i = 0 ; i < n ; i ++ ) printf("%d ", answer[i]);
        puts();
        return;
    }
    for(int i = 1; i <= n ; i++ ){
        if(!f[N]==true){
            answer[x] = i;

            f[i]= true;

            dfs(x+1);

            f[i] = false;

        }
    }
}

int main(){

    cin>>n;
    dfs(0);
    system("pause"); 
    return 0;
}