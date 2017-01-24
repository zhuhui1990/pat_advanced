#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cstdio>
using namespace std;

enum State{
	on,
	off
};

struct Time{
	int month;
	int day;
	int hour;
	int minute;
	State st;
};

bool comp (const Time& lhs, const Time rhs){
	if(lhs.month!=rhs.month){
		return lhs.month<rhs.month;
	}else if(lhs.day!=rhs.day){
		return lhs.day<rhs.day;
	}else if(lhs.hour!=rhs.hour){
		return lhs.hour<rhs.hour;
	}else{
		return lhs.minute<rhs.minute;
	}
}

Time operator -(const Time& lhs, const Time rhs){
	Time res;
	res.month=lhs.month-rhs.month;
	res.day=lhs.day-rhs.day;
	res.hour=lhs.hour-rhs.hour;
	res.minute=lhs.minute-rhs.minute;
	return res;
}

inline int time2int(const Time& t){
	return t.minute+60*t.hour+24*60*t.day;
}

struct Data{
	vector<Time> time;
	vector<int> ons,offs;
};

void computeAndOutput(int begin,int end,const vector<Time>& tt,const vector<int>& ons,const vector<int>& offs,const vector<double>& rates){
			int month=tt[ons[begin]].month;
			printf("%02d",tt[ons[begin]].month);
			cout<<endl;
			double total=0.;
			for(int i=begin;i<end;++i){
				printf("%02d:%02d:%02d ",tt[ons[i]].day,tt[ons[i]].hour,tt[ons[i]].minute);
				printf("%02d:%02d:%02d ",tt[offs[i]].day,tt[offs[i]].hour,tt[offs[i]].minute);
				int last=time2int(tt[offs[i]]-tt[ons[i]]);
				cout<<last<<" $";
				double money=0.;
				int h1=tt[ons[i]].hour+24*tt[ons[i]].day;
				int h2=tt[offs[i]].hour+24*tt[offs[i]].day;
				int hh=h1%24;
				if(h1 != h2){
					money += (rates[hh])*(60.-tt[ons[i]].minute)/100.;
					//cout<<endl;
					//cout<<"money="<<money<<endl;
					hh = h2%24;
					money += (rates[hh])*tt[offs[i]].minute/100.;
					//cout<<endl;
					//cout<<"money="<<money<<endl;
				}else{
				  money += rates[hh]*(tt[offs[i]].minute-tt[ons[i]].minute)/100.;
				}
				for(int h=h1+1;h<h2;++h){
					hh=h%24;
					//cout<<"hh="<<hh<<" rates="<<rates[hh]<<endl;
					money += (rates[hh])*60./100.;
				}
				cout<<money<<endl;
				total+=money;
			}
			cout<<"Total amount: $"<<total<<endl;
}


int main(){
	vector<double> rates(24);
	for(int i=0;i<24;++i){
		cin>>rates[i];
	}
	map<string,Data> customers;
	int n;
	cin>>n;
	string s;
	Time t;
	string a;
	State state;
	for(int i=0;i<n;++i){
		cin>>s;
		scanf("%d:%d:%d:%d",&t.month,&t.day,&t.hour,&t.minute);
		cin>>a;
		//cout<<"i="<<i<<" "<<t.month<<" "<<t.day<<" "<<t.hour<<" "<<t.minute<<endl;
		if(a=="on-line")
			t.st=on;
		else if(a=="off-line")
			t.st=off;
		if(customers.find(s) == customers.end()){
			Data newdata;
			newdata.time.push_back(t);
			customers.insert({s,newdata});
		}else{
				customers[s].time.push_back(t);		
		}
	}
	
	for(auto it=customers.begin();it!=customers.end();++it){

		cout<<setprecision(2)<<fixed;
		vector<Time>& tt=it->second.time;
		vector<int>& ons=it->second.ons;
		vector<int>& offs=it->second.offs;
		sort(tt.begin(),tt.end(),comp);
		/*
		cout<<it->first<<endl;
		for(int i=0;i<tt.size();++i){
			cout<<tt[i].month<<":"<<tt[i].day<<":"<<tt[i].hour<<":"<<tt[i].minute<<endl;
		}
		cout<<endl;
		*/
		for(int i=0; i < tt.size()-1;){
			if(tt[i].st == on && tt[i+1].st == off){
				ons.push_back(i);
				offs.push_back(i+1);
				i += 2;
			}else if(tt[i].st == on && tt[i+1].st == on){
				++i;
			}else if(tt[i].st == off){
				++i;
			}
		}
		
		int begin=0,end=0;
		if(ons.size()>0){
			cout<<it->first<<" ";
			computeAndOutput(0,ons.size(),tt,ons,offs,rates);
			/*while(end<ons.size()){
				int i=begin;
				while(tt[ons[i]].month == tt[ons[begin]].month && i<ons.size()){
					++i;
				}
				end=i;
				//cout<<"begin="<<begin<<" end="<<end<<endl;
				cout<<it->first<<" ";
				computeAndOutput(begin,end,tt,ons,offs,rates);
				begin=end;
			}
			*/
		}
		
	}
	
	return 0;
}