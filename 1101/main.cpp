#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	if(n==0)
		return 0;
	vector<int> nums(n);
	for(int i=0;i<n;++i){
		cin>>nums[i];
	}
	vector<int> max(n),min(n);
	max[0]=nums[0];
	for(int i=1;i<n;++i){
		max[i] = nums[i]>max[i-1]? nums[i]:max[i-1];
	}
	min[n-1]=nums[n-1];
	for(int i=n-2;i>=0;--i){
		min[i] = nums[i]<min[i+1]? nums[i]:min[i+1];
	}

	vector<int> res;
	for(int i=0;i<n;++i){
		if(nums[i]==max[i] && nums[i] == min[i]){
			res.push_back(nums[i]);
		}
	}
	
	sort(res.begin(),res.end());
	
	cout<<res.size()<<endl;
	if(res.size()==0){
		cout<<endl;
		return 0;
	}
	if(res.size()==1){
		cout<<res[0]<<endl;
		return 0;
	}
	for(int i=0;i<res.size()-1;++i){
		cout<<res[i]<<" ";
	}
	cout<<res[res.size()-1]<<endl;
	return 0;
}