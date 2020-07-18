#include <iostream>
#include <algorithm>
using namespace std;

const int N = 9;

int row[N], col[N], cell[3][3];
char str[100];

//ones 存储每一个数字中有多少个1
int ones[1 << N], map[1 << N];

inline int lowbit(int x)
{
    return x & -x;
}

void init()
{
    for(int i = 0 ; i < N; i++) row[i] = col[i] = (1 << N) - 1;
    for(int i = 0 ; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cell[i][j] = (1 << N) - 1;
}


inline int get(int x, int y)
{
    return row[x] & col[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt)
{
    if(!cnt) return true;

    //寻找方案数最小的位置
    int minv = 10;
    int x, y;
    for(int i = 0 ; i < N; i++)
        for(int j = 0 ; j < N; j++)
            if(str[i * 9 + j] == '.')
            {
                int t = ones[get(i, j)];
                if(t < minv)
                {
                    minv = t;
                    x = i;
                    y = j;
                }
            }

    for(int i = get(x, y); i; i -= lowbit(i))
    {
        int t = map[lowbit(i)];
        row[x] -= 1 << t;
        col[y] -= 1 << t;
        cell[x / 3][y / 3] -= 1 << t;
        str[x * 9 + y] = '1' + t;

        if(dfs(cnt - 1)) return true;

        row[x] += 1 << t;
        col[y] += 1 << t;
        cell[x / 3][y / 3] += 1 << t;
        str[x * 9 + y] = '.';

    }


    return false;
}



int main()
{

    //map和one 进行优化剪枝用下标对应所填数值，初始所有位当置1
    for(int i=0;i<N;i++) map[1<<i]=i; //最低位的1是在第几位

    //统计第i位可选的方案数
    for(int i=0;i<1<<N;i++){
       int s=0;
       for(int j=i;j;j-=lowbit(j)) s++;  //统计第i个位置可选的方案数
       ones[i]=s;
    } 


    while(cin >> str, str[0] != 'e')
    {
        init();

        int cnt = 0;
        for(int i = 0, k = 0; i < N; i ++)
            for(int j = 0; j < N; j ++, k ++)
                if(str[k] != '.')
                {
                    int t = str[k] - '1';
                    row[i] -= 1 << t;
                    col[j] -= 1 << t;
                    cell[i / 3][j / 3] -= 1 << t;
                }
                else cnt ++;
        dfs(cnt);

        cout << str << endl;

    }

    return 0;
}