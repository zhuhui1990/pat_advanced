#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
#define maxn 10050
using namespace std;
struct node2         //ÿ������״̬
{
    string id;        //  ����
    int state;        //  1:in  0:out
    int sum;          
    int in_time;     
    int loc;          // ��һ��in����λ��
} ID[maxn];

struct node          //���������Ϣ
{
    int time;
    string id;
    int state;
    int flag;        // ������Ƿ���ȷ
} s[maxn];

map<string,int>q;
set<string>w;

int cmp(node a,node b)
{
    return a.time<b.time;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int n,m;
    int query[maxn*8];
    string str1,str2;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        cin>>s[i].id>>str1>>str2;
        s[i].flag=0;
        s[i].time=((str1[0]-'0')*10+str1[1]-'0')*3600+((str1[3]-'0')*10+str1[4]-'0')*60+((str1[6]-'0')*10+str1[7]-'0');
        s[i].state=str2.compare("in")==0?1:0;
    }

    for(int i=1; i<=m; i++)
    {
        cin>>str1;
        query[i]=((str1[0]-'0')*10+str1[1]-'0')*3600+((str1[3]-'0')*10+str1[4]-'0')*60+((str1[6]-'0')*10+str1[7]-'0');
    }

    sort(s+1,s+1+n,cmp);

    int num=1,Que=1,ss=0,d;
    int ans=0;
    for(int i=1; i<=n; i++)         //��Ǵ�������
    {
        str1=s[i].id;
        if(q[str1]==0)                            //��ǰ����û���ֹ�
        {
            ID[num]= {s[i].id,s[i].state,0,s[i].time,i};
            q[str1]=num++;
        }
        else
        {
            d=q[str1];
            if(ID[d].state==1&&s[i].state==1)      //���inȡ���һ�� ǰ���in��䲻�Ϸ�
            {
                s[ID[d].loc].flag=1;
                ID[d].loc=i;
            }
            else if(ID[d].state==1&&s[i].state==0) //��ȥ
                ID[d].state=0;
            else if(ID[d].state==0&&s[i].state==1)   //�ٴν���
            {
                ID[d].state=1;
                ID[d].loc=i;
            }
            else if(ID[d].state==0&&s[i].state==0)  //���outȡ��ǰһ��
                s[i].flag=1;
        }
    }
    for(int i=1;i<num;i++)
    {
        if(ID[i].state==1)         //��ȥû���� ���Ϸ�
        {
            s[ID[i].loc].flag=1;
            ID[i].state=0;
        }
    }
    for(int i=1; i<=n; i++)         //�����������
    {
        if(s[i].flag)
            continue;
        while(Que<m+1&&query[Que]<s[i].time)  //  while �м�
        {
            Que++;
            printf("%d\n",ss);
        }
        str1=s[i].id;
        d=q[str1];
        if(ID[d].state==1&&s[i].state==0) //���� ��ȥ
        {
            ss--;
            ID[d].state=0;
            ID[d].sum+=s[i].time-ID[d].in_time;
            if(ID[d].sum>ans){
                ans=ID[d].sum;
                w.clear();
                w.insert(ID[d].id);
            }
            else if(ID[d].sum==ans)
                w.insert(ID[d].id);

        }
        else if(ID[d].state==0&&s[i].state==1)   //�ٴν���
        {
            ss++;
            ID[d].state=1;
            ID[d].in_time=s[i].time;
        }

    }
    while(Que<m+1)
    {
        printf("%d\n",ss);
        Que++;
    }
    set<string>::iterator ii;
    for(ii=w.begin();ii!=w.end();ii++)
        cout<<*ii<<" ";
    printf("%02d:%02d:%02d\n",ans/3600,ans%3600/60,ans%60);
    return 0;
}
