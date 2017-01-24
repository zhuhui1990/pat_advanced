#include <cstdio>
#include <vector>
using namespace std;

int findNotOK(const vector<int>& vec,int begin,int end){
	for(int i=begin;i<end;++i){
		if(vec[i]!=i){
			return i;
		}
	}
	return 0;
}

int main(){
	int n;
	scanf("%d",&n);
	vector<int> arr(n);
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	int cnt=0;
	int firstPos=1;
	firstPos = findNotOK(arr,firstPos,n);
	int tmp;
	while(firstPos != 0){
		if(arr[0] == 0){
			arr[0]=arr[firstPos];
			arr[firstPos]=0;
			++cnt;
		}
		while(arr[0]!=0){
			tmp = arr[0];
			arr[0] = arr[tmp];
			arr[tmp] = tmp;
			++cnt;
		}
		firstPos = findNotOK(arr,firstPos,n);
	}
	printf("%d\n",cnt);
	return 0;
}