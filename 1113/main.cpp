#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<long long> nums(n);
	for(int i=0;i<n;++i){
		cin>>nums[i];
	}
	sort(nums.begin(),nums.end());
	long long sum=0;
	for(int i=0;i<n/2;++i){
		sum += nums[n-1-i]-nums[i];
	}
	if(n%2==1){
		sum += nums[n/2];
	}
	cout<<n%2<<" "<<sum<<endl;
	return 0;
}