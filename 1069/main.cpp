#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

void int2vec(int a,vector<int>& vec){
	//µ¹Ðò´æ´¢
	vec.clear();
	if(a<1000)
		vec.push_back(0);
	if(a<100)
		vec.push_back(0);
	if(a<10)
		vec.push_back(0);
	while(a>0){
		vec.push_back(a%10);
		a /= 10;
	}
}

int vec2int(const vector<int> vec){
	if(vec.size()==0)
		return 0;
	int res=vec[0];
	for(int i=1;i<vec.size();++i)
		res = res*10+vec[i];
	return res;
}

inline bool ge(const int& a, const int& b){
	return a>=b;
}

inline bool le(const int& a, const int& b){
	return a<=b;
}

int main(){
	int n;
	cin>>n;
	vector<int> vec;
	do{
		int2vec(n,vec);
		sort(vec.begin(),vec.end(),ge);
		int n1=vec2int(vec);
		sort(vec.begin(),vec.end(),le);
		int n2=vec2int(vec);
		n = n1 - n2;
		printf("%04d - %04d = %04d\n", n1, n2, n); 
	}while(n != 6174 && n != 0);
	return 0;
}