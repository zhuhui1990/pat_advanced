#include <iostream>
#include <string>

using namespace std;

struct Student{
	string name;
	char gender;
	string id;
	int score;
};

int main(){
	int n;
	cin>>n;
	Student maxgirl;
	Student minboy;
	int maxscore=-1;
	int minscore=101;
	Student stu;
	for(int i=0;i<n;++i){
		cin>>stu.name>>stu.gender>>stu.id>>stu.score;
		if(stu.gender=='M' && stu.score<minscore){
			minboy=stu;
			minscore=stu.score;
		}
		if(stu.gender=='F' && stu.score>maxscore){
			maxgirl=stu;
			maxscore=stu.score;
		}
	}
	if(maxgirl.name!=""){
		cout<<maxgirl.name<<" "<<maxgirl.id<<endl;
	}else{
		cout<<"Absent"<<endl;
	}
	if(minboy.name!=""){
		cout<<minboy.name<<" "<<minboy.id<<endl;
	}else{
		cout<<"Absent"<<endl;
	}
	if(maxgirl.name!="" && minboy.name!=""){
		cout<<maxgirl.score-minboy.score<<endl;
	}else{
		cout<<"NA"<<endl;
	}
}