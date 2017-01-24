#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	string s;
	cin>>s;
	//n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } 
	//with n1 + n2 + n3 - 2 = N
	int n=s.length();
	int max=0;
	int n1,n2,n3;
	for(;n2<=n;++n2){
		n1=((n+2)-n2)/2;
		if(n1>max && n1<=n2)
			max=n1;
	}
	n1=max;
	n3=n1;
	n2=n+2-n1-n3;
	//cout<<n1<<" "<<n2<<endl;
	vector<string> vec(n1,string(n2,' '));
	int ii=0,jj=n-1;
	for(int i=0;i<n1-1;++i){
		vec[i][0]=s[ii];
		vec[i][n2-1]=s[jj];
		++ii;
		--jj;
	}
	vec[n1-1]=string(s.begin()+ii,s.begin()+jj+1);
	for(int i=0;i<n1;++i){
		cout<<vec[i]<<endl;
	}
	return 0;
}