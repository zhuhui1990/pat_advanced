#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node{
	int val;
	Node* lchild=NULL;
	Node* rchild=NULL;
	Node* father=NULL;
};

int string2int(const string& s){
	int res=0;
	int a;
	for(int i=s.length()-1;i>=0;--i){
		a = s[i]-'0';
		res = res*10+a;
	}
	return res;
}

void invert(Node* root){
	if(root->lchild==NULL && root->rchild==NULL){
		return;
	}else{
		if(root->lchild){
			invert(root->lchild);
		}
		if(root->rchild){
			invert(root->rchild);
		}
		Node* temp;
		temp=root->lchild;
		root->lchild=root->rchild;
		root->rchild=temp;
	}
}

void levelorder(Node* root){
	queue<Node*> q;
	q.push(root);
	cout<<root->val;
	Node* pn;
	if(root->lchild){
		q.push(root->lchild);
	}
	if(root->rchild){
		q.push(root->rchild);
	}
	q.pop();
	while(!q.empty()){
		pn=q.front();
		q.pop();
		cout<<" "<<pn->val;
		if(pn->lchild){
			q.push(pn->lchild);
		}
		if(pn->rchild){
			q.push(pn->rchild);
		}
	}
}

void inorder(bool& flag,Node* root){
	if(root==NULL)
		return;
	inorder(flag,root->lchild);
	if(flag){
		cout<<" ";
	}
	cout<<root->val;
	flag=true;
	inorder(flag,root->rchild);
}

int main(){
	int n;
	cin>>n;
	string s1,s2;
	int n1,n2;
	vector<Node> nodes(n);
	for(int i=0;i<n;++i){
		nodes[i].val = i;
		cin>>s1>>s2;
		if(s1!="-"){
			n1=string2int(s1);
			nodes[i].lchild=&nodes[n1];
			nodes[n1].father=&nodes[i];
		}
		if(s2!="-"){
			n2=string2int(s2);
			nodes[i].rchild=&nodes[n2];
			nodes[n2].father=&nodes[i];
		}
	}
	Node* root;
	for(int i=0;i<n;++i){
		if(nodes[i].father==NULL){
			root=&nodes[i];
			break;
		}
	}
	invert(root);
	levelorder(root);
	cout<<endl;
	bool flag;
	inorder(flag,root);
	cout<<endl;
	
	return 0;
}