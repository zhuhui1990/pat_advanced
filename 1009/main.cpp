#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main(){
	int k1,k2;
	cin>>k1;
	map<int,double> p1,p2;
	int tempi;
	double tempd;
	for(int i=0;i<k1;++i){
		cin>>tempi>>tempd;
		p1.insert({tempi,tempd});
	}	
	cin>>k2;
	for(int i=0;i<k2;++i){
		cin>>tempi>>tempd;
		p2.insert({tempi,tempd});
	}
	map<int,double> p3;
	for(auto it1=p1.begin();it1!=p1.end();++it1){
		for(auto it2=p2.begin();it2!=p2.end();++it2){
			tempi= it1->first + it2->first;
			tempd= it1->second * it2->second;
			//cout<<"tempi="<<tempi<<" tempd="<<tempd<<endl;
			if(p3.find(tempi) == p3.end()){
				p3.insert({tempi,tempd});
			}else{
				p3[tempi] += tempd;
			}
		}
	}
	for(auto it=p3.begin();it!=p3.end();++it){
		if(it->second > -0.05 && it->second  < 0.05)
			p3.erase(it);
	}
	
	if(p3.size()==0){
		cout<<endl;
		return 0;
	}else{
		cout<<p3.size();
		cout<<" ";
		cout<<setprecision(1)<<fixed;
		for(auto it=--p3.end();it!=p3.begin();--it){
			  cout<<it->first<<" "<<it->second<<" ";
		}
		cout<<p3.begin()->first<<" "<<p3.begin()->second<<endl;
	}
	
	
	return 0;
}