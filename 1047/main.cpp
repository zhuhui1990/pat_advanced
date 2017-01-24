#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
/*
inline int string2int(const string& s){
	return((s[0]-'A')*26*26*10+(s[1]-'A')*26*10+(s[2]-'A')*10+(s[3]-'0')); 
}

inline string int2string(int a){
	string s;
	int i=a%10;
	char c=i+'0';
	s = c+s;
	a/=10;
	for(int j=0;j<3;++j){
		i=a%26;
		a/=26;
		c=i+'A';
		s=c+s;
	}
	
	return s;
}
*/
int main(){
	int n,m;
	//cin>>n>>m;
	scanf("%d %d",&n,&m);
	//vector<set<int>> course(m);
	//vector<vector<string>> course(m);
	vector<string> course[2505];
	string s;
	char ch[10];
	int id,nn;
	int a;
	for(int i=0;i<n;++i){
		//cin>>s;
		scanf("%s %d",ch,&nn);
		s=string(ch);
		for(int j=0;j<nn;++j){
			//cin>>a;
			scanf("%d",&a);
			//cout<<a<<endl;
			//course[a-1].insert(id);
			course[a-1].push_back(s);
		}
	}
	int len;
	for(int i=0;i<m;++i){
		//cout<<i+1<<" "<<course[i].size()<<endl;
		len=course[i].size();
		printf("%d %d\n",i+1,len);
		sort(course[i].begin(),course[i].end());
		//for(auto it=course[i].begin();it!=course[i].end();++it){
		for(int j=0;j<len;++j){
			//cout<<int2string(*it)<<endl;
			//printf("%s\n",int2string(*it).c_str());
			printf("%s\n",course[i][j].c_str());
			//cout<<*it<<endl;
		}
	}
	return 0;
}