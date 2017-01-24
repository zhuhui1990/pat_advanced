#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 0x6fffffff
#define MAX 1005
int n,m;
bool follow[MAX][MAX];
int num[MAX];
bool flag[MAX];
struct point
{
    int num;
    int level;
} node,top;
queue<struct point> q;
void bfs(int x)
{
    int countx=0;
    for(; !q.empty(); q.pop());
    memset(flag,false,sizeof(flag));
    flag[x]=true;
    node.num=x;
    node.level=0;
    q.push(node);
    for(; !q.empty();)
    {
        top=q.front();
        q.pop();
        for(int i=1; i<=n; ++i)
        {
            if(flag[i]==false&&follow[top.num][i]==true)
            {
                flag[i]=true;
                node.num=i;
                node.level=top.level+1;
                if(node.level<m)
                {
                    q.push(node);
                }
                ++countx;
            }
        }
    }
    num[x]=countx;
}
int main()
{
    int k,t;
    memset(follow,false,sizeof(follow));
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d",&t);
        for(int j=0; j<t; ++j)
        {
            scanf("%d",&k);
            follow[k][i]=true;
        }
    }
    for(int i=1; i<=n; ++i)
    {
        bfs(i);
    }
    scanf("%d",&t);
    for(; t--;)
    {
        scanf("%d",&k);
        printf("%d\n",num[k]);
    }
    return 0;
}