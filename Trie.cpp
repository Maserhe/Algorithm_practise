#include<iostream>

using namespace std;

const int N= 1e6+10;

int son[N][26],cnt[N],idx;

char str[N];

//插入
void insert(char str[]){

    int p = 0;//从第一个结点开始 插入

    for(int i = 0; str[i] ; i++ ){

        int size = str[i] - 'a';
        if(!son[p][size]) son[p][size] = ++idx ; //如果不存在就创建这个节点

        p = son[p][size];//如果存在，我就让他往下一个节点走；


    }

    cnt[p]++;//以第p个结点结尾的单词的个数

}
int query(char str[]){
    
    int p = 0;
    for(int i = 0 ; str[i] ; i ++ ){

        int size = str[i] - 'a';
        if(!son[p][size]) return 0;
        
        p = son[p][size];

    }
    
    return cnt[p];

}



int main(){

   


    system("pause");
    return 0;
}