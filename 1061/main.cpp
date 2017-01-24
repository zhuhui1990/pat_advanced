#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	vector<string> days({"","MON","TUE","WED","THU","FRI","SAT","SUN"});
	string s1,s2;
	cin>>s1>>s2;
	int day,hour,time;
	int i=0;
	for(;;++i){
		if(s1[i]==s2[i] && (s1[i]<='G' && s1[i]>='A')){
			day = s1[i]-'A'+1;
			break;
		}
	}
	++i;
	for(;;++i){
		if(s1[i]==s2[i] && (s1[i]<='N' && s1[i]>='A')){
			hour = 10+s1[i]-'A';
			break;
		}
		if(s1[i]==s2[i] && (s1[i]<='9' && s1[i]>='0')){
			hour = s1[i]-'0';
			break;
		}
	}
	cin>>s1>>s2;
	i=0;
	for(;;++i){
		if(s1[i]==s2[i] && (s1[i]<='Z' && s1[i]>='A')){
			time = i;
			break;
		}
		if(s1[i]==s2[i] && (s1[i]<='z' && s1[i]>='a')){
			time = i;
			break;
		}
	}
	cout<<days[day]<<" ";
	if(hour<10)
	cout<<"0";
	cout<<hour<<":";
	if(time<10)
		cout<<"0";
	cout<<time<<endl;
	return 0;
}