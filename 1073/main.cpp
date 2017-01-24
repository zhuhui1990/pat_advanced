#include <iostream>
#include <string>

using namespace std;

int main(){
	string s1,s2;
	cin>>s1;
	if(s1[0]=='-')
		s2 += s1[0];
	s2+=s1[1];
	int i=3;
	while(s1[i]!='E'){
		s2+=s1[i];
		++i;
	}
	++i;
	char sgn=s1[i];
	++i;
	int pow=0;
	for(;i<s1.length();++i){
		pow *= 10;
		pow += s1[i]-'0';
	}
	int length=s2.length();
	if(s2[0]=='-')
		--length;
	if(sgn=='+'){
		if(pow>=length){
			int n=pow-length+1;
			for(int j=0;j<n;++j){
				s2 += '0';
			}
		}else if(pow<length-1){
			if(s2[0]=='-')
				s2.insert(pow+2,1,'.');
			else
				s2.insert(pow+1,1,'.');	
		}
	}else{
		bool ss=false;
		if(s2[0]=='-'){
			ss=true;
			s2.erase(0,1);
		}
		for(int j=0;j<pow-1;++j){
			s2 = "0" + s2;
		}
		s2 = "0." + s2;
		if(ss)
			s2.insert(0,1,'-');
	}
	
	cout<<s2<<endl;
	return 0;
}