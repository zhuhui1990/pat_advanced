#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 100005;
const int inf  = 0x7fffffff; //inf要开到足够大

int sum[maxn],dest[maxn];

//二分查找从i位置开始最优的解
int findBestSum(int i,int n,int m){
	int left = i+1;
	int right = n;
	int mid;
	while(left < right){
		mid = (left + right)/2;
		if(sum[mid]-sum[i] >= m){
			right = mid;
		}else{
			left = mid+1;
		}
	}
	dest[i] = right;
	return sum[right]-sum[i];
}


int main(){
#ifdef LOCAL
	freopen("input2.txt","r",stdin);
#endif
	int n,m;
	scanf("%d %d",&n,&m);
	sum[0]=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&sum[i]);
		sum[i] = sum[i]+sum[i-1];
	}
	
	vector<int> vec;
	int res,mm;
	mm= inf;
	for(int i=0;i<n;++i){
		res=findBestSum(i,n,m);
		//cout<<"i="<<i<<" res="<<res<<" m="<<m<<endl;
		if(res >= m){
			if(res == mm){
				vec.push_back(i);
			}else if(res < mm){
				mm = res;
				vec.clear();
				vec.push_back(i);
			}
		}else{
			break;
		}		
	}
	
	for(int i=0;i<vec.size();++i){
		printf("%d-%d\n",vec[i]+1,dest[vec[i]]);
	}
	
	
	
	
	
	return 0;
}