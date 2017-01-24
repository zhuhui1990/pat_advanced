//Dijkstra，时间复杂度O(n)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

const int inf=0xffffff;


void dijkstra(const int& s,const int& d,const vector<vector<int>>& mat1,const vector<vector<int>>& mat2,vector<int>& d1,vector<int>& d2,vector<int>& prev,vector<bool>& visited){
	int n=visited.size();
	for(int i=0;i<n;++i){
		visited[i]=false;
	}
	for(int i=0;i<n;i++){ //初始化
    d1[i]=mat1[s][i];
    d2[i]=mat2[s][i];
    if(d1[i]!=inf){
    	prev[i]=s;
    }else{
    	prev[i]=-1;
    }
  }
	d1[s]=0;
	visited[s]=true;
	int v=s,localmin;
	while(v!=d){
		localmin=inf;
		for(int i=0;i<n;++i){
			if(!visited[i] && d1[i]<localmin){
        v=i;
        localmin=d1[i];
      }
		}
		visited[v]=true;
		for(int i=0;i<n;i++){
			if(!visited[i]){
				if(d1[v]+mat1[v][i]<d1[i]){
					d1[i]=d1[v]+mat1[v][i];
					d2[i]=d2[v]+mat2[v][i];
					prev[i]=v;
				}else if(d1[v]+mat1[v][i]==d1[i] && d2[v]+mat2[v][i]<d2[i]){
					d2[i]=d2[v]+mat2[v][i];
					prev[i]=v;
				}
			}
		}
	}

}

vector<int> getroute(const int& d,const vector<int>& prev){
	vector<int> res;
	int a=d;
	while(a!=-1){
		res.push_back(a);
		a=prev[a];
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(){
	const int inf=0xffffff;
	int n,m;
	cin>>n>>m;
	vector<vector<int>> matdist(n,vector<int>(n,inf));
	vector<vector<int>> mattime(n,vector<int>(n,inf));
	vector<vector<int>> matconnect(n,vector<int>(n,inf));
	
	int c1,c2,oneway,dist,time;
	for(int i=0;i<m;++i){
		cin>>c1>>c2>>oneway>>dist>>time;
		matdist[c1][c2]=dist;
		mattime[c1][c2]=time;
		matconnect[c1][c2]=1;
		if(oneway == 0){
			matdist[c2][c1]=dist;
			mattime[c2][c1]=time;
			matconnect[c2][c1]=1;
		}
	}
	int start,end;
	cin>>start>>end;
	vector<bool> visited(n);
	vector<int> prev1(n),prev2(n);
	vector<int> dists(n),times(n),connects(n);
	
	dijkstra(start,end,matdist,mattime,dists,times,prev1,visited);
	dijkstra(start,end,mattime,matconnect,times,connects,prev2,visited);
	
	vector<int> route_short=getroute(end,prev1);
	vector<int> route_fast=getroute(end,prev2);
	
	int mind=dists[end];
	int mint=times[end];
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
