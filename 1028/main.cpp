#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

struct Student{
	string id;
	string name;
	int score;
};

inline bool comp1(const Student& lhs,const Student& rhs){
	return lhs.id<rhs.id;
}

inline bool comp2(const Student& lhs,const Student& rhs){
	if(lhs.name!=rhs.name){
		return lhs.name<rhs.name;
	}else{
		return lhs.id<rhs.id;
	}
}

inline bool comp3(const Student& lhs,const Student& rhs){
	if(lhs.score!=rhs.score){
		return lhs.score<rhs.score;
	}else{
		return lhs.id<rhs.id;
	}
}

int main(){
	int n,m;
	//cin>>n>>m;
	scanf("%d%d",&n,&m);
	vector<Student> stu(n);
	for(int i=0;i<n;++i){
		stu[i].id.resize(100);
		stu[i].name.resize(100);
		scanf("%s%s%d",&stu[i].id[0],&stu[i].name[0],&stu[i].score);
	}
	if(m==1){
		sort(stu.begin(),stu.end(),comp1);
	}else if(m==2){
		sort(stu.begin(),stu.end(),comp2);
	}else if(m==3){
		sort(stu.begin(),stu.end(),comp3);
	}
	for(int i=0;i<n;++i){
		//cout<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
		printf("%s %s %d\n",stu[i].id.c_str(),stu[i].name.c_str(),stu[i].score);
	}
	return 0;
}