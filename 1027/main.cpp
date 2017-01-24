#include <iostream>
#include <string>
using namespace std;

string change(const string& in){
	string s;
	int a=0;
	int ii;
	char c;
	for(int i=0;i<in.length();++i){
		c=in[i];
		ii=c-'0';
		a=a*10+ii;
	}
	//cout<<in<<" "<<a<<endl;
	if(a==0)
		return "00";
	while(a>0){
		ii=a%13;
		a/=13;
		if(ii<10){
			c=ii+'0';
		}else{
			c=ii-10+'A';
		}
		s=c+s;
	}
	if(s.size()==1)
		s="0"+s;
	return s; 
}

int main(){
	string r,g,b;
	cin>>r>>g>>b;
	cout<<"#"<<change(r)<<change(g)<<change(b)<<endl;
	return 0;
}