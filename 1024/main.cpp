#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string sum(string a,string b){
	while(a.size()<b.size()){
		a='0'+a;
	}
	while(b.size()<a.size()){
		b='0'+b;
	}
	string res;
	bool add=false;
	for(int i=a.size()-1;i>=0;--i){
		int ia=a[i]-'0';
		int ib=b[i]-'0';
		int ic=ia+ib;
		if(add)
			++ic;
		if(ic<10){
			char c=ic+'0';
			res = c+res;
			add=false;
		}else{
			char c=ic-10+'0';
			res = c+res;
			add=true;
		}
	}
	if(add)
		res = '1'+res;
	//cout<<a<<" "<<b<<" "<<res<<endl;
	return res;
}


int main(){
	string n;
	int k;
	cin>>n>>k;
	int i=0;
	string m;
	while(i<k){
		m=n;
		reverse(n.begin(),n.end());
		if(m==n){
			break;
		}else{
			n=sum(m,n);
		}
		++i;
	}
	cout<<n<<endl;
	cout<<i<<endl;
}