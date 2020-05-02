#include<iostream>
using namespace std;

int  a[21];
int l , r , k ;

long long conflict(int x){   计算 从 1 到 x 与 A 数组有关元素的数量
    long long res = 0;  记录有关元素的 个数
    for( int i = 1 ; i <1<< k ; i ++ ){   从 1 枚举到 2^k 状态
    
        // 记录是有枚举的元素中 1的 个数 例如 当i = 0010101 就有 cnt = 3
        int cnt =0; 
        
        // 记录枚举值的状态 如  A = { 2 . 3 , 5 , 7}; 当 i= 0011时， t= 2*3
        int t = 1;     
        for( int j = 0; j < k ; j ++ ){
            if(i>>j & 1){   //取出 二进制 表示 的 第 j 个元素
                
                if( t *a[j] > x){ //超出数据范围，不需要计算了。这里如果加上大于最小值的判断，就没必要算 L-1 再算 R 了，一次就就可以算完了。
                    t =-1 ; 
                    break; 
                }
                cnt ++ ;     //没有超出范围  我们就 加 1
                t*= a[j];
            }
        }
        if(t!=-1){     //没有超出范围 
            if(cnt % 2 )  res += x/t;   //容斥原理 如果 时 奇数 就 +  ， 否则就减
            else res -= x/t;         
        }
    }
    return res;  
}

int main(){

    cin>>l>>r>>k;
    
    for( int i = 0 ; i < k ; i ++ ) cin>>a[i];

    int sum= conflict(r)- conflict(l-1);

    cout<< r-l+ 1 -sum;   //L到 R 共有r- L+ 1 个元素 再减去 和A有关 的元素个数

    system("pause");
    return 0;
}
