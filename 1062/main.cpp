#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct Student{
	int id;
	int de;
	int cai;
	bool operator < (const Student& b) const{
		if(de+cai != b.de+b.cai)
			return (de+cai >b.de+ b.cai);
		else
			if(de != b.de)
				return (de > b.de);
			else
				return (id < b.id);
	}
};

int main(){
	int n,l,h;
	cin>>n>>l>>h;
	int cnt=0;
	vector<Student> type1,type2,type3,type4;
	Student temp;
	for(int i=0;i<n;++i){
		cin>>temp.id>>temp.de>>temp.cai;
		if(temp.de<l || temp.cai<l)
			continue;
		if(temp.de>=h && temp.cai>=h){
			type1.push_back(temp);
			++cnt;
		}
		else if(temp.de>=h && temp.cai<h && temp.cai>=l){
			type2.push_back(temp);
			++cnt;
		}
		else if(temp.de<h && temp.de>=l && temp.cai<h && temp.cai>=l && temp.de>=temp.cai){
			type3.push_back(temp);
			++cnt;
		}else if(temp.de>=l &&temp.cai>=l){
			type4.push_back(temp);
			++cnt;
		}
	}
	sort(type1.begin(),type1.end());
	sort(type2.begin(),type2.end());
	sort(type3.begin(),type3.end());
	sort(type4.begin(),type4.end());
	cout<<cnt<<endl;
	for(int i=0;i<type1.size();++i)
		printf("%d %d %d\n", type1[i].id,type1[i].de,type1[i].cai);
	for(int i=0;i<type2.size();++i)
		printf("%d %d %d\n", type2[i].id,type2[i].de,type2[i].cai);
	for(int i=0;i<type3.size();++i)
		printf("%d %d %d\n", type3[i].id,type3[i].de,type3[i].cai);
	for(int i=0;i<type4.size();++i)
		printf("%d %d %d\n", type4[i].id,type4[i].de,type4[i].cai);
	return 0;
}