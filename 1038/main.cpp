//排序
//更简单的比较逻辑：
//字符串s1+s2<s2+s1，则s1<s2
//理由：s1+s2和s2+s1位数一定相同，此时直接按照字典序比较


//老版本比较的逻辑：
//1.leading zeroes多的靠前
//2.如果leading zeroes一样多，去掉leading zero之后再比较
//3.如果长度一样，小的在前面
//4.如果长度不一样，只比较长度较短的部分，小的在前面
//5.如果长度较短的部分都一样，将长的去掉相同的部分，再逐位比较

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