#include<iostream>

using namespace std;

const int N= 10010;

int e[N], l[N], r[N], idx;

void init(){
    //让0代表左端点，1代表右端点,即 0 代表头部， 1 代表 尾部
    l[0] = 0;
    r[0] = 1;

    idx = 2;
}
//在下表为 k元素后面插入一个元素
void add(int k, int x){

    e[idx] = x;

    l[idx] = k;

    r[idx] = r[k];

    l[r[k]] = idx;//注意先后问题， 先把后面的 链接拔掉， r[k] 不能先改变

    r[k] = idx;

}
//将下标为K的元素删除
void remove(int k){

    r[l[k]] = r[k];

    l[r[k]] = l[k];

}

int main(){

    init();

    system("pause");
    return 0;
}