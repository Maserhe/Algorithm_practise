#include<iostream>

using namespace std;

//用数组模拟单链表
const int N= 1000;

int n[N],ne[N];
int head,idx;

void init(){
    head = -1;
    idx =0;
}
//在下表为k的元素后面插上 x
void add(int k ,int x){

    n[idx] = x;
    ne[idx] =ne[k];
    ne[k]= idx;
    idx++;

}
//在头部插入 元素 x
void add_to_head(int x){

    n[idx] = x;
    ne[idx] = head;
    head= idx;
    idx++;

}

//删除下表为k的元素后面的那个元素
void remove(int k){

    ne[k]=ne[ne[k]];

}

int main(){
    //初始化
    init();

    system("pause");
    return 0;
}