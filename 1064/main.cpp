//����complete binary tree������
//�±�i���ӽڵ��±�Ϊ2*i��2*i+1
//�±�λ�ô�1��ʼ
//��������������������
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxx=1005;
int node[maxx];
int tree[maxx];
int pos,n;

void build(int root){
	if(root>n){
		return;
	}
	int lchild = root * 2, rchild = root * 2 + 1;
	build(lchild);
	//cout<<"root="<<root<<" node[pos]="<<node[pos]<<endl;
	tree[root] = node[pos++];
	build(rchild);
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&node[i]);
	}
	sort(node,node+n);
	pos=0;
	build(1);
	printf("%d",tree[1]);
	for(int i=2;i<n+1;++i){
		printf(" %d",tree[i]);
	}
	printf("\n");
	return 0;
}