#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	long long n;
	cin>>n;
	long long n1;
	int sz;
	int cnt,maxcnt=0;
	long long start,first;
	long long m = sqrt(double(n));
	long long j;
	for( long long i=2; i<=m; ++i){
		n1 = n;
		start = i;
		j = i;
		cnt = 0;
		while(n1 % j == 0){
			//cout<<"n1="<<n1<<" i="<<i<<endl;
			n1 /= j;
			++cnt;
			++j;
		}
		if(cnt > maxcnt){
			maxcnt=cnt;
			first=start;
		}
	}
	if(maxcnt == 0){
		cout<<1<<endl;
		cout<<n;
		return 0;
	}
	cout<<maxcnt<<endl;
	cout<<first;
	for(int i=1;i<maxcnt;++i){
		cout<<"*"<<first+i;
	}
	cout<<endl;
	
}