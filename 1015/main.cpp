#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isprime(const int& a){
	if (a==0)
		return false;
	if (a==1)
		return false;
	int max=sqrt(a);
	for(int i=2;i<=max;++i){
		if(a%i ==0){
			return false;
		}
	}
	return true;
}

int reverse(int a, const int& radix){
	string s;
	char c;
	while(a>0){
		c = a%radix+'0';
		a /= radix;
		s += c;
	}
	int b,res=0;
	for(int i=0;i<s.size();++i){
		b=s[i]-'0';
		res *= radix;
		res += b;
	}
	return res;
}

int main(){
	int a,radix;
	while(cin>>a && a>=0){
		cin>>radix;
		if(isprime(a) == false){
			cout<<"No"<<endl;
			continue;
		}
		int b = reverse(a,radix);
		if(isprime(b) == false){
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
	}
	return 0;
}