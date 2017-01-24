#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

//直接字符串操作会超时，将字符串转化为整数
//直接用hashtable也会超时，改用vector模拟hashtable
inline int string2int(const string& s){
	return((s[0]-'A')*26*26*10+(s[1]-'A')*26*10+(s[2]-'A')*10+(s[3]-'0')); 
}


int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	const int maxarray=26*26*26*10+1;
	vector<vector<int>> hashtable(maxarray);
	int id;
	string s;
	s.resize(10);
	int l;
	for(int i=0;i<k;++i){
		scanf("%d %d",&id,&l);
		for(int j=0;j<l;++j){
			scanf("%s",&s[0]);
			int ii=string2int(s);
			hashtable[ii].push_back(id);
		}
	}
	for(int i=0;i<n;++i){
		scanf("%s",&s[0]);
		printf("%s ",s.c_str());
		int ii=string2int(s);
		if(hashtable[ii].size()>0){
			printf("%d ",hashtable[ii].size());
			sort(hashtable[ii].begin(),hashtable[ii].end());
			auto it=hashtable[ii].begin();
			printf("%d",*it);
			++it;
			for(;it!=hashtable[ii].end();++it){
				printf(" %d",*it);
			}
			printf("\n");	
		}else{
			printf("0\n");
		}
		
	}
	return 0;
}