//并查集
//一定要把大数组开在main外面，否则会有内存错误
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 10000

using namespace std;

int pre[N];
bool visit[N];

int find(int x){
	if(pre[x] != x){
		pre[x] = find(pre[x]);
	}
	return pre[x];
}

void join(int x,int y){
	int fx=find(x),fy=find(y);
	//cout<<"x="<<x<<" fx="<<fx<<" y="<<y<<" fy="<<fy<<endl;
	if(fx < fy){
		pre[fy] = fx;
	}else if(fx > fy){
		pre[fx] = fy;
	}
}

struct Family{
	int id;
	int cnt;
	double estate;
	double area;
	bool flag;
}fam[N];

bool cmp1(const Family& lhs, const Family& rhs){
	if(lhs.area != rhs.area){
		return lhs.area > rhs.area;
	}else{
		return lhs.id < rhs.id;
	}
}


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif

	for(int i=0;i<N;++i){
		pre[i]=i;
		visit[i]=false;
	}
	int f,m,k,c;
	vector<int> child;
	int n;
	//cin>>n;
	scanf("%d",&n);
	vector<int> id(n);
	vector<int> estate(n),area(n);

	for(int i=0;i<n;++i){
		//cin>>id[i]>>f>>m>>k;
		scanf("%d %d %d %d",&id[i],&f,&m,&k);
		//cout<<"id="<<id<<" find(id)="<<find(id)<<endl;
		visit[id[i]]=true;
		child.clear();
		if(f != -1){
			visit[f]=true;
			join(id[i],f);
		}	
		if(m != -1){
			//cout<<"id="<<id<<" pre[id]="<<pre[id]<<" "<<pre[pre[id]]<<endl;
			visit[m]=true;
			join(id[i],m);
		}
		for(int j=0;j<k;++j){
			cin>>c;
			child.push_back(c);
			visit[c]=true;
			join(id[i],c);
		}
		//cin>>estate[i]>>area[i];
		scanf("%d %d",&estate[i],&area[i]);
	}
	int res=0;
	for(int i=0;i<n;++i){
		int ix=find(id[i]);
		fam[ix].id=ix;
		fam[ix].estate += estate[i];
		fam[ix].area += area[i];
		fam[ix].flag = true;
	}
	for(int i=0;i<N;++i){
		if(visit[i]){
			++fam[find(i)].cnt;
		}
		if(fam[i].flag){
			++res;
		}
	}	
	for(int i=0;i<N;++i){
		if(fam[i].flag){
			fam[i].estate = double(fam[i].estate) / double(fam[i].cnt);
			fam[i].area   = double(fam[i].area)   / double(fam[i].cnt);
		}
	}
	sort(fam,fam+N,cmp1);
	printf("%d\n",res);
	for(int i=0;i<res;++i){
		printf("%04d %d %.3f %.3f\n",fam[i].id,fam[i].cnt,fam[i].estate,fam[i].area);
	}

	return 0;
}
