//DP
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,m,l;
	scanf("%d",&n);
	scanf("%d",&m);
	vector<int> s1(m);
	for(int i=0;i<m;++i){
		scanf("%d",&s1[i]);
	}
	scanf("%d",&l);
	vector<int> s2(l);
	for(int i=0;i<l;++i){
		scanf("%d",&s2[i]);
	}
	vector<vector<int>> dp(m+1,vector<int>(l+1,-1));
	for(int i=0;i<m+1;++i){
		dp[i][0] = 0;
	}
	for(int i=0;i<l+1;++i){
		dp[0][i] = 0;
	}
	
	for(int i=1;i<m+1;++i){
		for(int j=1;j<l+1;++j){
			if(s1[i-1] == s2 [j-1]){
				dp[i][j] = dp[i][j-1]+1;
			}else{
				dp[i][j] = dp[i-1][j] > dp[i][j-1] ?  dp[i-1][j] : dp[i][j-1];
			}
		}
	}
	printf("%d\n",dp[m][l]);
	return 0;
}
