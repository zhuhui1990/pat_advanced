//直接DFS比并查集简单

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
	string name;
	vector<int> neighbour;
	int relation;
	Node():name(),neighbour(),relation(0){
	}
	Node(const string& s):name(s),neighbour(),relation(0){
	}
};

struct Gang{
	string head;
	int size;
};

inline bool comp(const Gang& lhs,const Gang& rhs){
	return lhs.head < rhs.head;
}

int find(const vector<Node>& nodes,const string& s){
	for(int i=0;i<nodes.size();++i){
		if(nodes[i].name == s){
			return i;
		}
	}
	return -1;
}

int find(const vector<int>& neighbour,const int& i2){
	for(int i=0;i<neighbour.size();++i){
		if(neighbour[i]==i2){
			return i2;
		}
	}
	return -1;
}

void DFS(int a,int& maxloc,int& maxval,int& size,double& relation,vector<bool>& visited,const vector<Node>& nodes){

	++size;
	relation += nodes[a].relation/2.;
	if(nodes[a].relation > maxval){
		maxval = nodes[a].relation;
		maxloc = a;
	}

	for(int i=0;i<nodes[a].neighbour.size();++i){
		int j=nodes[a].neighbour[i];
	//	cout<<"a="<<a<<" i="<<i<<" j="<<j<<endl;
		if(!visited[j]){
			visited[j]=true;
			DFS(j,maxloc,maxval,size,relation,visited,nodes);
		}
	}
}


int main(){
	int n,threshold;
	cin>>n>>threshold;
	string s1,s2;
	int wt;
	vector<Node> nodes;
	//input
	for(int i=0;i<n;++i){
		cin>>s1>>s2>>wt;
		int i1=find(nodes,s1);
		int i2=find(nodes,s2);
		if(i1==-1){
			nodes.push_back(Node(s1));
		}
		if(i2==-1){
			nodes.push_back(Node(s2));
		}
		
		i1=find(nodes,s1);  
		i2=find(nodes,s2);  
		
		int l=find(nodes[i1].neighbour,i2);
		nodes[i1].relation += wt;
		if(l==-1){
			nodes[i1].neighbour.push_back(i2);
		}
		l=find(nodes[i2].neighbour,i1);
		nodes[i2].relation += wt;
		if(l==-1){
			nodes[i2].neighbour.push_back(i1);
		}
	}
	//DFS
	vector<bool> visited(nodes.size());
	for(int i=0;i<nodes.size();++i){
		visited[i]=false;
	}
	int jj=0;
	vector<Gang> gangs;
	while(jj<nodes.size()){
		int maxloc=jj;
		int maxval=0;
		int size=0;
		double relation=0.;
		visited[jj]=true;
		DFS(jj,maxloc,maxval,size,relation,visited,nodes);
		if(size>2 && relation>threshold){
			gangs.push_back({nodes[maxloc].name,size});
		}
		bool flag=false;
		for(int ii=jj+1;ii<nodes.size();++ii){
			if(!visited[ii]){
				jj=ii;
				flag=true;
				break;
			}
		}
		if(flag==false){
			jj=nodes.size();
		}
	}
	sort(gangs.begin(),gangs.end(),comp);
	
	cout<<gangs.size()<<endl;
	for(int i=0;i<gangs.size();++i){
		cout<<gangs[i].head<<" "<<gangs[i].size<<endl;
	}
	return 0;
}