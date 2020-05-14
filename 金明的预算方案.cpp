#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#define v first
#define w second

using namespace std;

typedef pair<int, int> PII;

const int N = 70, M = 32010;

int n, m;
PII master[N];
vector<PII> servent[N];
int f[M];

int main()
{
    cin >> m >> n;
    
    for( int i = 1 ; i <= n ; i ++ ) {
        int x , y ,z ;
        cin>>x>>y>>z;
        if(!z){
            master[i].first = x;
            master[i].second = x*y;
        }
        else servent[z].push_back({x,x*y});
    }
    
    for( int i =  1 ; i <= n ; i ++ ){
        if(master[i].first){
            
            for( int j = m ; j >= 0 ; j -- )
            {
                for( int k = 0 ; k < 1<<servent[i].size() ; k ++ )
                {
                    int a = master[i].first;
                    int b = master[i].second;
                    for( int s = 0 ; s < servent[i].size() ; s ++ ){
                        if(k >>s & 1){
                            a += servent[i][s].first;
                            b += servent[i][s].second;
                        }
                    }
                    if(j >= a ) f[j] = max( f[j] , f[ j - a] + b );
                }
                
            }
        }
    }

    cout << f[m] << endl;

    system("pause");
    return 0;
}

/*
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0

输出
2200
*/