#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1005;
int wt[maxn];
int rank1[maxn];


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,m;
	queue<int> order;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&wt[i]);
	}
	int od;
	for(int i=0;i<n;++i){
		
		scanf("%d",&od);
		order.push(od);
	}
	
	while(order.size() > 1){
		int gamecount = order.size()/m;
		if(order.size()%m != 0){
			++gamecount;
		}
		int currank = gamecount+1;
		queue<int> tmp; //±¾ÂÖ»ñÊ¤Õß
		for(int i=0;i<gamecount;++i){
			int max=-1,maxindex=-1;
			for(int j=i*m;j< i*m+m && order.size()!=0;++j){
				int index=order.front();
				order.pop();
				if(wt[index]>max){
					max=wt[index];
					if(maxindex != -1){
						rank1[maxindex] = currank;
					}
					maxindex = index;
				}else{
					rank1[index] = currank;
				}
			} 
			tmp.push(maxindex);
		}
		order = tmp;
	}
	
	rank1[order.front()] = 1;
	printf("%d",rank1[0]);
	for(int i=1;i<n;++i){
		printf(" %d",rank1[i]);
	}
	printf("\n");
	
	return 0;
}