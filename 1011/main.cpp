#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
	vector<double> odds(3);
	double a=1.;
	for(int i=0;i<3;++i){
		cin>>odds[0]>>odds[1]>>odds[2];
		if(odds[0]>odds[1] && odds[0]>odds[2]){
			cout<<"W"<<" ";
			a*=odds[0];
		}else if(odds[1]>odds[0] && odds[1]>odds[2]){
			cout<<"T"<<" ";
			a*=odds[1];
		}else if(odds[2]>odds[0] && odds[2]>odds[1]){
			cout<<"L"<<" ";
			a*=odds[2];
		}
	}
	cout<<setprecision(2)<<fixed;
	cout<<(a*0.65-1.)*2.<<endl;
	return 0;
}
