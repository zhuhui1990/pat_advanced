#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student{
	string name;
	int height;
	bool operator < (const Student& rhs) const{
		if(height!=rhs.height)
			return height<rhs.height;
		else 
			return name > rhs.name;
	}
};

int main(){
	int n,k;
	cin>>n>>k;
	vector<Student> stu(n);
	vector<vector<string>> mat(k);
	for(int i=0;i<n;++i){
		cin>>stu[i].name>>stu[i].height;
	}
	sort(stu.begin(),stu.end());
	int m=n/k;
	int remain=n%k;
	for(int i=0;i<k-1;++i){
		int high=(i+1)*m-1;
		mat[i].resize(m);
		mat[i][m/2]=stu[high].name;
		int t=m/2-1;
		for(int j=1;j<m;j+=2){ //left
			mat[i][t]=stu[high-j].name;
			--t;
		}
		t=m/2+1;
		for(int j=2;j<m;j+=2){ //right
			mat[i][t]=stu[high-j].name;
			++t;
		}
	}
	m+=remain;
	int high=n-1;
	mat[k-1].resize(m);
	mat[k-1][m/2]=stu[high].name;
	int t=m/2-1;
	for(int j=1;j<m;j+=2){ //left
		mat[k-1][t]=stu[high-j].name;
		--t;
	}
	t=m/2+1;
	for(int j=2;j<m;j+=2){ //right
		mat[k-1][t]=stu[high-j].name;
		++t;
	}
	for(int i=k-1;i>=0;--i){
		for(int j=0;j<mat[i].size()-1;++j){
			cout<<mat[i][j]<<" ";
		}
		cout<<mat[i][mat[i].size()-1]<<endl;
	}
	
	return 0;
}