#include <iostream>
#include <vector>
#include <unordered_set>
#include <iomanip>

using namespace std;

int main(){
	int n,m,a;
	cin>>n;
	vector<unordered_set<int>> sets(n);
	for(int i=0;i<n;++i){
		cin>>m;
		for(int j=0;j<m;++j){
			cin>>a;
			sets[i].insert(a);
		}
	}
	int nq;
	int s1,s2;
	int nc,nt;
	double res;
	cin>>nq;
	cout<<setprecision(1)<<fixed;
	unordered_set<int> sq;
	for(int i=0;i<nq;++i){
		sq.clear();
		cin>>s1>>s2;
		--s1;
		--s2;
		nc=0;
		for(auto it=sets[s1].begin();it!=sets[s1].end();++it){
			if(sets[s2].find(*it)!=sets[s2].end()){
				++nc;
			}
		}
		
		nt=sets[s1].size()+sets[s2].size()-nc;
		//cout<<"nc="<<nc<<" nt="<<nt<<endl;
		res=double(nc)/nt*100.;
		cout<<res<<"%"<<endl;
	}
	return 0;
}
