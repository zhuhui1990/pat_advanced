//DFS
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Node{
	int wt;
	vector<int> child;
	Node():wt(0),child(){
	}
};

vector<vector<int>> res;
vector<int> visited;
int sum=0;


void DFS(int i,const int& s,const vector<Node>& nodes){
	//cout<<"i="<<i<<" sum="<<sum<<endl;
	if(i < 0 || i >= nodes.size()){
		return;
	}
	if(sum == s && nodes[i].child.size()==0){
		//cout<<"i="<<i<<" visited.size()="<<visited.size()<<endl;
		res.push_back(visited);
	}else{
		for(int j=0;j<nodes[i].child.size();++j){
			int id=nodes[i].child[j];
			if(id < 0 || id >= nodes.size()){
				continue;
			}
			//cout<<"    j="<<j<<" id="<<id<<endl;
			if(sum < s){
				sum += nodes[id].wt;
				visited.push_back(nodes[id].wt);
				DFS(id,s,nodes);
				sum -= nodes[id].wt;
				visited.pop_back();
			}
		}
	}	
}
/*
bool operator < (const vector<int>& lhs, const vector<int>& rhs){
	int sz=min(lhs.size(),rhs.size());
	if(sz==0){
		return true;
	}
	for(int i=0;i<sz;++i){
		if(lhs[i] != rhs[i]){
			return lhs[i]>rhs[i];
		}
	}
	return true;
}
*/
int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,m,s;
	scanf("%d %d %d",&n,&m,&s);
	//cout<<"n="<<n<<" m="<<m<<" s="<<s<<endl;
	if(n==0){
		return 0;
	}
	vector<Node> nodes(n);
	for(int i=0;i<n;++i){
		scanf("%d",&nodes[i].wt);
	}
	int id,sz;
	for(int i=0;i<m;++i){
		scanf("%d %d",&id,&sz);
		nodes[id].child.resize(sz);
		for(int j=0;j<sz;++j){
			scanf("%d",&nodes[id].child[j]);
		}
	}
	//cout<<nodes[7].child[0]<<" "<<nodes[7].child[1]<<endl;
	visited.push_back(nodes[0].wt);
	sum = nodes[0].wt;
	DFS(0,s,nodes);
	//for(int i=0;i<res.size();++i){
	//	cout<<"i="<<i<<" sz="<<res[i].size()<<endl;
	//}
	if(res.size()>0){
		sort(res.begin(),res.end());
		for(int i=res.size()-1;i>=0;--i){
			if(res[i].size()>0){
				printf("%d",res[i][0]);
				for(int j=1;j<res[i].size();++j){
					printf(" %d",res[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
