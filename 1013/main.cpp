//Union Find
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int find(int x,vector<int>& pre){
	int r=x;
	while(pre[r]!=r){
		r=pre[r];
	}
	//Â·¾¶Ñ¹Ëõ
	int i=x,j;
	while(i!=r){
		j=pre[i];
		pre[i]=r;
		i=j;
	}
	return r;
}

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> pre(n+1,0);

	int c1,c2;
	vector<pair<int,int>> roads;
	for(int i=0;i<m;++i){
		cin>>c1>>c2;
		roads.push_back({c1,c2});
	}
	
	for(int i=0;i<k;++i){
		int c;
		cin>>c;
		for(int j=1;j<=n;++j){
			pre[j]=j;
		}

		for(int j=0;j<m;++j){
			if(roads[j].first==c || roads[j].second==c){
				continue;
			}else{
				int f1=find(roads[j].first,pre);
				int f2=find(roads[j].second,pre);
				if(f1!=f2){
					pre[f2]=f1;
				}
			}							
		}
		int cnt=0;
		for(int j=1;j<=n;++j){
			if(pre[j]==j && j!=c){
				++cnt;
			}
		}
		cout<<cnt-1<<endl;
	}
	
	
	
	return 0;
}