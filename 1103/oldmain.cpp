//DFS
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n,k,p;
vector<int> power,vec,res;

inline int po(int a,int p){
	int res=1;
	for(int i=0;i<p;++i){
		res *= a;
	}
	return res;
}

bool DFS(int& n1,int& sum1,int& sum){
	//cout<<"n1="<<n1<<endl;
	if(vec.size() > k){
		return false;
	}
	if(n1 > n){
		return false;
	}
	if(vec.size() == k && n1 != n){
		return false;
	}
	if(vec.size()==k){
		//cout<<"n1="<<n1<<" size="<<vec.size()<<endl;
		if(n1 == n){
			if(sum1 >= sum){
				res = vec;
				sum = sum1;
			}
			return true;
		}else{
			return false;
		}
	}else{
		int nn=power.size();
		int ll = vec.size() > 0? vec.back()-1 : 0;
		for(int i=0;i<nn;++i){
			//cout<<"i="<<i<<" nn-i="<<nn-i<<" pow[nn-1-i]="<<power[nn-1-i]<<endl;
			if(n1+power[i] <= n && vec.size() < k){
				n1 += power[i];
				vec.push_back(i+1);
				sum1 += i+1;
				DFS(n1,sum1,sum);
				n1 -= power[i];
				vec.pop_back();
				sum1 -= i+1;
			}else{
				return false;
			}
		}
	}
	return true;
}


int main(){
	scanf("%d %d %d",&n,&k,&p);
	int maxm=1,pow=1;
	while(pow <= n){
		power.push_back(pow);
		++maxm;
		pow = po(maxm,p);
	}
	/*
	for(int i=0;i<power.size();++i){
		cout<<"i="<<i<<" power[i]="<<power[i]<<endl;
	}
	*/
	int n1=0;
	int sum1=0,sum=0;
	bool possible=DFS(n1,sum1,sum);
	if(possible){
		printf("%d = ",n);
		printf("%d^%d",res[0],p);
		for(int i=1;i<res.size();++i){
			printf(" + %d^%d",res[i],p);
		}
		printf("\n");
	}else{
		printf("Impossible\n");
	}
	return 0;
}

