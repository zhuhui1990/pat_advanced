#include <iostream>
#include <string>

using namespace std;

enum sign{
	positive,
	zero,
	negative
};

struct Num{
	sign sgn;
	string abs;
	Num():sgn(zero),abs(""){
	}
	Num(string s){
		if(s[0]=='-'){
			sgn=negative;
			abs=string(s.begin()+1,s.end());
		}else if(s=="0"){
			sgn=zero;
			abs=s;
		}else{
			sgn=positive;
			abs=s;
		}
	}
};

bool comp(const string& lhs,const string& rhs){
	if(lhs.size()!=rhs.size()){
		return lhs.size()>rhs.size();
	}else{
		for(int i=0;i<lhs.size();++i){
			if(lhs[i]>rhs[i]){
				return true;
			}else if(lhs[i]<rhs[i]){
				return false;
			}
		}
	}
	return false;
}

string add(string lhs,string rhs){
	string s;
	while(lhs.size()<rhs.size()){
		lhs='0'+lhs;
	}
	while(rhs.size()<lhs.size()){
		rhs='0'+rhs;
	}
	int add1=0;
	char c;
	int a,a1,a2;
	for(int i=lhs.size()-1;i>=0;--i){
		a1=lhs[i]-'0';
		a2=rhs[i]-'0';
		a=a1+a2+add1;
		if(a<10){
			c=a+'0';
			add1=0;
			s = c+s;
		}else{
			c=a-10+'0';
			add1=1;
			s = c+s;
		}
	}
	if(add1!=0)
		s='1'+s;
	return s;
}

string minuss(string lhs,string rhs){
	string s;
	while(lhs.size()<rhs.size()){
		lhs='0'+lhs;
	}
	while(rhs.size()<lhs.size()){
		rhs='0'+rhs;
	}
	int minus1=0;
	char c;
	int a,a1,a2;
	for(int i=lhs.size()-1;i>=0;--i){
		a1=lhs[i]-'0';
		a2=rhs[i]-'0';
		a=a1-a2-minus1;
		if(a>=0){
			c=a+'0';
			minus1=0;
			s=c+s;
		}else{
			c=a+10+'0';
			minus1=1;
			s=c+s;
		}
	}
	int cnt=0;
	for(int i=0;i<s.size();++i){
		if(s[i]!='0'){
			cnt=i;
			break;
		}
	}
	s.erase(0,cnt);
	return s;
}

Num add(const Num& lhs,const Num& rhs){
	if(lhs.sgn==zero)
		return rhs;
	else if(rhs.sgn==zero)
		return lhs; 
	else{
		Num res;
	  if(lhs.sgn==rhs.sgn){
			res.sgn=lhs.sgn;
			res.abs=add(lhs.abs,rhs.abs);
		}else{
				if(comp(lhs.abs,rhs.abs)){
					res.abs=minuss(lhs.abs,rhs.abs);
					res.sgn=lhs.sgn;
				}else if(comp(rhs.abs,lhs.abs)){
					res.abs=minuss(rhs.abs,lhs.abs);
					res.sgn=rhs.sgn;
				}else{
					res.sgn=zero;
					res.abs="0";
				}
		}
		return res;
	}
}



bool comp(const Num& lhs,const Num& rhs){
	if(lhs.sgn!=rhs.sgn){
		return lhs.sgn<rhs.sgn;
	}else if(lhs.abs==rhs.abs){
		return false;
	}else{
		if(lhs.sgn == positive){
			return comp(lhs.abs,rhs.abs);
		}else{
			return comp(rhs.abs,lhs.abs);
		}
	}
}



int main(){
	int n;
	cin>>n;
	string s1,s2,s3;
	for(int i=0;i<n;++i){
		cin>>s1>>s2>>s3;
		Num n1(s1),n2(s2),n3(s3);
		Num n4=add(n1,n2);
		//cout<<n4.abs<<endl;
		cout<<"Case #"<<i+1<<": ";
		if(comp(n4,n3)){
			cout<<"true"<<endl;
		}else{
			cout<<"false"<<endl;
		}
	}
	return 0;
}