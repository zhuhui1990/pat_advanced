#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student{
	string id;
	int score;
	int loc;
	int local_rank;
	int final_rank;
};

bool comp(const Student& lhs, const Student& rhs){
	if(lhs.score!=rhs.score){
		return lhs.score>rhs.score;
	}else{
		return lhs.id<rhs.id;
	}
}

int main(){
	int n;
	cin>>n;
	vector<Student> stu_local;
	vector<Student> stu_global;
	for(int i=0;i<n;++i){
		stu_local.clear();
		int m;
		cin>>m;
		stu_local.resize(m);
		for(int j=0;j<m;++j){
			cin>>stu_local[j].id>>stu_local[j].score;
			stu_local[j].loc=i+1;
		}
		sort(stu_local.begin(),stu_local.end(),comp);
		int rank = 1;
		stu_local[0].local_rank=1;
		stu_global.push_back(stu_local[0]);
		for(int j=1;j<m;++j){
			if(stu_local[j].score==stu_local[j-1].score){
				stu_local[j].local_rank=rank;
			}else{
				rank=j+1;
				stu_local[j].local_rank=rank;
			}
			stu_global.push_back(stu_local[j]);
		}
	}
	sort(stu_global.begin(),stu_global.end(),comp);
	int m=stu_global.size();
	cout<<m<<endl;
	int rank=1;
	stu_global[0].final_rank=1;
	int j=0;
	cout<<stu_global[j].id<<" "<<stu_global[j].final_rank<<" "<<stu_global[j].loc<<" "<<stu_global[j].local_rank<<endl;
	for(int j=1;j<m;++j){
			if(stu_global[j].score==stu_global[j-1].score){
				stu_global[j].final_rank=rank;
			}else{
				rank=j+1;
				stu_global[j].final_rank=rank;
			}
			cout<<stu_global[j].id<<" "<<stu_global[j].final_rank<<" "<<stu_global[j].loc<<" "<<stu_global[j].local_rank<<endl;
	}
	
	return 0;
}