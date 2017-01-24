#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
	//      1
	//     2 2
	//    3 4 3
	//   4 6 6 4
//    5 8 9 8 5
// 6 10 12 12 10 6
	int n;
	cin>>n;
	vector<double> nums(n);
	vector<double> weight(n);
	for(int i=0;i<n;++i){
		cin>>nums[i];
	}
	weight[0]=n;
	double step=n;
	for(int i=1;i<(n+1)/2;++i){
		step -= 2;
		weight[i]=weight[i-1]+step;
	}
	for(int i=(n+1)/2;i<n;++i){
		weight[i]=weight[n-i-1];
	}
	double sum=0;
	for(int i=0;i<n;++i){
		sum+=nums[i]*weight[i];
	}
	cout<<setprecision(2)<<fixed<<sum<<endl;
	return 0;
}