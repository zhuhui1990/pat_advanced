//Dijkstra
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int inf=0x7fffff;

struct Node{
	vector<int> nb;
	vector<int> dist;
};

int str2int(char* s,int begin,int end){
	int res = 0;
	while(begin != end){
		res = res * 10 + s[begin] -'0';
		++begin;
	}
	return res;
}

struct Point
{
    int id;
    int aver;
    int minx;
    Point(int id,int minx,int aver):id(id),aver(aver),minx(minx){
    }
};

bool cmp(const Point &a,const Point &b)
{
    return a.minx==b.minx?(a.aver==b.aver?(a.id<b.id):(a.aver<b.aver)):(a.minx>b.minx);
}

void dijkstra(int src,int n,int m,vector<bool>& visited,vector<int>& dist,const vector<Node>& nodes){
	fill_n(visited.begin(),n+m,false);
	fill_n(dist.begin(),n+m,inf);
	for(int i=0;i<nodes[src].nb.size();++i){//³õÊ¼»¯¾àÀë
		int j = nodes[src].nb[i];
		dist[j] = nodes[src].dist[i];
	}
	dist[src] = 0;
	visited[src] = true;
	for(int i=1;i<n+m;++i){
		int mindist = inf;
		int u = src;
		for(int j=0;j<n+m;++j){
			if(!visited[j] && dist[j]<mindist){
				u = j;
				mindist = dist[j];
			}
		}
		visited[u] = true;
		for(int j=0;j<nodes[u].nb.size();++j){
			int nd=nodes[u].nb[j];
			if(!visited[nd]){
				if(dist[u]+nodes[u].dist[j]<dist[nd]){
					dist[nd] = dist[u]+nodes[u].dist[j];
				}
			}
		}
	}
}


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,m,k,ds;
	scanf("%d %d %d %d",&n,&m,&k,&ds);
	vector<Node> nodes(n+m);
	vector<bool> visited(n+m);
	vector<int>  dist(n+m);
	vector<Point> pt;
	int node1,node2,dist1;
	char s1[5],s2[5];
	for(int i=0;i<k;++i){
		scanf("%s %s %d",s1,s2,&dist1);
		if(s1[0] == 'G'){
			node1 = n + str2int(s1,1,strlen(s1))-1;
		}else{
			node1 = str2int(s1,0,strlen(s1))-1;
		}
		if(s2[0] == 'G'){
			node2 = n + str2int(s2,1,strlen(s2))-1;
		}else{
			node2 = str2int(s2,0,strlen(s2))-1;
		}
		//cout<<node1<<" "<<node2<<endl;
		nodes[node1].nb.push_back(node2);
		nodes[node1].dist.push_back(dist1);
		nodes[node2].nb.push_back(node1);
		nodes[node2].dist.push_back(dist1);
	}
	int best=inf;
	int mind=0;
	int avgd=inf;
	for(int i=0;i<m;++i){
		dijkstra(n+i,n,m,visited,dist,nodes);
		/*
		cout<<"i="<<i<<endl;
		for(int j=0;j<n+m;++j){
			cout<<"j="<<j<<" dist[j]="<<dist[j]<<endl;
		}
		*/
		int maxdist = 0;	
		bool possible = true;
		for(int j=0;j<n;++j){
			if(maxdist <  dist[j]){
				maxdist = dist[j];
			}
			if(maxdist > ds){
				possible = false;
				break;
			}
		}
		if(possible){
			int mindist = inf;
			double avgdist = 0.;
			for(int j=0;j<n;++j){
				avgdist += dist[j];
				if(mindist > dist[j]){
					mindist = dist[j];
				}
			}
			pt.push_back(Point(i,mindist,avgdist));
			//cout<<"i="<<i<<" maxdist="<<maxdist<<" mindist="<<mindist<<" avgdist="<<avgdist<<endl;
			/*
			if(mindist > mind){
				mind = mindist;
				best = i;
				avgd = avgdist;
			}else if (mindist == mind){
				if(avgd > avgdist){
					avgd = avgdist;
					best = i;
				}
			}
			*/
		}
	}
	if(pt.size()==0){
		printf("No Solution\n");
	}else{
		sort(pt.begin(),pt.end(),cmp);
		printf("G%d\n",pt[0].id+1);
		printf("%.1lf %.1lf\n",double(pt[0].minx),double(pt[0].aver)/double(n));
	}
	
	return 0;
}