#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

bool bfs(string st)
{

    string end = "12345678x";
    unordered_map<string ,int > dist; //用来记录某一种状态是否被搜索过
    unordered_map<string , pair<string, int> > prev; //记录当前状态是由哪一种状态转移过来的

    queue<string> q;

    q.push(st);
    dist[st]  =  0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    char dir[4] = {'u', 'r', 'd', 'l'};

    while ( q.size() )
    {
        
        string t = q.front();
        q.pop();

        int distance = dist[t];

        if (t == end) { // 如果找到了答案.
            vector<char> res;
            while(distance --)
            {
                auto s = prev[end];
                res.push_back(dir[s.second]);
                end = s.first;
            }

            for(int i = res.size() - 1; i >= 0; i --) cout << res[i];
            return true;
        };
       
        int x, y;
        int k =t.find('x');
        x = k / 3 , y = k % 3;
        for( int i = 0 ; i < 4 ; i ++ ){
            
            string tmp = t;
            int a = x + dx[i];
            int b = y + dy[i];
            if( a < 0 || a >= 3 || b <  0 || b >= 3 ) continue;
            

            swap( t[ x * 3 + y ] , t[  a * 3 + b ]);  //将两个换位置
            
            if(dist.count( t )){    //说明之前已经 进队了
                swap( t[ x * 3 + y ] , t[  a * 3 + b ]);  //将两个换位置
                continue;   
            }
            dist[t] = distance + 1; //记录情况
            prev[t] = { tmp , i}; // 先前状态是 tmp , 转移的方式 为 i 
            
            q.push(t);
            swap( t[ x * 3 + y ] , t[  a * 3 + b ]); //恢复现场
            
        }
    }
    
    return false;
}

int main(){
    string str;
    for(int i = 0; i < 9; i ++)
    {
        char c;
        cin >> c;
        str += c;
    }

    if(!bfs(str)) puts("unsolvable"); // 如果找不到答案.
    return 0;
}

