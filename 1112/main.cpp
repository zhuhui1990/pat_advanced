#include <iostream>
#include <unordered_set>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	char s[1005];
	scanf("%s",s);
	vector<char> del;
	unordered_set<char> err;
	int i=0;
	while(i<strlen(s)){
		int begin = i;
		char a = s[i++];
		while(i<strlen(s) && s[i] == a){
			++i;
		}
		int l = i - begin;
		if(l % n == 0 && find(del.begin(),del.end(),a)==del.end()){
			del.push_back(a);
		}else if(l % n !=0){
			err.insert(a);
		}
	}
	/*
	for(auto it=err.begin();it!=err.end();++it){
		cout<<*it;
	}
	cout<<endl;
	*/
	vector<char> del1;
	for(int i=0;i<del.size();++i){
		//cout<<"i="<<i<<" del[i]="<<del[i]<<endl;
		if(err.find(del[i])==err.end()){
			del1.push_back(del[i]);
		}
	}
	for(int i=0;i<del1.size();++i){
		printf("%c",del1[i]);
	}
	printf("\n");
	string s1;
	for(int i=0;i<strlen(s);){
		if(find(del1.begin(),del1.end(),s[i])==del1.end()){
			s1 += s[i++];
		}else{
			s1 += s[i];
			i += n;
		}
	}
	cout<<s1<<endl;
	return 0;
}