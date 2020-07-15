#include<iostream>

using namespace std;

int a[10] = {1,45,48,2,485,6,87,2,7,52};
int tem[100];
void merge_sort(int arr[], int l , int r){

    if(l >= r ) return ;
    int mid = l+ r >> 1;
    merge_sort(arr, l ,mid);
    merge_sort(arr, mid+1, r);

    int k =0  , i = l , j = mid + 1;
    
    while (i <= mid && j <= r)
    {
        if(arr[i] < arr[ j ]) tem[k++ ] = arr[i ++ ];
        else tem[k ++ ] = arr[ j ++ ];
    }
    
    while (i <= mid) tem[k ++ ] = arr[ i ++ ];
    while (j <= r) tem[k++] = arr[ j ++ ];

    for( int i = l , k =0 ; i <= r ; i ++ ) arr[i] = tem[k++ ];

}
int main(){

    int len = sizeof(a)/sizeof(*a);
    
    merge_sort(a, 0 , len - 1);

    for(int i = 0; i < len ; i ++ ) cout<< a[i]<<" ";
    system("pause");
    return 0;
}