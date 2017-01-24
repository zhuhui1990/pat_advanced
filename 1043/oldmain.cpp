#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Node{
	int val;
	int lchild = -1;
	int rchild = -1;
};

void getTree(vector<Node>& pre,int l,int r,int mirror,bool& flag,int root){
	int ll;
	if(!flag){
		return;
	}
	if(l >= r){
		return;
	}
	if(!mirror){
		int i=l+1;
		for(;i<=r;++i){
			if(pre[i].val >= pre[l].val){
				ll = i;
				break;
			}
		}
		//cout<<"l="<<l<<" r="<<r<<" ll="<<ll<<endl;
		for(;i<=r;++i){
			if(pre[i].val < root){
				//cout<<"root="<<root<<" i="<<i<<endl;
				flag = false;
				return;
			}
		}
		pre[l].lchild=l+1;
		getTree(pre,l+1,ll-1,mirror,flag,pre[l+1].val);
		pre[l].rchild=ll;
		getTree(pre,ll,r,mirror,flag,pre[ll].val);
	}else{
		int i=l+1;
		for(;i<=r;++i){
			if(pre[i].val < pre[l].val){
				ll = i;
				break;
			}
		}
		//cout<<"l="<<l<<" r="<<r<<" ll="<<ll<<endl;
		for(;i<=r;++i){
			if(pre[i].val >= root){
				//cout<<"root="<<root<<" i="<<i<<endl;
				flag = false;
				return;
			}
		}
		pre[l].lchild=l+1;
		getTree(pre,l+1,ll-1,mirror,flag,pre[l+1].val);
		pre[l].rchild=ll;
		getTree(pre,ll,r,mirror,flag,pre[ll].val);
	}
}

void postOrder(const vector<Node>& pre, vector<int>& post,int i){
	if(pre[i].lchild != -1){
		postOrder(pre,post,pre[i].lchild);
	}	
	if(pre[i].rchild != -1){
		postOrder(pre,post,pre[i].rchild);
	}
	post.push_back(i);
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	vector<Node> pre(n);
	for(int i=0;i<n;++i){
		scanf("%d",&pre[i].val);
	}
	int mirror = 0;
	if(pre[1].val >= pre[0].val){
		mirror = 1;
	}
	bool flag = true;
	getTree(pre,0,n-1,mirror,flag,pre[0].val);
	/*
	for(int i=0;i<n;++i){
		cout<<"i="<<i<<" val="<<pre[i].val<<" lchild="<<pre[i].lchild<<" rchild="<<pre[i].rchild<<endl;
	}
	*/
	if(flag){
		printf("YES\n");
		vector<int> post;
		postOrder(pre,post,0);
		printf("%d",pre[post[0]].val);
		for(int i=1;i<post.size();++i){
			printf(" %d",pre[post[i]].val);
		}
		printf("\n");
	}else{
		printf("NO\n");
	}
	return 0;
}