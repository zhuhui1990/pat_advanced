#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#define INF 0x6fffffff  
using namespace std;

struct Customer{
	int id;
	int usetime;
	int arrivetime;
	int starttime;
	int endtime;
	inline bool operator < (const Customer& rhs) const{
		return arrivetime<rhs.arrivetime;
	}
};

struct Window{
	int time;
};

int main(){
	const int open=8*3600;
	const int close=17*3600;
	int n,k;
	cin>>n>>k;
	vector<Customer> cus(n);
	vector<Window> win(k);
	int hour,minute,second;
	for(int i=0;i<n;++i){
		scanf("%d:%d:%d %d",&hour,&minute,&second,&cus[i].usetime);
		cus[i].usetime *= 60;
		cus[i].arrivetime = hour*3600+minute*60+second;
		cus[i].id=i;
	}
	sort(cus.begin(),cus.end());
	for(int i=0;i<k;++i){
		win[i].time=open;
	}
	int total=0;
	//第一批客户
	int i=0;
	for(int j=0;i<k && i<n;++i,j=(j+1)%k){
		cus[i].starttime = cus[i].arrivetime<win[j].time?win[j].time:cus[i].arrivetime;
		cus[i].endtime = cus[i].starttime+cus[i].usetime;
		win[j].time = cus[i].endtime;
	}
	//其余客户
	int mintime;
	int id,pos;
	for(;i<n;++i){
		//cout<<"i="<<i<<endl;
		mintime=INF; //过了close时间，继续处理那些已经在排队的顾客
		for(int j=0;j<k;++j){
			if(win[j].time<mintime){
				mintime=win[j].time;
				pos=j;
			}
		}
		//cout<<"id="<<id<<" pos="<<pos<<endl;
		cus[i].starttime=cus[i].arrivetime<win[pos].time?win[pos].time:cus[i].arrivetime;
		cus[i].endtime = cus[i].starttime+cus[i].usetime;
		win[pos].time = cus[i].endtime;
	}
	
	int cnt=0;
	for(int i=0;i<n;++i){
		if(cus[i].arrivetime<=close){
			//cout<<"i="<<i<<" arrive="<<cus[i].arrivetime-open<<" start="<<cus[i].starttime-open<<endl;
			total+=cus[i].starttime-cus[i].arrivetime;
			++cnt;
		}
	}
		
	if(cnt==0){
		cout<<"0.0"<<endl;
		return 0;
	}
	cout<<setprecision(1)<<fixed;
	cout<<double(total)/cnt/60.<<endl;
	
	return 0;
}