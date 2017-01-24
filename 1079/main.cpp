#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;

struct Node{
	int level;
	vector<int> child;
	int amount;
};


void getLevel(int i,int level,vector<Node>& nodes){
	nodes[i].level=level;
	for(int j=0;j<nodes[i].child.size();++j){
		int k=nodes[i].child[j];
		getLevel(k,level+1,nodes);
	}
}

void DFS(int i,double& total,const double& p,const double& r,const vector<Node>& nodes){
	int n=nodes[i].child.size();
	if(n==0){
		//cout<<"i="<<i<<" level="<<nodes[i].level<<" amount="<<nodes[i].amount<<endl;
		double plus = p*pow(1.+r/100.,nodes[i].level);
		total += plus*nodes[i].amount;
	}else{
		int c;
		for(int j=0;j<nodes[i].child.size();++j){
			c = nodes[i].child[j];
			DFS(c,total,p,r,nodes);
		}
	}
}



int main(){
	int n;
	double p,r;
	scanf("%d %lf %lf",&n,&p,&r);
	vector<Node> nodes(n);
	int k;
	for(int i=0;i<n;++i){
		scanf("%d",&k);
		nodes[i].child.resize(k);
		if(k!=0){
			for(int j=0;j<k;++j){
				scanf("%d",&(nodes[i].child[j]));
			}
		}else{
			scanf("%d",&(nodes[i].amount));
		}
	}
	double total=0.;
	getLevel(0,0,nodes);
	DFS(0,total,p,r,nodes);
	printf("%.1lf",total);
}