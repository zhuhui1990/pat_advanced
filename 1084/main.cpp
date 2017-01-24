#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;
	unordered_set<char> hashtable1,hashtable2;
	
	for(auto const& c:s2){
		char c1=toupper(c);
		hashtable2.insert(c1);
	}
	for(auto const& c:s1){
		char c1=toupper(c);
		if(hashtable2.find(c1)==hashtable2.end() && hashtable1.find(c1)==hashtable1.end()){
			hashtable1.insert(c1);
			cout<<c1;
		}
	}
	
	
	return 0;
}