#include<iostream>

using namespace std;

const int N= 1e5+10;
int h[N],m,a[N];
/*
插入一个数， heap[++size] = x,up(size);

求最小值     heap[1]

删除最小值   heap[1] = heap[size]; size--; down(k);up(k);

删除任意元素 heap[k] = heap[size]; size--; down(k);up(k);

修改任意一个元素 heap[k] = x; down(k); up(k);


*/

void up(int x){

    while(h[x/2]>h[x]) {
        swap(h[x/2],h[x]);
        x /=2;
    }
   
}
void down(int x){
    int t = x;
    if(x*2 <= m&& h[x*2] < h[t]) t = x*2;
    if(x*2+1 <= m&&h[x*2+1] <h[t] ) t = x*2+1;

    if(x!=t){
        swap(a[t],a[x]);
        down(t);
    }


}
void add(int x){

    h[++m] = x;

    up(m);


}
int main(){

    int n ;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++  ) scanf("%d",&a[i]);
    m = n;
    for(int i = n/2;i >= 0; i -- )  down(i); //时间复杂度为N的建造堆的方式
         
    for(int i = 1; i <= n; i ++ ) printf("%d ",a[i]);




    system("pause");
    return 0;
}