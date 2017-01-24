#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
#include <map>
#include <vector>

using namespace std;

vector<char> input;
char ch;
map<string,int> hash1;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	string s;
	while(scanf("%c",&ch)){
		//cout<<"ch="<<ch<<endl;
		input.push_back(tolower(ch));
		if(ch=='\n'){
			break;
		}
	}
	
	int begin=0,end=0;
	for(int i=0;i<input.size();++i){
		//cout<<"i="<<i<<" begin="<<begin<<" end="<<end<<endl;
		if(isalnum(input[i])){
			++end;
			continue;
		}
		if(begin<end){
			s = string(input.begin()+begin,input.begin()+end);
			++hash1[s];
			++end;
			begin=end;
			continue;
		}
		begin = end = i+1;
	}
	int max=0;
	string maxs;
	for(auto it=hash1.begin();it!=hash1.end();++it){
		if(it->second > max){
			max = it->second;
			maxs = it->first;
		}
	}
	cout<<maxs<<" "<<max<<endl;
}