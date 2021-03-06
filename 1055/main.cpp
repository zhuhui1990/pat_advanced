#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Person{
	char name[50];
	int age;
	int money;
};

inline bool operator < (const Person& lhs,const Person& rhs){
	if(lhs.money != rhs.money){
		return lhs.money > rhs.money;
	}else if(lhs.age != rhs.age){
		return lhs.age < rhs.age;
	}else{
		return strcmp(lhs.name,rhs.name)<0;
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n1,n2;
	scanf("%d %d",&n1,&n2);
	vector<Person> ps(n1);
	for(int i=0;i<n1;++i){
		scanf("%s %d %d",ps[i].name,&ps[i].age,&ps[i].money);
	}
	sort(ps.begin(),ps.end());
	int cnt,low,high;
	for(int i=0;i<n2;++i){
		scanf("%d %d %d",&cnt,&low,&high);
		printf("Case #%d:\n",i+1);
		int j=0;
		int c1=cnt;
		while(cnt>0 && j<n1){
			if(ps[j].age >= low && ps[j].age <= high){
				--cnt;
				printf("%s %d %d\n",ps[j].name,ps[j].age,ps[j].money);
			}
			++j;
		}
		if(cnt == c1){
			printf("None\n");
		}
	}
	return 0;
}