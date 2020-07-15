#include<iostream>
#include<algorithm>

using namespace std;

const int N =10010;

typedef pair<int , int> PII;
PII q[N];
int n , f[N];

int main(){
    cin>>n;
    for( int i = 0 ; i <n; i ++ ) cin>>q[i].first>>q[i].second;

    sort(q,q+n);
    int res= 1;
    for( int i = 0; i < n ; i++ ){
        f[i] = 1;
        for(int j =0 ; j < i ; j ++ ){
            if(q[i].second > q[j].second ){

                f[i] = max(f[i] , f[j] + 1);
            }

        }
        res = max(res, f[i]);
    }
    
    cout<<res;
    return 0;
}