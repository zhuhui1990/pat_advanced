#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
using namespace std;
int N;
int cluster[1001]={0};
int findRoot(int x){
	if(cluster[x] == x)
		return x;
	// cout<<"***"<<endl;
	int rx = cluster[x];
	while(cluster[rx]!=rx){
		int rrx = findRoot(rx);
		rx = rrx;
	}
	cluster[x] = rx;
	return rx;
}
void Union(int a, int b){
	int ra = findRoot(a);
	int rb = findRoot(b);
	cluster[rb] = ra;
}
int main(void)
{
	cin>>N;
	vector<int> hobbies;
	vector<int> person(N);
	for(int i = 1; i <= N; i++){
		int number;
		cin>>number;
		getchar();
		hobbies.clear();
		hobbies.resize(number);
		for(int j = 0; j < number; j++){
			cin>>hobbies[j];
			if(cluster[hobbies[j]] <= 0)
				cluster[hobbies[j]] = hobbies[j];
		}
		if(hobbies.size() > 1){
			for(int j = 1; j < hobbies.size(); j++){
				Union(hobbies[0],hobbies[j]);
			}
		}
		person[i-1] = findRoot(hobbies[0]);
	}
	set<int> count;
	for(int i = 1; i <= 1000; i++){
		if(cluster[i] <= 0)
			continue;
		int tmp = findRoot(cluster[i]);
		count.insert(tmp);
	}
	vector<int> result(1001,0);
	for(int i = 0; i < N; i++){
		person[i] = findRoot(person[i]);
		result[person[i]]++;
	}
	cout<<count.size()<<endl;
	sort(result.begin(),result.end(),greater<int>());
	for(int i = 0; i <= 1001; i++){
		if(result[i] <= 0)
			break;
		if(i)
			cout<<" "<<result[i];
		else
			cout<<result[i];
	}
	return 0;
}