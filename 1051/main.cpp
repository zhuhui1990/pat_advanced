#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int m,n,k;
	cin>>m>>n>>k;
	vector<int> vec(n);
	int max;
	bool flag;
	for(int i=0;i<k;++i){
		flag=true;
		stack<int> stk;
		for(int j=0;j<n;++j){
			cin>>vec[j];
		}
		max = 0;
		
		for(int j=0;j<n;++j){
			/*
			cout<<"j="<<j<<" vec[j]="<<vec[j];
			if(!stk.empty()){
				cout<<" top="<<stk.top();
			}
			cout<<endl;
			*/
			if(stk.empty() || vec[j]>max){
				for(int l=max+1;l<=vec[j];++l){
					stk.push(l);
				}
				max = vec[j];
			}else if(vec[j] != stk.top()){
				cout<<"NO"<<endl;
				flag = false;
				break;
			}
			if(stk.size()>m){
				cout<<"NO"<<endl;
				flag = false;
				break;
			}
			if(!stk.empty()){
				stk.pop();
			}
		}
		if(flag){
			cout<<"YES"<<endl;
		}
	}
	return 0;
}