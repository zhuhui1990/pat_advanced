//±≥∞¸Œ Ã‚
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> coin(n+1);
	for(int i=0;i<n;++i){
		scanf("%d",&coin[i+1]);
	}
	sort(coin.begin()+1,coin.end(),greater<int>());
	vector<vector<int>> f(n+1,vector<int>(m+1,0));
	vector<vector<bool>> has(n+1,vector<bool>(m+1,false));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(j-coin[i] < 0){
				f[i][j] = f[i-1][j];
			}else{
				if(f[i-1][j] <= f[i-1][j-coin[i]]+coin[i]){
					has[i][j] = true;
					f[i][j] = f[i-1][j-coin[i]]+coin[i];
				}else{
					f[i][j] = f[i-1][j];
				}
			}
			//cout<<"i="<<i<<" j="<<j<<" f[i][j]="<<f[i][j]<<endl;
		}
	}
	/*
	for(int i=1;i<=n;++i){
		cout<<"i="<<i<<" has[i][m]="<<has[i][m]<<endl;
	}
	*/
	if(f[n][m]!=m){
		printf("No Solution\n");
	}else{
		vector<int> v;
		while(m){
			while(!has[n][m]){
				--n;
			}
			v.push_back(coin[n]);
			m -= coin[n];
			--n;
		}
		printf("%d",v[0]);
		for(int i=1;i<v.size();++i){
			printf(" %d",v[i]);
		}
		printf("\n");
	}
	return 0;
}