#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct Node{
	string addr;
	int val;
	string next;
};

void sortList(const string& head,int& n,vector<Node>& nodes){
	for(int i=0;i<n;++i){
		if(nodes[i].addr == head){
			swap(nodes[0],nodes[i]);
			break;
		}
	}
	
	for(int i=0;i<n-1;++i){
		string next=nodes[i].next;
		if(next=="-1"){
			n=i+1;
			break;
		}
		for(int j=i+1;j<n;++j){
			if(next == nodes[j].addr){
				swap(nodes[j],nodes[i+1]);
				break;
			}
		}
	}
	
}

void reverse(vector<Node>& nodes,const int& start,const int& k){
	int loc1=start,loc2=start+k-1;
	while(loc1<loc2){
		swap(nodes[loc1],nodes[loc2]);
		++loc1;
		--loc2;
	}
	for(int i=start;i<start+k-1;++i){
		nodes[i].next=nodes[i+1].addr;
	}
	if(start+k<nodes.size())
		nodes[start+k-1].next=nodes[start+k].addr;
	else
		nodes[start+k-1].next="-1";
	
	if(start>0)
		nodes[start-1].next=nodes[start].addr;
}

int main(){
	int n,k;
	string head;
	cin>>head>>n>>k;
	if(n==0)
		return 0;
	vector<Node> nodes;
	Node temp;
	for(int i=0;i<n;++i){
		cin>>temp.addr>>temp.val>>temp.next;
		nodes.push_back(temp);
	}
	sortList(head,n,nodes);

	int start=0;
	while(start+k<=n){
		reverse(nodes,start,k);
		start+=k;
	}
	for(int i=0;i<n;++i){
		//cout<<nodes[i].addr<<" "<<nodes[i].val<<" "<<nodes[i].next<<endl;
		printf("%s %d %s\n",nodes[i].addr.c_str(),nodes[i].val,nodes[i].next.c_str());
	}
	return 0;
} 