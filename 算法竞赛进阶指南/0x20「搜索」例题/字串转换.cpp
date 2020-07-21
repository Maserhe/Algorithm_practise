#include<algorithm>
#include<cstring>
#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

string A , B;
string a[6] , b[6];
int n ;

int extend( queue<string> & q,  unordered_map<string, int> & da, unordered_map<string, int>& db , string a[] ,string b[] ){

    for( int k = 0 , sk = q.size() ; k < sk ; k ++ ){ //每次 只往下 扩展一层
        string t = q.front();
        q.pop();

        for( int i = 0 ; i < t.size() ; i ++ ) //枚举相邻两列
            for( int j = 0 ; j < n ; j ++ ) //枚举规则
            if( t.substr(i, a[j].size()) == a[j] ) //如果可以按照规则转换
            {
                string state = t.substr(0 , i) + b[j] + t.substr(i+ a[j].size());
                if( db.count(state) ) return da[t] + 1 + db[state];
                if( da.count(state) ) continue;

                da[state] = da[t] + 1;
                q.push(state);
            } 
    }    
    return 11;
}
int bfs(string A , string B){

    queue<string> qa, qb;  // 双端 队列 ， 如果两个 撞见时相同 说明此时有解
    unordered_map<string, int>  da, db;
    qa.push(A);
    qb.push(B);
    da[A] = 0;
    db[B] = 0;

    while ( qa.size() && qb.size() )
    {
        int t ;
        if( qa.size() <= qb.size() ) t = extend(qa , da , db , a, b);
        else t = extend( qb,  db , da , b , a );

        if( t <= 10 ) return t;
    }

    return 11;
}

int main(){
    cin>>A>>B;
    while( cin>>a[n]>>b[n] ) n ++ ;

    int step = bfs( A , B);
    if( step > 10 )puts("NO ANSWER!");
    else cout<<step;

    return 0;
}

