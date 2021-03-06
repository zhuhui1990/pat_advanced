//直接DFS，会超时
//时间复杂度O(n!)
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Node{
	vector<int> neighb;
	vector<int> dist;
	vector<int> time;
};

int find(const vector<int>& vec,int r){
	for(int i=0;i<vec.size();++i){
		if(vec[i]==r)
			return i;
	}
	return -1;
}


void DFS1(int start,int end,int& d,int& t,int& mind,int& amint,vector<int>& visited,vector<int>& route_short,const vector<Node>& nodes){
	
	if(start==end){
		if(d<mind){
			route_short=visited;
			mind=d;
			amint=t;
		}else if(d==mind){
		//	cout<<"d="<<d<<" t="<<t<<" amint="<<amint<<endl;
			if(t<amint){
				route_short=visited;
				mind=d;
				amint=t;
			}
		}
	}else{
		int c;
		for(int i=0;i<nodes[start].neighb.size();++i){
			c=nodes[start].neighb[i];
			//cout<<"start="<<start<<" end="<<end<<" c="<<c<<endl;
			if(find(visited,c)==-1 && d < mind){
				visited.push_back(c);
				d += nodes[start].dist[i];
				t += nodes[start].time[i];
				if(d<=mind){
					DFS1(c,end,d,t,mind,amint,visited,route_short,nodes);
				}
				visited.pop_back();
				d -= nodes[start].dist[i];
				t -= nodes[start].time[i];
			}
		}
	}
}


void DFS2(int start,int end,int& t,int& mint,vector<int>& visited,vector<int>& route_fast,const vector<Node>& nodes){
	
	if(start==end){
		if(t<mint){
			route_fast=visited;
			mint=t;
		}else if(t==mint){
			if(visited.size()<route_fast.size()){
				route_fast=visited;
				mint=t;
			}
		}
	}else{
		int c;
		for(int i=0;i<nodes[start].neighb.size();++i){
			c=nodes[start].neighb[i];
			//cout<<"start="<<start<<" end="<<end<<" c="<<c<<endl;
			if(find(visited,c)==-1 && t<mint ){
				visited.push_back(c);
				t += nodes[start].time[i];
				if(t<=mint){
					DFS2(c,end,t,mint,visited,route_fast,nodes);
				}
				visited.pop_back();
				t -= nodes[start].time[i];
			}
		}
	}
}

int main(){
	const int inf=0xffffff;
	int n,m;
	cin>>n>>m;
	vector<Node> nodes(n);
	int c1,c2,oneway,dist,time;
	for(int i=0;i<m;++i){
		cin>>c1>>c2>>oneway>>dist>>time;
		nodes[c1].neighb.push_back(c2);
		nodes[c1].dist.push_back(dist);
		nodes[c1].time.push_back(time);
		if(oneway == 0){
			nodes[c2].neighb.push_back(c1);
			nodes[c2].dist.push_back(dist);
			nodes[c2].time.push_back(time);
		}
	}
	int start,end;
	cin>>start>>end;
	vector<int> visited;
	visited.push_back(start);
	vector<int> route_short;
	vector<int> route_fast;
	int d=0,t=0;
	int mind=inf,mint=inf,amint=inf;
	DFS1(start,end,d,t,mind,amint,visited,route_short,nodes);
	visited.clear();
	visited.push_back(start);
	DFS2(start,end,t,mint,visited,route_fast,nodes);
	//cout<<"Distance = "<<mind;
	printf("Distance = %d",mind);
	if(route_short == route_fast){
		//cout<<"; Time = "<<mint<<": ";
		//cout<<route_short[0];
		printf("; Time = %d: %d",mint,route_short[0]);
		for(int i=1;i<route_short.size();++i){
			//cout<<" -> "<<route_short[i];
			printf(" -> %d",route_short[i]);
		}
		//cout<<endl;
		printf("\n");
	}else{
		//cout<<": "<<route_short[0];
		printf(": %d",route_short[0]);
		for(int i=1;i<route_short.size();++i){
			//cout<<" -> "<<route_short[i];
			printf(" -> %d",route_short[i]);
		}
		//cout<<endl;
		printf("\n");
		//cout<<"Time = "<<mint<<": "<<route_fast[0];
		printf("Time = %d: %d",mint,route_fast[0]);
		for(int i=1;i<route_fast.size();++i){
			//cout<<" -> "<<route_fast[i];
			printf(" -> %d",route_fast[i]);
		}
		//cout<<endl;
		printf("\n");
	}
	return 0;
}