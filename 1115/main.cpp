//BST的插入：递归算法
//1.如果当前节点值小于待插入节点值：
//  a.左子树为空，新建节点并插入；
//  b.左子树非空，递归进左子树
//2.如果当前节点值大于等于待插入节点值：
//  a.右子树为空，新建节点并插入；
//  b.右子树非空，递归进右子树；
//3.如果当前节点为空，插入节点为根

//算法：
//1.先逐个节点插入BST，获得结构；
//2.获得每个节点的层数


#include <iostream>
#include <vector>
using namespace std;
	
struct Node{
	int val;
	int level;
	Node* lchild=NULL;
	Node* rchild=NULL;
};

void getLevel(int l,int& maxlevel,Node* root){
	if(root==NULL)
		return;
	//cout<<"val="<<root->val<<" l="<<l<<endl;
	root->level = l;
	maxlevel = l>maxlevel?l:maxlevel;
	getLevel(l+1,maxlevel,root->lchild);
	getLevel(l+1,maxlevel,root->rchild);
}

void insert(Node* ins,Node* root){
	if(ins->val <= root->val){
		if(root->lchild == NULL){
			root->lchild = ins;
		}else{
			insert(ins,root->lchild);
		}
	}else{
		if(root->rchild == NULL){
			root->rchild = ins;
		}else{
			insert(ins,root->rchild);
		}
	}
}

void count(const int& maxlevel,int& m1,int& m2,Node* root){
	if(root==NULL)
		return;
	if(root->level == maxlevel){
		++m1;
	}else if(root->level == maxlevel-1){
		++m2;
	}
	count(maxlevel,m1,m2,root->lchild);
	count(maxlevel,m1,m2,root->rchild);
}

int main(){
	int n;
	cin>>n;
	vector<Node> nodes(n);
	for(int i=0;i<n;++i){
		cin>>nodes[i].val;
	}
	Node* root=&nodes[0];
	for(int i=1;i<n;++i){
		insert(&nodes[i],root);
	}
	int maxlevel=0;
	getLevel(0,maxlevel,root);
	int m1=0,m2=0;
	//cout<<"maxlevel="<<maxlevel<<endl;
	count(maxlevel,m1,m2,root);
	cout<<m1<<" + "<<m2<<" = "<<m1+m2<<endl;
	return 0;
}
