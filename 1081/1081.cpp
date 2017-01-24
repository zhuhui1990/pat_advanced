#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long gcd(long a,long b){
	if(a==0 || b==0)
		return 1;
	if(a==1 || b==1)
		return 1;
	if(a==b)
		return a;
	long max=a>b?a:b;
	long min=a>b?b:a;
	if(max%min==0)
		return min;
	return gcd(min,max%min);
}


struct Rational{
		void reduction(){
			long c=gcd(abs(denom),abs(numer));
			denom /= c;
			numer /= c;
		}
		long denom;
		long numer;
};

Rational sum(const Rational& lhs, const Rational& rhs){
	Rational res;
	res.numer = lhs.numer*rhs.numer;
	res.denom = lhs.numer*rhs.denom+rhs.numer*lhs.denom;
	res.reduction();
	return res;
}

void output(Rational r){
	//cout << r.denom << " " << r.numer << endl;
	if(r.numer == 1){
		cout<<r.denom<<endl;
		return;
	}else if(r.denom == 0){
		cout<<"0"<<endl;
		return;
	}else{
		if(r.numer * r.denom<0){
			cout<<"-";
			r.numer = abs(r.numer);
			r.denom = abs(r.denom);
		}
		if(r.denom>r.numer){
			cout<<r.denom/r.numer<<" ";
		}
		if (r.denom%r.numer != 0){
			cout << r.denom%r.numer << "/" << r.numer << endl;
		}
		
	}
}

int main(){
	int n;
	cin>>n;
	vector<Rational> rs(n);
	for(int i=0;i<n;++i){
		scanf("%ld/%ld",&rs[i].denom,&rs[i].numer);
	}
	if(n==1){
		output(rs[0]);
	}else{
		Rational res=sum(rs[0],rs[1]);
		for(int i=2;i<n;++i){
			res=sum(res,rs[i]);
		} 
		
		output(res);
		//system("pause");
	}
	return 0;
}