#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,l;
	scanf("%d %d",&n,&l);
	vector<vector<int>> follower(n+1);
	int sz,id;
	for(int i=1;i<=n;++i){
		scanf("%d",&sz);
		for(int j=0;j<sz;++j){
			scanf("%d",&id);
			follower[id].push_back(i);
		}
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;++i){
		scanf("%d",&id);
		vector<int> res;
		vector<int> level(n);
		vector<bool> flag(n,false);
		//BFS
		queue<int> q;
		q.push(id);
		level[id]=0;
		flag[id]=true;
		int id1;
		while(!q.empty()){
			id1=q.front();
			//cout<<"id1="<<id1<<endl;
			q.pop();
			for(auto c:follower[id1]){
				//cout<<"c="<<c<<" ";
				if(!flag[c]){
					level[c] = level[id1]+1;
					flag[c] = true;
					if(level[c]<=l){
						res.push_back(c);
						if(level[c]<l){
							q.push(c);
						}
					}
					
				}
			}
			//cout<<endl;
		}
		//for(auto c:res){
		//cout<<c<<" ";
		//}
		//cout<<endl;
		cout<<res.size()<<endl;
	}
}