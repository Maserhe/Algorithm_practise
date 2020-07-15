#include<iostream>  //整数二分

using namespace std;

const int N = 1e5+10;
int n ,m ;
int a[N];
int main(){
    
    cin>>n>>m;
    for(int i = 0 ;i < n ; i++ )cin>>a[i];
    
    while(m -- ){
        int x;
        cin>>x;
        int  l = 0, r =n-1;
        
        while( l < r){
            int mid = l+ r >>1;
            
            if(a[mid] >= x) r =mid;
            else l = mid + 1;
        }
        if(a[l] != x){
           cout<<"-1 -1"<<endl;
           continue;
        } 
        
        cout<<l<<" ";
        l = 0; r =n-1;
         while( l < r){
            int mid = l + r + 1>>1;
            
            if(a[mid] >= x) l =mid;
            else r = mid - 1;
        }
        cout<<r<<endl;
    
    }
    system("pause");
    return 0;
}
/*输入
6 3
1 2 2 3 3 4
3
4
5
输出
3 4
5 5
-1 -1
*/