#include<iostream>
#include<algorithm>
using namespace std;

int a[10] = {1,45,48,2,485,6,87,2,7,52};

void quick_sort(int arr[], int l ,int r){
    if(r<=l) return;

    int i = l - 1; 
    int j = r + 1;
    int x = a[l + r>>1]; 
    while( i < j ){
        
        do i++ ;while( arr[i] < x );
        do j--; while( arr[j] > x);

        if(i < j ) swap( arr[i], arr[j]);
    }
    quick_sort(arr,l, j);
    quick_sort(arr,j+1, r);

}
int main(){
    int len = sizeof(a) / sizeof(*a); //获得未知数组的长度

    quick_sort(a,0 ,len - 1);

    for(int  i = 0; i < len ; i ++ ) cout<<a[i]<<" ";

    system("pause");
    return 0;
}