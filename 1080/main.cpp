#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Student{
	int id;
	int ge;
	int gi;
	int gtotal;
	int rank;
	vector<int> choice;
};

//用comp函数会段错误，必须用operator <
bool operator <(const Student& lhs, const Student& rhs){
	return lhs.gtotal == rhs.gtotal ? lhs.ge>rhs.ge:lhs.gtotal > rhs.gtotal;
}


int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> quota(m);
	for(int i=0;i<m;++i){
		cin>>quota[i];
	}
	vector<Student> stu(n);
	for(int i=0;i<n;++i){
		stu[i].id=i;
		cin>>stu[i].ge>>stu[i].gi;
		stu[i].gtotal=stu[i].ge+stu[i].gi;
		stu[i].choice.resize(k);
		for(int j=0;j<k;++j){
			cin>>stu[i].choice[j];
		}
	}
	sort(stu.begin(),stu.end());
	int rank=0;
	stu[0].rank=0;
	//int i=0;
	//cout<<"i="<<i<<" id="<<stu[i].id<<" gtotal="<<stu[i].gtotal<<" ge="<<stu[i].ge<<" rank="<<stu[i].rank<<endl;
	for(int i=1;i<n;++i){
		if(stu[i-1].gtotal == stu[i].gtotal && stu[i-1].ge == stu[i].ge){
			stu[i].rank=stu[i-1].rank;
		}else{
			stu[i].rank=i;
		}
		//cout<<"i="<<i<<" id="<<stu[i].id<<" gtotal="<<stu[i].gtotal<<" ge="<<stu[i].ge<<" rank="<<stu[i].rank<<endl;
	}
	vector<set<int>> college(m);
	vector<int> lowrank(m,-1);
	int c;
	for(int i=0;i<n;++i){
		for(int j=0;j<k;++j){
			c=stu[i].choice[j];
			if(college[c].size()<quota[c] || ( lowrank[c] == stu[i].rank)){
				college[c].insert(stu[i].id);
				lowrank[c]=stu[i].rank;
				break;
			}
			
		}
	}
	for(int i=0;i<m;++i){
		if(!college[i].empty()){
			auto it=college[i].begin();
			cout<<*it;
			++it;
			for(;it!=college[i].end();++it){
				cout<<" "<<*it;
			}
		}
		cout<<endl;
	}
	
	return 0;
}