//����һ�β��鼯���ҵ����ڵ�
//Ȼ��������DFS
//��һ�δ��ҵ��ĸ��ڵ㿪ʼ����¼������Զ�ĵ�
//�ڶ��δ������Զ�㿪ʼ����������Զ��
#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Node{
	int val;
	vector<Node*> neighbour;
	Node* father;
};

Node* find(Node* node){
	Node* root=node;
	while(root->father != root){
		root=root->father;
	}
	//·��ѹ��
	Node* nodei=node,*nodej;
	while(nodei!=root){
		nodej=nodei->father;
		nodei->father=root;
		nodei=nodej;
	}
	return root;
}

void join(Node* nodex,Node* nodey){
	Node* fx=find(nodex);
	Node* fy=find(nodey);
	if(fx!=fy){
		fx->father=fy;
	}
}

void DFS1(int i,int level,int& maxlevel,vector<Node>& nodes,vector<bool>& visited,set<int>& deeproots){
	if(level>maxlevel){
		deeproots.clear();
		deeproots.insert(i);
		maxlevel=level;
	}else if(level==maxlevel){
		deeproots.insert(i);
	}
	//cout<<"i="<<i<<" level="<<level<<" maxlevel="<<maxlevel<<endl;
	for(auto it=nodes[i].neighbour.begin();it!=nodes[i].neighbour.end();++it){
		int k=(*it)->val;
		if(!visited[k]){
			visited[k]=true;
			DFS1(k,level+1,maxlevel,nodes,visited,deeproots);
			visited[k]=false; //�����������visited�ĳ�false����DFS�ĵݹ��ԣ�
		}
	}
}




int main(){
	int n;
	cin>>n;
	vector<Node> nodes(n+1);
	for(int i=1;i<n+1;++i){
		nodes[i].val=i;
		nodes[i].father=&nodes[i];
	}
	int i1,i2;
	while(cin>>i1>>i2){
		nodes[i1].neighbour.push_back(&nodes[i2]);
		nodes[i2].neighbour.push_back(&nodes[i1]);
		join(&nodes[i1],&nodes[i2]);
	}
	
	set<Node*> roots;
	for(int i=1;i<n+1;++i){
		roots.insert(find(&nodes[i]));
	}
	
	if(roots.size()>1){
		cout<<"Error: "<<roots.size()<<" components"<<endl;
		return 0;
	}else{
		int maxlevel=0;
		int maxloc=(*roots.begin())->val;
		vector<bool> visited(n+1);
		visited[maxloc]=true;
		set<int> deeproots;
		DFS1(maxloc,0,maxlevel,nodes,visited,deeproots);
		visited[maxloc]=false;
		set<int> res=deeproots;
		visited[*deeproots.begin()]=true;
		DFS1(*deeproots.begin(),0,maxlevel,nodes,visited,deeproots);
		visited[*deeproots.begin()]=false;
		for(auto it=deeproots.begin();it!=deeproots.end();++it){
			res.insert(*it);
		}
		for(auto it=res.begin();it!=res.end();++it){
			cout<<*it<<endl;
		}
	}
	
	return 0;
}