#include <iostream>
#include <vector>

using namespace std;

struct City{
	string name;
	int happiness;
	vector<int> neighb;
	vector<int> cost;
	City(string s):name(s),happiness(0),neighb(),cost(){
	}
	City(string s,int h):name(s),happiness(h),neighb(),cost(){
	}
	City():name(""),happiness(0),neighb(),cost(){
	}
};

int find(const string& s,const vector<City>& cities){
	for(int i=0;i<cities.size();++i){
		if(s==cities[i].name){
			return i;
		}
	}
	return -1;
}

int find(int a,const vector<int>& vec){
	for(int i=0;i<vec.size();++i){
		if(a==vec[i]){
			return i;
		}
	}
	return -1;
}

void DFS(int i,const int& d,int& cost,int& happiness,int& cnt,int& mincost,int& maxhappiness,int& sumhappiness,vector<int>& route,vector<int>& visited,const vector<City>& cities){
	//cout<<"i="<<i<<" d="<<d<<" cost="<<cost<<" happiness="<<happiness<<" cnt="<<cnt;
	//cout<<" mincost="<<mincost<<" maxhappiness="<<maxhappiness<<" sumhappiness="<<sumhappiness<<endl;
	if(i==d){
		if(cost<mincost){
			mincost=cost;
			cnt=1;
			maxhappiness=happiness;
			sumhappiness=happiness;
			route=visited;
		}else if(cost==mincost){
			++cnt;
			sumhappiness+=happiness;
			if(happiness>maxhappiness){
				maxhappiness= happiness;
				route=visited;
			}else if(happiness/visited.size()>maxhappiness/route.size()){
				maxhappiness= happiness;
				route=visited;
			}
		}
	}else{
		for(int j=0;j<cities[i].neighb.size();++j){
			int c1=cities[i].neighb[j];
			//cout<<"c1="<<c1<<" find="<<find(c1,visited)<<endl;
			if(find(c1,visited)==-1 && cost<mincost ){
				visited.push_back(c1);
				happiness+=cities[c1].happiness;
				cost +=cities[i].cost[j];
				DFS(c1,d,cost,happiness,cnt,mincost,maxhappiness,sumhappiness,route,visited,cities);
				visited.pop_back();
				happiness-=cities[c1].happiness;
				cost -=cities[i].cost[j];
			}
		}
	}
}


int main(){
	const int inf=0xffffff;
	int n,k;
	cin>>n>>k;
	string s;
	int h;
	vector<City> cities(n);
	cin>>s;
	cities[0]=City(s);
	for(int i=1;i<n;++i){
		cin>>s>>h;
		cities[i]=City(s,h);
	}
	int c1,c2;
	string s1,s2;
	int w;
	for(int i=0;i<k;++i){
		cin>>s1>>s2>>w;
		c1=find(s1,cities);
		c2=find(s2,cities);
		cities[c1].neighb.push_back(c2);
		cities[c2].neighb.push_back(c1);
		cities[c1].cost.push_back(w);
		cities[c2].cost.push_back(w);
	}
	int cost=0;
	int mincost=inf;
	int cnt=0;
	int happiness=0;
	int maxhappiness=0;
	int sumhappiness=0;
	int d=find("ROM",cities);
	vector<int> visited;
	visited.push_back(0);
	vector<int> route;
	
	DFS(0,d,cost,happiness,cnt,mincost,maxhappiness,sumhappiness,route,visited,cities);
	cout<<cnt<<" "<<mincost<<" "<<maxhappiness<<" "<<maxhappiness/(route.size()-1)<<endl;
	cout<<cities[route[0]].name;
	for(int i=1;i<route.size();++i){
		cout<<"->"<<cities[route[i]].name;
	}
	cout<<endl;
}