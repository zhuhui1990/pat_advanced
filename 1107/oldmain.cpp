//²¢²é¼¯
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int find(int x,vector<int>& pre){
	int r=x;
	while(pre[r]!=r){
		r=pre[r];
	}
	int i=x,j;
	while(i != r){
		j=pre[i];
		pre[i]=j;
		i=j;
	}
	return r;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	vector<unordered_set<int>> vec(n);
	int n1,n2;
	for(int i=0;i<n;++i){
		scanf("%d:",&n1);
		for(int j=0;j<n1;++j){
			scanf("%d",&n2);
			//cout<<"i="<<i<<" n1="<<n1<<" n2="<<n2<<endl;
			vec[i].insert(n2);
		}
	}
	vector<int> pre(n);
	for(int i=0;i<n;++i){
		pre[i]=i;
	}
	for(int i=0;i<n;++i){
		bool flag=false;
		for(auto it=vec[i].begin();it!=vec[i].end();++it){
			for(int j=0;j<i;++j){				
				if(vec[j].find(*it)!=vec[j].end()){
					//pre[i]=j;
					int fx=find(i,pre),fy=find(j,pre);
					if(fx!=fy){
						pre[fx]=fy;
					}
					flag=true;
					break;
				}

			}
			if(flag){
				break;
			}	
		}
	}
		
	int cnt=0;
	vector<int> res(n,0);
	for(int i=0;i<n;++i){
		if(pre[i]==i){
			++cnt;
			++res[i];
		}else{
			++res[pre[i]];
		}
	}
	/*
	for(int i=0;i<n;++i){
		cout<<"i="<<i<<" pre[i]="<<pre[i]<<" res[i]="<<res[i]<<endl;
	}
	*/
	printf("%d\n",cnt);
	sort(res.begin(),res.end());
	printf("%d",res[n-1]);
	for(int i=1;i<cnt;++i){
		printf(" %d",res[n-i-1]);
	}
	printf("\n");
	
	return 0;
}	