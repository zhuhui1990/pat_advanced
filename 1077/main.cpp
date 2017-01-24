//×ÖµäÊ÷
#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

struct Node{
	char c;
	vector<shared_ptr<Node>> child;
};

int find(const vector<shared_ptr<Node>>& vec,char c){
	for(int k=0;k<vec.size();++k){
		if(vec[k]->c == c){
			return k;
		}
	}
	return -1;
}


int main(){
	int n;
	cin>>n;
	if(n==0){
		return 0;
	}
	string s;
	getline(cin,s);
	getline(cin,s);
	char c=s[s.length()-1];
	shared_ptr<Node> root=make_shared<Node>(Node());
	root->c=c;
	shared_ptr<Node> pn1=root,pn2;
	for(int j=s.length()-2;j>=0;--j){
		c=s[j];
		pn2=make_shared<Node>(Node());
		pn2->c=c;
		pn1->child.push_back(pn2);
		pn1=pn2;
	}
	int k;
	for(int i=1;i<n;++i){
		getline(cin,s);
		pn1=root;
		for(int j=s.length()-1;j>=1;--j){
			c=s[j];
			if(pn1->c != c){
				cout<<"nai"<<endl;
				return 0;
			}else{
				c=s[j-1];
				k=find(pn1->child,c);
				//cout<<"k="<<k<<" c="<<c<<" pn1->c="<<pn1->c<<endl;
				if(k==-1){
					pn2=make_shared<Node>(Node());
					pn2->c=c;
					pn1->child.push_back(pn2);
					pn1=pn2;	
				}else{
					pn1=pn1->child[k];
				}	
			}
		}
	}
	pn1=root;
	string res;
	while(pn1->child.size()==1){
		res = pn1->c + res;
		pn1 = pn1->child[0];
	}
	res = pn1->c + res;
	cout<<res<<endl;
	return 0;
}
