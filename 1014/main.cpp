#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Customer{
	int id;
	int starttime;
	int usetime;
	int endtime;
};

struct Window{
	int time=0;
	queue<Customer*> q;	
};

string intToString(const int& i){
	string res;
	if(i<10){
		res += "0";
		char c=i+'0';
		res += c;
	}else{
		char c1=i/10+'0';
		char c2=i%10+'0';
		res += c1;
		res += c2;
	}	
	return res;
}

bool isSorry(const int& stime){
	return stime>=9*60;
}

string timeToString(const int& etime){
	string s;
	int hour=etime/60;
	int minute=etime%60;
	hour += 8;
	s += intToString(hour);
	s += ":";
	s += intToString(minute);
	return s;
}



int main(){
	int n,m,k,q;
	cin>>n>>m>>k>>q;
	vector<Customer> customer(k);
	for(int i=0;i<k;++i){
		cin>>customer[i].usetime;
		customer[i].id=i;
	}
	vector<Window> window(n);
	int minwindow;
	//第一批客户
	int i=0;
	for(int j=0;i<m*n && i<k; ++i, j=(j+1)%n){
		customer[i].starttime = window[j].time;
		customer[i].endtime = customer[i].starttime + customer[i].usetime;
		window[j].time += customer[i].usetime;
		window[j].q.push(&customer[i]);
	}
	//其余客户
	int mintime;
	int id,pos;
	for(;i<k;++i){
		mintime=(17-8)*60+1;
		for(int j=0;j<n;++j){
			id=window[j].q.front()->id;
			if(customer[id].endtime<mintime){
				mintime=customer[id].endtime;
				pos=j;
			}
		}
		//cout<<"i="<<i<<" pos="<<pos<<endl;
		
		customer[i].starttime=window[pos].time;
		customer[i].endtime = customer[i].starttime+customer[i].usetime;
		window[pos].time += customer[i].usetime;
		window[pos].q.pop();
		window[pos].q.push(&customer[i]);	
	}
	//cout<<"other customers complete"<<endl;
	string s;
	for(int i=0;i<q;++i){
		cin>>id;
		if(isSorry(customer[id-1].starttime)){
			cout<<"Sorry"<<endl;
			continue;
		}
		s=timeToString(customer[id-1].endtime);
		cout<<s<<endl;
	}
	return 0;
}