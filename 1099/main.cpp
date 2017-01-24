//步骤
//1.获取树的结构
//2.中序遍历树，获得从小到大的排序
//3.将数组从小到大排序
//4.依次填入树的节点
//5.用队列层序输出

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node{
	int val;
	Node* lchild;
	Node* rchild;
	Node* father=NULL;
};

void inOrder(vector<Node*>& order ,Node* root){
	if(root == NULL)
		return;
	inOrder(order,root->lchild);
	order.push_back(root);
	inOrder(order,root->rchild);
}

int main(){
	int n;
	cin>>n;
	vector<Node> nodes(n);
	int c1,c2;
	for(int i=0;i<n;++i){
		cin>>c1>>c2;
		if(c1!=-1){
			nodes[i].lchild=&nodes[c1];
			nodes[c1].father=&nodes[i];
		}else{
			nodes[i].lchild=NULL;
		}
		if(c2!=-1){
			nodes[i].rchild=&nodes[c2];
			nodes[c2].father=&nodes[i];
		}else{
			nodes[i].rchild=NULL;
		}
	}
	Node* root;
	for(int i=0;i<n;++i){
		if(nodes[i].father==NULL){
			root=&nodes[i];
			break;
		}
	}
	vector<Node*> order;
	inOrder(order,root);
	vector<int> nums(n);
	for(int i=0;i<n;++i){
		cin>>nums[i];
	}
	sort(nums.begin(),nums.end());
	for(int i=0;i<n;++i){
		order[i]->val = nums[i];
	}
	
	queue<Node*> q;
	q.push(root);
	cout<<root->val;
	if(root->lchild){
		q.push(root->lchild);
	}
	if(root->rchild){
		q.push(root->rchild);
	}
	q.pop();
	Node* pn;
	while(!q.empty()){
		pn=q.front();
		cout<<" "<<pn->val;
		if(pn->lchild){
			q.push(pn->lchild);
		}
		if(pn->rchild){
			q.push(pn->rchild);
		}
		q.pop();
		
	}
	cout<<endl;
	
	return 0;
}