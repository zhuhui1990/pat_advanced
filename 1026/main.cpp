#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Player{
	int arrivetime;
	int servetime;
	int playtime;
	bool vip;
};

struct Table{
	int served;
	int time;
	bool vip;
	bool isfree;
};

inline int hmsToTime(const int& hour,const int& minute,const int& second){
	return hour*3600+minute*60+second;
}

inline void timeToHMS(int time,int& hour,int& minute,int& second){
	second=time%60;
	time/=60;
	minute=time%60;
	hour=time/60;
} 

inline bool comp(const Player& lhs,const Player& rhs){
	return lhs.arrivetime<rhs.arrivetime;
}

inline bool comp1(const Player& lhs,const Player& rhs){
	if(lhs.servetime != rhs.servetime){
		return lhs.servetime<rhs.servetime;
	}else{
		return lhs.vip;
	}
}

int main(){
	const int opentime=8*3600;
	const int closetime=21*3600;
	int n;
	cin>>n;
	vector<Player> players(n);
	int hour,minute,second;
	int playtime;
	int flag;
	for(int i=0;i<n;++i){
		scanf("%d:%d:%d %d %d",&hour,&minute,&second,&playtime,&flag);
		players[i].arrivetime=hmsToTime(hour,minute,second);
		players[i].playtime=playtime*60;
		if(players[i].playtime>7200)
			players[i].playtime=7200;
		players[i].vip= flag==1? true:false;
		players[i].servetime=closetime+1;
	}
	int m,mvip,vtables=0;
	cin>>m>>mvip;
	vector<Table> tables(m);
	for(int i=0;i<mvip;++i){
		int temp;
		cin>>temp;
		tables[temp-1].vip=true;
		++vtables;
	}
	int nvtables=m-vtables;
	for(int i=0;i<m;++i){
		tables[i].served=0;
		tables[i].time=opentime;
		tables[i].isfree=true;
	}
	sort(players.begin(),players.end(),comp);

	
	int j=0;//按照到达顺序的玩家编号

	queue<int> q;//普通玩家
	queue<int> vq;//vip玩家
	
	int vipcnt=0,nvipcnt=0; //正在使用的vip桌和非vip桌
	//模拟一个时钟
	//算法复杂度最高，但是最不容易出错
	for(int i=opentime;i<closetime;++i){
		//离开桌子
		for(int k=0;k<m;++k){
			if(tables[k].isfree){
				continue;
			}else{
				if(tables[k].time==i){
					tables[k].isfree=true;
					if(tables[k].vip){
						--vipcnt;
					}else{
						--nvipcnt;
					}
				}
			}
		}
		//加入队伍
		while(players[j].arrivetime==i && j<n){
			if(players[j].vip){
				vq.push(j);
			}else{
				q.push(j);
			}
			++j;
		}
		if(vipcnt+nvipcnt==m){//当前没有空桌
			continue;
		}
		//排队的人上桌，有vip桌时先满足vip玩家
		for(int k=vipcnt;k<vtables;++k){
			int id;
			if(!vq.empty()){ //有vip用户在排队
				id=vq.front();

			}else{//没有vip用户在排队
				break;
			}
			int pos=-1;
			for(int t=0;t<m;++t){//寻找空桌
				if(tables[t].isfree && tables[t].vip){
					pos=t;
					break;
				}
			}
			if(pos==-1){//没找到空桌
				break;
			}
			players[id].servetime=i;
			tables[pos].time=i+players[id].playtime;
			tables[pos].isfree=false;
			++tables[pos].served;
			++vipcnt;
			timeToHMS(players[id].arrivetime,hour,minute,second);
			printf("%02d:%02d:%02d ",hour,minute,second);
			timeToHMS(players[id].servetime,hour,minute,second);
			printf("%02d:%02d:%02d ",hour,minute,second);
			int waittime=players[id].servetime-players[id].arrivetime;
			timeToHMS(waittime,hour,minute,second);
			if(second>=30){
				++minute;
			}
			minute+=60*hour;
			printf("%d",minute);
			cout<<endl;
			vq.pop();
		}

		if(vipcnt+nvipcnt==m){//当前没有空桌
			continue;
		}
		//其他情况的排队上桌
		for(int k=0;k<m;++k){
			int id;
			int qq=0;
			if(q.empty() && vq.empty()){ //没人在排队
				break;
			}else if(q.empty() && !vq.empty()){//有人在排队
				id=vq.front();
				qq=1;
			}else if(!q.empty() && vq.empty()){
				id=q.front();
				qq=0;
			}else{
				int id1=q.front();
				int id2=vq.front();
				if(players[id1].arrivetime<players[id2].arrivetime){
					id=id1;
					qq=0;
				}else{
					id=id2;
					qq=1;
				}
			}
			int pos=-1;
			for(int t=0;t<m;++t){//寻找空桌
				if(tables[t].isfree){
					pos=t;
					break;
				}
			}
			if(pos==-1){//没找到空桌
				break;
			}
			players[id].servetime=i;
			tables[pos].time=i+players[id].playtime;
			tables[pos].isfree=false;
			++tables[pos].served;
			if(tables[pos].vip){
				++vipcnt;
			}else{
				++nvipcnt;
			}
			timeToHMS(players[id].arrivetime,hour,minute,second);
			printf("%02d:%02d:%02d ",hour,minute,second);
			timeToHMS(players[id].servetime,hour,minute,second);
			printf("%02d:%02d:%02d ",hour,minute,second);
			int waittime=players[id].servetime-players[id].arrivetime;
			timeToHMS(waittime,hour,minute,second);
			if(second>=30){
				++minute;
			}
			minute+=60*hour;
			printf("%d",minute);
			cout<<endl;
			if(qq==0)
				q.pop();
			else
				vq.pop();
		}
	}

	

	cout<<tables[0].served;
	for(int i=1;i<m;++i){
		cout<<" "<<tables[i].served;
	}
	cout<<endl;
	return 0;
}