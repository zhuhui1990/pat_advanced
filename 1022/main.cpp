#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<string> id(n);
	vector<string> title(n);
	vector<string> author(n);
	vector<vector<string>> keywords(n);
	vector<string> publisher(n);
	vector<string> year(n);
	string s,s1;
	int start,end;
	getline(cin,s);
	for(int i=0;i<n;++i){
		getline(cin,id[i]);
		getline(cin,title[i]);
		getline(cin,author[i]);
		getline(cin,s);
		start=0;
		for(int j=0;j<s.size();++j){
			if(s[j]==' '){
				end=j;
				keywords[i].push_back(string(s.begin()+start,s.begin()+end));
				start=j+1;
			}
		}
		keywords[i].push_back(string(s.begin()+start,s.end()));
		getline(cin,publisher[i]);
		getline(cin,year[i]);
	}
	/*
	cout<<endl;
	for(int i=0;i<n;++i){
		cout<<"i="<<i<<endl;
		for(int j=0;j<keywords[i].size();++j){
			cout<<keywords[i][j]<<endl;
		}
	}
	*/
	int m;
	cin>>m;
	set<string> res;
	getline(cin,s);
	for(int i=0;i<m;++i){
		getline(cin,s);
		res.clear();
		string s1(s,3);
		switch(s[0]){
			case('1'):{
				for(int j=0;j<n;++j){
					if(s1==title[j]){
						res.insert(id[j]);
					}
				}
				break;
			}case('2'):{
				for(int j=0;j<n;++j){
					if(s1==author[j]){
						res.insert(id[j]);
					}
				}
				break;
			}case('3'):{
				for(int j=0;j<n;++j){
					for(int k=0;k<keywords[j].size();++k){
						if(s1==keywords[j][k]){
							res.insert(id[j]);
							continue;
						}
					}
				}
				break;
			}case('4'):{
				for(int j=0;j<n;++j){
					if(s1==publisher[j]){
						res.insert(id[j]);
					}
				}
				break;
			}case('5'):{
				for(int j=0;j<n;++j){
					if(s1==year[j]){
						res.insert(id[j]);
					}
				}
				break;
			}
		}
		cout<<s<<endl;
		if(res.empty()){
			cout<<"Not Found"<<endl;
		}else{
			for(auto it=res.begin();it!=res.end();++it){
				cout<<*it<<endl;
			}
		}
	}
	
}