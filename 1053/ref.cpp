#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 0x6fffffff
#define MAX 105
vector<int> link[MAX];
vector<int> path;
int weight[MAX];
bool flag[MAX];
int n,m,s;
void dfs(int weit,int idx)
{
    int len;
    weit+=weight[idx];
    if(weit>s) return;//如果权重和大于要求，返回
    else if(weit==s&&link[idx].size()==0)
    {//如果权重和等于要求且当前结点无子树
        path.push_back(weight[idx]);
        printf("%d",path[0]);
        len=path.size();
        for(int i=1;i<len;++i)
            printf(" %d",path[i]);
        printf("\n");
        path.pop_back();
    }
    else if(weit<s&&link[idx].size()>0)
    {
        int maxm,maxIdx=0;
        path.push_back(weight[idx]);
        for(;maxIdx!=-1;)
        {
            maxm=maxIdx=-1;
            len=link[idx].size();
            for(int i=0;i<len;++i)
            {
                if(flag[link[idx][i]]==false&&weight[link[idx][i]]>maxm)
                {
                    maxIdx=link[idx][i];
                    maxm=weight[link[idx][i]];
                }
            }
            if(maxIdx!=-1)
            {
                flag[maxIdx]=true;
                dfs(weit,maxIdx);
            }
        }
        flag[idx]=true;
        path.pop_back();
    }
    return;
}
int main()
{
    int a,b,k;
    scanf("%d%d%d",&n,&m,&s);
    memset(flag,false,sizeof(flag));
    for(int i=0;i<n;++i)
        scanf("%d",weight+i);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&a,&k);
        for(int j=0;j<k;++j)
        {
            scanf("%d",&b);
            link[a].push_back(b);
        }
    }
    dfs(0,0);
    return 0;
}