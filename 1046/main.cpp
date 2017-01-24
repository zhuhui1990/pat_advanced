#include <iostream>
#include <vector>

using namespace std;

//  1 2  4  14  9
// 0 1  3  7  21 
// 0 29 27 23  9    
// 0 1  3  7   9


int main(){
	int n;
	cin>>n;
	vector<int> dl(n),dr(n);
	int sum=0;
	int a;
	for(int i=0;i<n;++i){
		dl[i]=sum;
		cin>>a;
		sum+=a;
	}
	for(int i=0;i<n;++i){
		dr[i]=sum-dl[i];
	}
	int m;
	cin>>m;
	int c1,c2;
	int cl,cr;
	int l,r;
	for(int i=0;i<m;++i){
		cin>>c1>>c2;
		cl=c1<c2?c1-1:c2-1;
		cr=c1<c2?c2-1:c1-1;
		l=dl[cr]-dl[cl];
		r=dl[cl]+dr[cr];
		//cout<<"l="<< l<<" r="<<r<<endl;
		if(l<r){
			cout<<l<<endl;
		}else{
			cout<<r<<endl;
		}
		
	}
	return 0;
}