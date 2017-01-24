#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Node{
	int addr;
	int val;
	int next;
	bool flag;
};

inline bool operator < (const Node& lhs,const Node& rhs){
	return lhs.val<rhs.val;
}

int main(){
	int n,head;
	scanf("%d %d",&n,&head);
	vector<Node> nodes(100000);
	Node nd;
	vector<Node> newnode;
	for(int i=0;i<n;++i){
		scanf("%d %d %d",&(nd.addr),&(nd.val),&(nd.next));
		nodes[nd.addr]=nd;
	}
	//去掉不在list里的节点
	int addr=head;
	while(addr != -1){
		newnode.push_back(nodes[addr]);
		addr=nodes[addr].next;
	}
	
	
	sort(newnode.begin(),newnode.end());
	n = newnode.size();
	if(n==0){
		printf("0 -1\n");
		return 0;
	}
	printf("%d %05d\n",n,newnode[0].addr);
	for(int i=0;i<n-1;++i){
		printf("%05d %d %05d\n",newnode[i].addr,newnode[i].val,newnode[i+1].addr);
	}
	printf("%05d %d -1\n",newnode[n-1].addr,newnode[n-1].val);
	return 0;
}