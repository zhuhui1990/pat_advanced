#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct Node{
	int level;
	vector<int> child;
};

void DFS(int i,int level,int& cnt,int& maxlevel,const vector<Node>& nodes){
	if(nodes[i].child.size()==0){
		if(level>maxlevel){
			cnt=1;
			maxlevel=level;
		}else if(level==maxlevel){
			++cnt;
		}
	}else{
		for(int j=0;j<nodes[i].child.size();++j){
			DFS(nodes[i].child[j],level+1,cnt,maxlevel,nodes);
		}	
	}	
}

int main(){
	int n;
	double p,r;
	scanf("%d %lf %lf",&n,&p,&r);
	//cout<<n<<" "<<p<<" "<<r<<endl;
	int c,root;
	vector<Node> nodes(n);
	for(int i=0;i<n;++i){
		scanf("%d",&c);
		//cout<<"i="<<i<<" c="<<c<<endl;
		if(c==-1){
			root=i;
		}else{
			nodes[c].child.push_back(i);
		}
	}
	//cout<<"root="<<root<<endl;
	int cnt=0,maxlevel=0;
	DFS(root,0,cnt,maxlevel,nodes);
	double res = p*pow(1.+r/100.,maxlevel);
	
	printf("%.2lf %d\n",res,cnt);

}