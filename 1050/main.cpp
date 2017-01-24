#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(){
	string s1,s2,res;
	getline(cin,s1);
	getline(cin,s2);
	unordered_set<char> chs;
	for(int i=0;i<s2.size();++i){
		chs.insert(s2[i]);
	}
	for(int i=0;i<s1.size();++i){
		if(chs.find(s1[i])==chs.end()){
			res+=s1[i];
		}
	}
	cout<<res<<endl;
}