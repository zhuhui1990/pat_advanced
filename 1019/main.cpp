#include <iostream>
#include <vector>
using namespace std;

vector<int> int2vector(int n,const int& radix){
	vector<int> res;
	if(n==0){
		res.push_back(0);
		return res;
	}
	int a;
	while(n>0){
		a=n%radix;
		n/=radix;
		res.push_back(a);
	}
	return res;
}

bool isPalin(const vector<int>& s){
	int i=0,j=s.size()-1;
	while(i<=j){
		if(s[i]!=s[j])
			return false;
		++i;
		--j;
	}
	return true;
}

int main(){
	int n,radix;
	cin>>n>>radix;
	vector<int> s=int2vector(n,radix);
	if(isPalin(s))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	for(int i=s.size()-1;i>0;--i){
		cout<<s[i]<<" ";
	}
	cout<<s[0]<<endl;
}