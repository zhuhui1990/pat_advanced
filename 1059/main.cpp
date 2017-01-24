#include <iostream>
#include <map>
#include <cstdio>
#include <cmath>

using namespace std;

bool isprime(const long& n){
	if(n==1 || n==0){
		return false;
	}
	for(int i=2;i<=sqrt(n);++i){
		//cout<<"i="<<i<<" n="<<n<<" n%i="<<n%i<<endl;
		if(n%i==0){
			return false;
		}
	}
	return true;
}

void factor(long n,int& p,map<long,int>& hashtable){
	//cout<<"n="<<n<<" p="<<p<<endl;
	if(isprime(n)){
		++hashtable[n];
		return;
	}else{
		if(n%p==0){
			++hashtable[p];
			factor(n/p,p,hashtable);
		}else{
			if(p==2){
				++p;
			}else{
				p+=2;
				while(!isprime(p)){
					p+=2;
				}
			}
			factor(n,p,hashtable);
		}
	}
}


int main(){
	long n;
	scanf("%ld",&n);
	if(n==1){
		printf("1=1\n");
		return 0;
	}
	map<long,int> hashtable;
	int p=2;
	factor(n,p,hashtable);
	printf("%ld=",n);
	auto it=hashtable.begin();
	printf("%ld",it->first);
	if(it->second > 1){
		printf("^%d",it->second);
	}
	++it;
	for(;it!=hashtable.end();++it){
		printf("*%ld",it->first);
		if(it->second > 1){
			printf("^%d",it->second);
		}
	} 
}