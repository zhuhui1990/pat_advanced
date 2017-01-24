#include <iostream>
#include <vector>

using namespace std;

struct Node{
	int id;
	int level;
	vector<int> child;
};

void getLevel(int i,int level,int& maxlevel,vector<Node>& nodes){
	nodes[i].level=level;
	maxlevel = level>maxlevel? level:maxlevel;
	for(int j=0;j<nodes[i].child.size();++j){
		getLevel(nodes[i].child[j],level+1,maxlevel,nodes);
	}
}

void countLevel(int i,vector<int>& levels,const vector<Node>& nodes){
	int l=nodes[i].level;
	++levels[l];
	for(int j=0;j<nodes[i].child.size();++j){
		countLevel(nodes[i].child[j],levels,nodes);
	}
}


int main(){
	int n,m;
	cin>>n>>m;
	if(m==0){
		cout<<n<<" "<<1<<endl;
		return 0;
	}
	vector<Node> nodes(n+1);
	int id,cnt,id1;
	for(int i=0;i<m;++i){
		cin>>id;
		cin>>cnt;
		for(int j=0;j<cnt;++j){
			cin>>id1;
			nodes[id].child.push_back(id1);
		}
	}
	int maxlevel=1;
	getLevel(1,1,maxlevel,nodes);
	vector<int> levels(maxlevel+1);
	
	countLevel(1,levels,nodes);
	
	int maxloc=0,maxval=0;
	for(int i=1;i<maxlevel+1;++i){
		if(levels[i]>maxlevel){
			maxval=levels[i];
			maxloc=i;
		}
	}
	cout<<maxval<<" "<<maxloc<<endl;
	
	return 0;
}