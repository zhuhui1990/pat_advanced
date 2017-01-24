#include <iostream>
#include <vector>

using namespace std;

struct Node{
	int id;
	vector<Node*> child;
	int level;
};

void computeLevels(vector<Node>& nodes,int& maxlevel){
	vector<Node*> stack; //DFS
	stack.push_back(&nodes[1]);
	while(stack.empty()==false){
		Node* pt=stack.back();
		stack.pop_back();
		int sz=pt->child.size();
		int lvl=pt->level;
		if(lvl>maxlevel)
			maxlevel=lvl;
		for(int i=0;i<sz;++i){
			stack.push_back(pt->child[i]);
			pt->child[i]->level=lvl+1;
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<Node> nodes(n+1);
	int temp1,temp2,temp3;
	for(int i=0;i<m;++i){
		cin>>temp1>>temp2;
		nodes[temp1].child.resize(temp2);
		for(int j=0;j<temp2;++j){
			cin>>temp3;
			nodes[temp1].child[j]=&nodes[temp3];
		}
	}
	nodes[1].level=0;
	int maxlevel=0;
	computeLevels(nodes,maxlevel);
	vector<int> leaves(maxlevel+1);
	//cout<<"maxlevel="<<maxlevel;
	for(int i=1;i<n+1;++i){
	//cout<<"i="<<i<<" level="<<nodes[i].level<<endl;
		if(nodes[i].child.empty() == true){
			int lvl=nodes[i].level;
			++leaves[lvl];
		}
	}
	for(int i=0;i<maxlevel;++i){
		cout<<leaves[i]<<" ";
	}
	cout<<leaves[maxlevel]<<endl;
	return 0;
}