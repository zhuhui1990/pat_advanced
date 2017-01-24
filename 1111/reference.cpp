#include <cstdio>
#define INF 999999999
int n,m,d,s;
int len[500][500],dist[500],dlast[500];
int tm[500][500],time[500],tlast[500];
bool visited[500];
void dijkstra(int mp1[][500],int mp2[][500],int d1[],int last[]){  //d1[]为第一个判断条件，last[]为上一步
  int d2[500];  //d2[]为第二个判断条件
  for(int i=0;i<n;i++) visited[i]=false;
  for(int i=0;i<n;i++){
    d1[i]=mp1[s][i];
    last[i]=s;
    d2[i]=mp2[s][i];
  }
  visited[s]=true;d1[s]=0;d2[s]=0;
  int v=s;
  while(v!=d){
    int min=INF;
    for(int i=0;i<n;i++)
      if(!visited[i] && d1[i]<min){
        v=i;
        min=d1[i];
      }
    visited[v]=true;
    for(int i=0;i<n;i++)
      if(!visited[i]){
        if(d1[v]+mp1[v][i]<d1[i]){
          d1[i]=d1[v]+mp1[v][i];
          d2[i]=d2[v]+mp2[v][i];
          last[i]=v;
        }
        else if(d1[v]+mp1[v][i]==d1[i] && d2[v]+mp2[v][i]<d2[i]){
          d2[i]=d2[v]+mp2[v][i];
          last[i]=v;
        }
      }
  }
}
void output(int *last){
  int step[500],pos=0;
  for(int i=d;i!=s;i=last[i],pos++)
    step[pos]=i;
  for(int i=pos-1;i>=0;i--)
    printf(" -> %d",step[i]);
  printf("\n");
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      len[i][j]=tm[i][j]=INF;
  for(int i=0;i<m;i++){
    int v1,v2,oneway;
    scanf("%d%d",&v1,&v2);
    scanf("%d%d%d",&oneway,&len[v1][v2],&tm[v1][v2]);
    if(!oneway){
      len[v2][v1]=len[v1][v2];
      tm[v2][v1]=tm[v1][v2];
    }
  }
  scanf("%d%d",&s,&d);
  if(s==d) printf("Distance = 0; Time = 0: %d -> %d",s,d);
  dijkstra(len,tm,dist,dlast);
  int cnt[500][500];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cnt[i][j]=1;
  dijkstra(tm,cnt,time,tlast);
  bool identical=true;
  for(int i=d;i!=s && identical;i=dlast[i])
    if(dlast[i]!=tlast[i]){
      identical=false;
    }
  if(identical){
    printf("Distance = %d; Time = %d: %d",dist[d],time[d],s);
    output(dlast);
  }
  else{
    printf("Distance = %d: %d",dist[d],s);
    output(dlast);
    printf("Time = %d: %d",time[d],s);
    output(tlast);
  }
  return 0;
}