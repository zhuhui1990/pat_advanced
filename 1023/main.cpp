#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string s1,s2;
	cin>>s1;
	int add=0;
	int n1;
	char c;
	for(int i=s1.size()-1;i>=0;--i){
		n1=2*(s1[i]-'0')+add;
		if(n1<10){
			c=n1+'0';
			s2=c+s2;
			add=0;
		}else{
			c=n1-10+'0';
			s2=c+s2;
			add=1;
		}
	}
	if(add==1){
		s2='1'+s2;
		cout<<"No"<<endl;
	}else	if(is_permutation(s1.begin(),s1.end(),s2.begin())){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	cout<<s2<<endl;
}