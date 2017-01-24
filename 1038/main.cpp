//����
//���򵥵ıȽ��߼���
//�ַ���s1+s2<s2+s1����s1<s2
//���ɣ�s1+s2��s2+s1λ��һ����ͬ����ʱֱ�Ӱ����ֵ���Ƚ�


//�ϰ汾�Ƚϵ��߼���
//1.leading zeroes��Ŀ�ǰ
//2.���leading zeroesһ���࣬ȥ��leading zero֮���ٱȽ�
//3.�������һ����С����ǰ��
//4.������Ȳ�һ����ֻ�Ƚϳ��Ƚ϶̵Ĳ��֣�С����ǰ��
//5.������Ƚ϶̵Ĳ��ֶ�һ����������ȥ����ͬ�Ĳ��֣�����λ�Ƚ�

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int countzero(const string& s){
	for(int i=0;i<s.length();++i){
		if(s[i]!='0')
			return i;
	}
	return s.length();
}

string deletezero(string s){
	return s.erase(0,countzero(s));
}

/*
bool comp(string lhs,string rhs){
	if(countzero(lhs)!=countzero(rhs)){
		return countzero(lhs) > countzero(rhs);
	}else{
		lhs=deletezero(lhs);
		rhs=deletezero(rhs);
		if(lhs.length()==rhs.length()){
			return lhs < rhs;
		}else{
			int m=lhs.size()<rhs.size()? lhs.size():rhs.size();
			string l1(lhs.begin(),lhs.begin()+m);
			string r1(rhs.begin(),rhs.begin()+m);
			if(l1!=r1){
				return l1<r1;
			}else{
				if(m==lhs.size()){
					int j=0;
					for(int i=m;i<rhs.size();++i){
						if(rhs[i]!=lhs[j]){
							return rhs[i]<lhs[j];
						}
						j=(j+1)%m;
					}
				}else{
					int j=0;
					for(int i=m;i<lhs.size();++i){
						if(lhs[i]!=rhs[j]){
							return lhs[i]<rhs[j];
						}
						j=(j+1)%m;
					}
				}
			}
		}
	}
	return false;
}
*/

bool comp(string lhs,string rhs){
	return lhs+rhs<rhs+lhs;
}

int main(){
	int n;
	cin>>n;
	if(n==0){
		cout<<"0"<<endl;
		return 0;
	}
	vector<string> nums(n);
	for(int i=0;i<n;++i){
		cin>>nums[i];
	}
	sort(nums.begin(),nums.end(),comp);
	
	int i=0;
	while(i<n && (nums[i]=deletezero(nums[i]),nums[i].size()==0)){
		++i;
	}
	if(i==n){
		cout<<"0"<<endl;
		return 0;
	}
	for(;i<n;++i){
		cout<<nums[i];
	}
	
	cout<<endl;
	return 0;
	
}