//Backtracking
//下一级：本节点的相邻单元
//剪枝条件：
//1.距离已大于当前的最小距离
//2.携带的自行车已大于当前最少自行车需求
//3.相邻的节点已经走过
//4.已经到达终点

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0xFFFF 
using namespace std;

struct Node{
	int bike;
	vector<int> neighb;
	vector<int> weight;
};


void backtrack(const int& a,const int& end,const int& capacity,int& dist,int& carry,int& bike,int& mindist,int& mincarry,int& minbike,vector<int>& visited,vector<int>& route, const vector<Node>& nodes){
	/*cout<<"visited=";
	for(int j=0;j<visited.size();++j){
		cout<<visited[j]<<" ";
	}
	cout<<endl;
	cout<<"a="<<a<<" dist="<<dist<<" carry="<<carry<<" bike="<<bike<<endl;
	cout<<"mindist="<<mindist<<" mincarry="<<mincarry<<" minbike="<<minbike<<endl;
	
	*/
	if(a==end){
		if(dist < mindist ||(dist== mindist && carry < mincarry) || (dist==mindist && carry==mincarry && bike<minbike)){
			mindist=dist;
			mincarry=carry;
			route=visited;
			minbike=bike;
		}
		return;
	}else{
		for(int i=0;i<nodes[a].neighb.size();++i){
			int half=capacity/2;
			int ii=nodes[a].neighb[i];
			//cout<<"ii="<<ii<<endl;
			//cout<<(find(visited.begin(),visited.end(),ii)==visited.end())<<" "<<(dist<=mindist)<<" "<<(carry<=mincarry)<<endl;
			if((find(visited.begin(),visited.end(),ii)==visited.end()) && (dist<=mindist) && (carry<=mincarry)){
				dist += nodes[a].weight[i];
				int plus=half-nodes[ii].bike-bike;
				int oldcarry=carry;
				int oldbike=bike;
				if(plus>0){
					carry += plus;
					bike=0;
				}else{
					bike = -plus;
				}
				visited.push_back(ii);
				backtrack(ii,end,capacity,dist,carry,bike,mindist,mincarry,minbike,visited,route,nodes);
				dist  -= nodes[a].weight[i];
				carry = oldcarry;
				bike = oldbike;
				visited.pop_back();
			}	
		}
	}	
}

int main(){
	int cmax,n,sp,m;
	cin>>cmax>>n>>sp>>m;
	vector<Node> nodes(n+1);
	nodes[0].bike=INF;
	//cout<<nodes[0].bike<<endl;
	for(int i=0;i<n;++i){
		cin>>nodes[i+1].bike;
	}
	int n1,n2,wt;
	for(int i=0;i<m;++i){
		cin>>n1>>n2>>wt;
		nodes[n1].neighb.push_back(n2);
		nodes[n1].weight.push_back(wt);
		nodes[n2].neighb.push_back(n1);
		nodes[n2].weight.push_back(wt);
	}
	vector<int> visited;
	int start = 0;
	int dist =0;
	int carry =0;
	int bike =0;
	int mindist=INF;
	int mincarry=INF;
	int minbike=INF;
	vector<int> route;
	visited.push_back(0);
	route.push_back(0);
	backtrack(start,sp,cmax,dist,carry,bike,mindist,mincarry,minbike,visited,route,nodes);
	cout<<mincarry<<" ";
	for(int i=0;i<route.size()-1;++i){
		cout<<route[i]<<"->";
	}
	cout<<route[route.size()-1]<<" ";
	cout<<minbike<<endl;
	return 0;
}