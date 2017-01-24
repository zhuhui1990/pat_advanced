#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Team{
	string name;
	string password;
	Team():name(),password(){
	}	
	Team(const string& s1,const string& s2):name(s1),password(s2){
	}
};

int main(){
	int n;
	cin>>n;
	vector<Team> teams;
	int cnt=0;
	string s1,s2;
	for(int i=0;i<n;++i){
		cin>>s1>>s2;
		bool flag=false;
		for(int j=0;j<s2.length();++j){
			if(s2[j]=='1'){
				s2[j]='@';
				flag=true;
			}
			if(s2[j]=='0'){
				s2[j]='%';
				flag=true;
			}
			if(s2[j]=='l'){
				s2[j]='L';
				flag=true;
			}
			if(s2[j]=='O'){
				s2[j]='o';
				flag=true;
			}
		}
		if(flag){
			teams.push_back(Team(s1,s2));
		}
	}
	if(teams.size()>0){
		cout<<teams.size()<<endl;
		for(int i=0;i<teams.size();++i){
			cout<<teams[i].name<<" "<<teams[i].password<<endl;
		}
	}else{
		if(n==1){
			cout<<"There is 1 account and no account is modified"<<endl;
		}else{
			cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
		}
	}
	return 0;
}