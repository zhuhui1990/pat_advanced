#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

struct Node{
	int val;
	int father=0;
	int lchild=0;
	int rchild=0;
};

int find(const vector<int>& postorder,const int& val){
	for(int i=0;i<postorder.size();++i){
		if(postorder[i]==val)
			return i;
	}
}

int buildtree(vector<Node>& tree,const vector<int>& preorder,int pb,int pe,const vector<int>& inorder,int ib,int ie){
	if(pb>pe)
		return 0;
	int loc=find(inorder,preorder[pb]);
	int val=preorder[pb];
	int lchild=buildtree(tree,preorder,pb+1,pb+loc-ib,inorder,ib,loc-1);
	int rchild=buildtree(tree,preorder,pb+loc-ib+1,pe,inorder,loc+1,ie);
	//cout<<"pb="<<pb<<" pe="<<pe<<" val="<<val<<" lchild="<<lchild<<" rchild="<<rchild<<endl;
	tree[val].lchild=lchild;
	tree[val].rchild=rchild;
	if(lchild){
		tree[lchild].father=val;
	}
	if(rchild){
		tree[rchild].father=val;
	}
	return val;
}

void getPostOrder(vector<int>& postorder,const vector<Node>& tree,int root){
	if(tree[root].lchild){
		getPostOrder(postorder,tree,tree[root].lchild);
	}
	if(tree[root].rchild){
		getPostOrder(postorder,tree,tree[root].rchild);
	}
	postorder.push_back(root);
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	if(n==0){
		return 0;
	}
	vector<int> preorder;
	vector<int> inorder;
	stack<int>  stk;
	char s[5];
	int  i,cnt=0;
	while(cnt<n*2){
		scanf("%s",s);
		if(strcmp(s,"Push")==0){
			scanf("%d",&i);
			preorder.push_back(i);
			stk.push(i);
		}else if(strcmp(s,"Pop")==0){
			i = stk.top();
			stk.pop();
			inorder.push_back(i);
		}
		++cnt;
	}
#ifdef LOCAL
	for(int j=0;j<preorder.size();++j){
		cout<<preorder[j]<<" ";
	}
	cout<<endl;
	for(int j=0;j<inorder.size();++j){
		cout<<inorder[j]<<" ";
	}
	cout<<endl;
#endif
	
	vector<Node> tree(n+1);
	buildtree(tree,preorder,0,n-1,inorder,0,n-1);
	int root=0;
	for(int i=1;i<=n;++i){
		if(tree[i].father==0){
			root=i;
			break;
		}
	}
	vector<int> postorder;
	getPostOrder(postorder,tree,root);
	printf("%d",postorder[0]);
	for(int i=1;i<n;++i){
		printf(" %d",postorder[i]);
	}
	printf("\n");
	
}