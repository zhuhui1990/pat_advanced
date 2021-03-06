#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student{
	string id;
	double c,m,e,a;
	int rank;
	char best;
};


inline bool compA(const Student& lhs, const Student& rhs) {
		return lhs.a>rhs.a;
}
inline bool compC(const Student& lhs, const Student& rhs) {
		return lhs.c>rhs.c;
}
inline bool compM(const Student& lhs, const Student& rhs) {
		return lhs.m>rhs.m;
}
inline bool compE(const Student& lhs, const Student& rhs) {
		return lhs.e>rhs.e;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<Student> stu(n);
	
	for(int i=0;i<n;++i){
		cin>>stu[i].id>>stu[i].c>>stu[i].m>>stu[i].e;
		stu[i].a = stu[i].c+stu[i].m+stu[i].e;
		stu[i].a /= 3.;
		stu[i].rank=n+1;
	}

	sort(stu.begin(),stu.end(),compA);
	for(int i=0;i<n;++i){
		int j=i;
		while(j>=1 && stu[j].a==stu[j-1].a){
			--j;
		}
		if(j<stu[i].rank){
			stu[i].rank=j;
			stu[i].best='A';

		}

	}
	sort(stu.begin(),stu.end(),compC);
	for(int i=0;i<n;++i){
		int j=i;
		while(j>=1 && stu[j].c==stu[j-1].c){
			--j;
		}
		
		if(j<stu[i].rank){
			stu[i].rank=j;
			stu[i].best='C';
		}
	}
	sort(stu.begin(),stu.end(),compM);
	for(int i=0;i<n;++i){
		int j=i;
		while(j>=1 && stu[j].m==stu[j-1].m){
			--j;
		}
		if(j<stu[i].rank){
			stu[i].rank=j;
			stu[i].best='M';
		}

	}
	sort(stu.begin(),stu.end(),compE);
	for(int i=0;i<n;++i){
		int j=i;
		while(j>=1 && stu[j].e==stu[j-1].e){
			--j;
		}
		if(j<stu[i].rank){
			stu[i].rank=j;
			stu[i].best='E';
		}
	}
	string temp;
	for(int i=0;i<m;++i){
		cin>>temp;
		auto it=stu.begin();
		for(;it!=stu.end();++it){
			if(it->id==temp){
				cout<<it->rank+1<<" "<<it->best<<endl;
				break;
			}
		}
		if(it==stu.end())
			cout<<"N/A"<<endl;
	}
	return 0;
}