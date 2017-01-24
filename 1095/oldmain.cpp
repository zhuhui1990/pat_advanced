#include <iostream>
#include <unordered_map>
#include <map>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

enum State{
	in,
	out
};

struct Time{
	int   t;
	State st;
	bool flag;
};

inline bool operator < (const Time& lhs, const Time& rhs){
	return lhs.t<rhs.t;
}

inline int hms2time(const int& hour,const int& minute,const int& second){
	return hour*3600+minute*60+second;
}

inline State str2state(const char* s){
	return strcmp(s,"in")==0? in:out;
}

int getLocation(const int& a,const vector<Time>& vec){
	//cout<<"a="<<a<<" vec[0]="<<vec[0]<<" vec.back()="<<vec.back()<<endl;
	int nextin,nextout;
	if(a<vec1[0] || a>vec1.back()){
		return 0;
	}
	for(int i=1;i<vec1.size();++i){
		if(a >= vec1[i-1] && a < vec1[i]){
			return i;
		}
	}
}

void time2hms(int time,int& hour,int& minute,int& second){
	second = time % 60;
	time /= 60;
	minute = time % 60;
	hour = time / 60;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	unordered_map<string,vector<Time>> cars;
	char s[10],s1[5];
	int hour,minute,second,time;
	for(int i=0;i<n;++i){
		scanf("%s %d:%d:%d %s",s,&hour,&minute,&second,s1);
		//cout<<"i="<<i<<" s="<<s<<" s1="<<s1<<endl;
		//cout<<"hour="<<hour<<" minute="<<minute<<" second="<<second<<endl;
		//cout<<"time="<<hms2time(hour,minute,second)<<endl;
		cars[s].push_back({hms2time(hour,minute,second),str2state(s1)});
	}
	
	//unordered_map<string,vector<int>> processed;
	for(auto it=cars.begin();it!=cars.end();++it){
		vector<Time>& rvt=it->second;
		sort(rvt.begin(),rvt.end());
		//去掉无效信息
		//vector<int> ts;
		//cout<<"car="<<it->first<<endl;
		//cout<<"size="<<rvt.size()<<endl;
		for(int ii=0;ii+1<rvt.size();){
			//cout<<"   rvt[ii].st="<<rvt[ii].st<<" rvt[ii+1].st="<<rvt[ii+1].st<<endl;
			if(rvt[ii].st == in && rvt[ii+1].st == out){
				//cout<<"it1->t="<<it1->t<<" (it1+1)->t="<<(it1+1)->t<<endl;
				rvt[ii].flag=true;
				rvt[ii+1].flag=true;
				//cout<<"it1->t="<<it1->t<<" (it1+1)->t="<<(it1+1)->t<<endl;
				//printf("%d %d\n",rvt[ii].t,rvt[ii+1].t);
				//ts.push_back(t1);
				//ts.push_back(t2);
				ii += 2;
			}else{
				rvt[ii].flag=false;
				++ii;
			}
		}
		//if(!ts.empty()){
		//	processed.insert({it->first,ts});
		//}
	}
	//cout<<"process complete"<<endl;
	int cnt;
	int loc;
	for(int i=0;i<k;++i){
		scanf("%d:%d:%d",&hour,&minute,&second);
		time = hms2time(hour,minute,second);
		cnt = 0;
		for(auto it=cars.begin();it!=cars.end();++it){
			//cout<<"car="<<it->first<<" size="<<it->second.size()<<endl;
			loc=getLocation(time,it->second);
			if(loc%2!=0){
				//cout<<it->first<<endl;
				++cnt;
			}
		}
		cout<<cnt<<endl;
	}
	set<string> res;
	int max=0;
	int t=0;
	for(auto it=cars.begin();it!=cars.end();++it){
		vector<int>& rv=it->second;
		t=0;
		//cout<<"car="<<it->first<<endl;
		for(int ii=0;ii+1<rv.size();ii+=2){
			//cout<<"   in="<<rv[ii]<<" out="<<rv[ii+1]<<endl;
			t += rv[ii+1]-rv[ii];
		}
		if(t > max){
			res.clear();
			res.insert(it->first);
			max=t;
		}else if(t == max){
			res.insert(it->first);
		}
	}
	for(auto it=res.begin();it!=res.end();++it){
		cout<<*it<<" ";
	}
	time2hms(max,hour,minute,second);
	printf("%02d:%02d:%02d\n",hour,minute,second);
	
 //ZD00001 11:30:08 out
 //ZD00001 04:09:59 in
	
	return 0;
}