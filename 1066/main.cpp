#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
	int val;
	int ht;
	Node* lc;
	Node* rc;
};

int height(Node* anode){
	if(anode == NULL){
		return 0;
	}
	return anode->ht;
}

int adjHeight(Node* anode){
	return max(height(anode->lc),height(anode->rc))+1;
}

Node* RotateRR(Node* anode){
	Node* bnode = anode->lc;
	anode->lc = bnode->rc;
	bnode->rc = anode;
	anode->ht = adjHeight(anode);
	bnode->ht = adjHeight(bnode);
	return bnode;
}

Node* RotateLL(Node* anode){
	Node* bnode = anode->rc;
	anode->rc = bnode->lc;
  bnode->lc = anode;
  anode->ht = adjHeight(anode);
  bnode->ht = adjHeight(bnode);
  return bnode;
}

Node* RotateLR(Node* anode){
	anode->lc = RotateLL(anode->lc);
	return RotateRR(anode);
}

Node* RotateRL(Node* anode){
	anode->rc = RotateRR(anode->rc);
	return RotateLL(anode);
}

Node* insert(Node* tree,int key){
	if(tree == NULL){
		tree = new Node;
		tree->val = key;
		tree->ht = 1;
		tree->lc = tree->rc = NULL;
	}else if(key > tree->val){
		tree->rc = insert(tree->rc,key);
		int balance = height(tree->rc) - height(tree->lc);
		if(balance == 2){
			if(key > tree->rc->val){
				tree = RotateLL(tree);
			}else{
				tree = RotateRL(tree);
			}
		}
	}else if(key < tree->val){
		tree->lc = insert(tree->lc,key);
		int balance = height(tree->lc) - height(tree->rc);
		if(balance == 2){
			if(key < tree->lc->val){
				tree = RotateRR(tree);
			}else{
				tree = RotateLR(tree);
			}
		}
	}
	tree->ht = adjHeight(tree);
	return tree;
}

int main(){
#ifdef LOCAL
	freopen("input2.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	int val;
	Node* root=NULL;
	for(int i=0;i<n;++i){
		scanf("%d",&val);
		//cout<<"val="<<val<<endl;
		root = insert(root,val);
	}
	cout<<root->val<<endl;
	
	return 0;
}