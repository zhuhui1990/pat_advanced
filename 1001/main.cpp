#include <iostream>
#include <string>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int c=a+b;
	int cnt=0;
	int sgn = (c>=0? 1:-1);
	int cc=c*sgn;
	string s;
	if(cc==0){
		cout<<"0"<<endl;
		return 0;
	}
	while(cc>0){
		char c1=cc%10+'0';
		cc/=10;
		++cnt;
		s = c1+s;
		if(cnt%3==0 && cc>0)
			s=','+s;
	}
	if(sgn==-1)
		s='-'+s;

	cout<<s<<endl;
	return 0;
}