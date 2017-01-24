#include <iostream>
#include <vector>
#include <queue>
#include <memory>

using namespace std;

struct Node{
	int val;
	shared_ptr<Node> lchild;
	shared_ptr<Node> rchild;
};

int find(const vector<int>& postorder,const int& val){
	for(int i=0;i<postorder.size();++i){
		if(postorder[i]==val)
			return i;
	}
}

shared_ptr<Node> buildtree(const vector<int>& postorder,int pb,int pe,const vector<int>& inorder,int ib,int ie){
	shared_ptr<Node> root(new Node);
	//必须把这个指针开在heap上
	if(pb>pe)
		return NULL;
	int loc=find(inorder,postorder[pe]);
	
	root->val=inorder[loc];
	root->lchild=buildtree(postorder,pb,pe-ie+loc-1,inorder,ib,loc-1);
	root->rchild=buildtree(postorder,pe-ie+loc,pe-1,inorder,loc+1,ie);

	return root;
}

void BFS(shared_ptr<Node> root,vector<int>& levelorder){
	queue<shared_ptr<Node>> q;
	q.push(root);
	shared_ptr<Node> pn;
	while(!q.empty()){
		pn=q.front();
		levelorder.push_back(pn->val);
		q.pop();
		if(pn->lchild)
			q.push(pn->lchild);
		if(pn->rchild)
			q.push(pn->rchild);
	}
}

int main(){
	int n;
	cin>>n;
	if(n==0)
		return 0;
	vector<int> postorder(n);
	vector<int> inorder(n);

	for(int i=0;i<n;++i){
		cin>>postorder[i];
	}
	for(int i=0;i<n;++i){
		cin>>inorder[i];
	}
	shared_ptr<Node> root=buildtree(postorder,0,n-1,inorder,0,n-1);
	
	vector<int> levelorder;
	BFS(root,levelorder);
	
	cout<<levelorder[0];
	for(int i=1;i<n;++i){
		cout<<" "<<levelorder[i];
	}
	cout<<endl;
	
	return 0;
}
