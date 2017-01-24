#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	long n,p;
	cin>>n>>p;
	if(n==0){
		cout<<"0"<<endl;
		return 0;
	}
	vector<long> nums(n);
	for(int i=0;i<n;++i){
		cin>>nums[i];
	}
	sort(nums.begin(),nums.end());
	
	int max=0;
	for(int i=0;i<n-max;++i){
		int j=i+max;
		for(;j<n;++j){
			if(nums[j]>nums[i]*p)
				break;
		}
		max=j-i>max?j-i:max;
	}
	
	cout<<max<<endl;
	return 0;

}