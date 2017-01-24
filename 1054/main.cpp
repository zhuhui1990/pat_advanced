#include <iostream>
#include <unordered_map>
#include <cstdio>

using namespace std;

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int all=n*m;
	int half=all/2;
	unordered_map<int,int> color;
	int a;
	for(int i=0;i<all;++i){
		scanf("%d",&a);
		++color[a];
		if(color[a]>half){
			printf("%d\n",a);
			return 0;
		}
	}
	return 0;
}
