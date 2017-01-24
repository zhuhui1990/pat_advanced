#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student{
	string name;
	string id;
	int score;
};

inline bool comp(const Student&lhs,const Student& rhs){
	return lhs.score > rhs.score;
}

int main(){
	int n;
	cin >> n;
	vector<Student> stu(n);
	for (int i = 0; i < n; ++i){
		cin >> stu[i].name >> stu[i].id >> stu[i].score;
	}
	sort(stu.begin(), stu.end(), comp);
	int high, low; 
	cin >>low >> high;
	int cnt = 0;
	for (int i = 0; i < n; ++i){
		if (stu[i].score > high){
			continue;
		}else if (stu[i].score < low){
			break;
		}else{
			++cnt;
			cout << stu[i].name << " " << stu[i].id << endl;
		}
	}
	if (cnt == 0){
		cout << "NONE" << endl;
	}
	//system("pause");
	return 0;
}