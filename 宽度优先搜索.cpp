#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
const int N =10000;
bool st[N];
queue<int> q;

int e[N], ne[N], idx, h[N];
int main(){

    
    st[1] = true; // 表示1号点已经被遍历过
    q.push(1);

}

int bfs(){
    while (q.size())
    {
        int t = q.front();
        q.pop();

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (!st[j])
            {
                st[j] = true; // 表示点j已经被遍历过
                q.push(j);
            }
        }

    }
}
