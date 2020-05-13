#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class SeqList{
private:
    int *data;
    int Maxsize;
    int Length;

public:
    SeqList(int a = 100);    //默认 Maxsize = 100
    ~SeqList() {delete [] data;};
    void InitList(); //初始化

    void max();  //求最大值

    void ergodic(); //遍历所有线性表

    int seek(int x); //进行 查找 元素 ,成功 返回 1  ，否则返回 0；

    int symmetry();  //判断是否对称 ， 成功返回 1 ，否则返回0

    void odd_even(); //将奇数排列在 偶数 前面

    void mysort(); // 对输入 的 元素 进行 排序

    void merge_sort( SeqList &  ,SeqList & ); // 将两个顺序表 进行 合并 排序 到 第三个中

    void insert(int x, int idx ); //再 下表 为 idx 的 地方 插入 x

    int find(int x); //查找元素 并返回 下标 ,找不到返回 -1

    void remove(int x); //删除元素x , 若有多个 x 我只删除 第一个出现的 x

};

SeqList::SeqList(int a ){
    Maxsize = a;
    data = new int[Maxsize];
    int Length = 0;

    memset(data , 0 , sizeof data);  //使线性表中的数据全部初始化成0；
}
void SeqList::InitList(){

    cout<<"请输入"<<Maxsize<<"个整数"<<endl;
    Length = Maxsize;     //这种初始化 ， 是对线性表中的所有内容进行赋值,
    for(int i = 0 ; i < Maxsize ; i ++ ) cin>>data[i];
    
}
void SeqList::ergodic(){    //遍历线性表 所有元素  输出
    for(int i = 0 ; i  < Length ; i ++ )
        cout<<data[i]<<" ";
    cout<<endl;
}
int SeqList::seek(int x){    //进行 查找 元素 ,成功 返回 1  ，否则返回 0；
    for(int i = 0 ; i < Length ; i ++ )
        if(data[i] == x) return 1;   //查找到 返回 1

    return 0;    //没有查找到返回 0
}

int SeqList::symmetry(){
    int t = Length/2;
    for(int i =0 ; i < t ; i ++ )
        if(data[i] != data[Length - i]) return 0;  //如果 不相同 就返回 0

    return 1;  //元素 对称返回 1；
}

void SeqList::odd_even(){           //将奇数排列在 偶数 前面 ，用 双指针算法  遍历一遍就可以了
    cout<<"将奇数排在偶数前面"<<endl;
    if(Length == 0 ) return; 
    int l = -1  , r = Length ;      // 0 到 length-1 个元素 ，下面用的 do while 循环 ，所以左边减1，右边 加1 

    while (l < r)  
    {
        do l ++ ; while ( data[ l ] %2 !=0 );  //只要是 奇数， 我就 一直 让 指针往下走 ，直到碰见 第一个 偶数
        do r -- ; while ( data[ r ] %2 == 0);  //只要是 偶数 ，我就 一直 让 指针往后退 ，直到碰见 第一个 奇数
        swap(data[l] ,data[r]);
    }   
}

void SeqList::mysort(){  //这里 将 线性表 进行 排序
    cout<<"对线性表进行 排序"<<endl;
    sort(data ,data + Length);
}

void SeqList::remove(int x){ //删除元素x , 若有多个 x 我只删除 第一个出现的 x
    cout<<"删除下表为"<<x<<"的点"<<endl;
    if(x>Length - 1) return; //特判
    for(int i = x; i < Length -1; i ++)
        data[i] = data[i+1];
       
    data[Length-1 ] =0;  //这个可以不用写，
    Length-=1;
 }

void SeqList::insert(int x, int idx ){  //再 下表 为 idx 的 地方 插入 x
    cout<<"在下表为"<<idx<<"的地方插入"<<x<<endl;
    if(Length == Maxsize) return;  //特判 ，无法插入

    for(int i = Length ; i > idx ; i --){
        data[i+1] = data[i];
    }
    data[idx] = x;
}

int SeqList::find(int x){ //查找元素 并返回 下标
    
    for(int i = 0 ; i < Length ; i ++ )
        if(data[i] == x) return x;

    return -1;
}


void SeqList::merge_sort(SeqList & t1 , SeqList & t2){ // 将两个顺序表 进行 合并 排序 时间复杂度O(n)

    if(t1.Length + t2.Length > Maxsize) return ; // 长度不够
    int i=0,j=0,k=0;   
    while (i < t1.Length && j <t2.Length)
    {
        if(t1.data[i] < t2.data[j])  data[k++] = t1.data[i ++ ];
        else  data[k++] = t2.data[j ++];
    } 
    //已经有一个序列 差如完毕 ， 剩下的直接插上就行
    while(i < t1.Length )  data[k++] = t1.data[i ++ ];
    while (j <t2.Length)  data[k++] = t2.data[j ++];
    Length = k ; 
}

int main(){
    
    SeqList s(10);
    s.InitList();
    puts("");

    s.mysort();
    s.ergodic();

    puts("");
    s.odd_even();
    s.ergodic();

    puts("");
    cout<<"元素是否对称"<<s.symmetry()<<endl;

    puts("");
    cout<<"元素2是否存在"<<s.seek(2)<<endl;

    puts("");
    if(s.seek(2)) cout<<"元素 2 的下标"<<s.find(2)<<endl;   //如果2 元素存在 ，输出下标。
    
    puts("");
    s.remove(2);
    s.ergodic();

    puts("");
    s.insert(100, 0); //在下表为0 的地方 插入 100
    s.ergodic();

    puts("");
    cout<<"第一个序列"<<endl;
    s.mysort();
    s.ergodic();

    puts("");
    cout<<"第二个序列"<<endl;
    SeqList a(10);
    a.InitList();
    a.mysort();
    a.ergodic();
    puts("");
    puts("合并后的序列");
    SeqList b(100);

    b.merge_sort(s,a);
    b.ergodic();

    system("pause");
    return 0;
}