#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Node{
	int level;
	vector<int> child;
};

void getLevel(int i,int level,vector<Node>& nodes){
	nodes[i].level=level;
	for(int j=0;j<nodes[i].child.size();++j){
		int k=nodes[i].child[j];
		getLevel(k,level+1,nodes);
	}
}

void getMinLevel(int i,int& cnt,int& minlevel,const vector<Node>& nodes){
	if(nodes[i].child.size()==0){
		if(nodes[i].level<minlevel){
			minlevel=nodes[i].level;
			cnt = 1;
		}else if(nodes[i].level==minlevel){
			++cnt;
		}
	}else{
		for(int j=0;j<nodes[i].child.size();++j){
			int k=nodes[i].child[j];
			getMinLevel(k,cnt,minlevel,nodes);
		}
	}
}


int main(){
	const int inf=0xffffff;
	int n;
	double p,r;
	cin>>n>>p>>r;
	vector<Node> nodes(n);
	int k;
	for(int i=0;i<n;++i){
		cin>>k;
		nodes[i].child.resize(k);
		for(int j=0;j<k;++j){
			cin>>nodes[i].child[j];
		}
	}
	getLevel(0,0,nodes);
	int minlevel=inf,cnt=0;
	getMinLevel(0,cnt,minlevel,nodes);
	double res=p;
	for(int i=0;i<minlevel;++i){
		res *= 1.+r/100.;
	}
	//cout<<minlevel<<endl;
	cout<<setprecision(4)<<fixed;
	cout<<res<<" "<<cnt;
	return 0;
}