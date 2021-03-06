#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdio>

using namespace std;

struct Node{
	int addr;
	int val;
	int next;
};

inline int abs(int a){
	return a > 0 ? a : -a;
}

int main(){
	int head,n;
	cin>>head>>n;
	vector<Node> nodes(100005);
	Node nd;
	for(int i=0;i<n;++i){
		cin>>nd.addr>>nd.val>>nd.next;
		nodes[nd.addr]=nd;
	}

	unordered_set<int> nums; 
	vector<Node> list1,list2;
	int pos=head;
	int num;
	while(pos!=-1){
		//cout<<"pos="<<pos<<endl;
		num=abs(nodes[pos].val);
		if(nums.find(num)==nums.end()){
			list1.push_back(nodes[pos]);
			nums.insert(num);
		}else{
			list2.push_back(nodes[pos]);
		}
		pos=nodes[pos].next;
	}
	for(int i=0;i<list1.size();++i){
		if(i+1<list1.size()){
			printf("%05d %d %05d\n",list1[i].addr,list1[i].val,list1[i+1].addr);
		}else{
			printf("%05d %d -1\n",list1[i].addr,list1[i].val);
		}
	}
	for(int i=0;i<list2.size();++i){
		if(i+1<list2.size()){
			printf("%05d %d %05d\n",list2[i].addr,list2[i].val,list2[i+1].addr);
		}else{
			printf("%05d %d -1\n",list2[i].addr,list2[i].val);
		}
	}
	
	return 0;
}