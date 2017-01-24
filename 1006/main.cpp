#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Student{
	string id;
	int h1,m1,s1;
	int h2,m2,s2;
};

bool comp_starttime(const Student& stu1, const Student& stu2){
	if(stu1.h1 != stu2.h1){
		return stu1.h1 < stu2.h1;
	}else if(stu1.m1 != stu2.m1){
		return stu1.m1 < stu2.m1;
	}else{
		return stu1.s1 < stu2.s1;
	}
}

bool comp_endtime(const Student& stu1, const Student& stu2){
	if(stu1.h2 != stu2.h2){
		return stu1.h2 < stu2.h2;
	}else if(stu1.m2 != stu2.m2){
		return stu1.m2 < stu2.m2;
	}else{
		return stu1.s2 < stu2.s2;
	}
}

int main(){
	int n;
	cin>>n;
	vector<Student> students(n);
	for(int i=0;i<n;++i){
		cin>>students[i].id;
		scanf("%2d:%2d:%2d %2d:%2d:%2d",&students[i].h1,&students[i].m1,&students[i].s1,&students[i].h2,&students[i].m2,&students[i].s2);
	}
	nth_element(students.begin(),students.begin(),students.end(),comp_starttime);
	cout<<students[0].id<<" ";
	nth_element(students.begin(),students.begin()+n-1,students.end(),comp_endtime);
	cout<<students[n-1].id<<endl;
	return 0;
}