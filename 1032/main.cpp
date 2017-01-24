#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <cstdio>

using namespace std;

int main(){
	int ss1,ss2;
	int n;
	scanf("%d %d %d",&ss1,&ss2,&n);
	if(ss1==-1 || ss2==-1){
		printf("-1\n");
		return 0;
	}
	unordered_map<int,int>  hashtable;
	int s1,s3;
	char s2;
	for(int i=0;i<n;++i){
		scanf("%d %c %d",&s1,&s2,&s3);
		hashtable.insert({s1,s3});
	}
	unordered_set<int> setstring;
	int s=ss1;
	setstring.insert(s);
	while(s!=-1){
		auto it=hashtable.find(s);
		setstring.insert(it->second);
		s=it->second;
	}
	s=ss2;
	if(setstring.find(s)!=setstring.end()){
		printf("%05d\n",s);
		return 0;
	}
	while(s!=-1){
		auto it=hashtable.find(s);
		auto it1=setstring.find(it->second);
		if(it1!=setstring.end() && it->second!=-1){
			printf("%05d\n",it->second);
			return 0;
		}else{
			s=it->second;
		}
	}
	
	printf("-1\n");
	return 0;
}