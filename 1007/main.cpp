//DP
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> nums(n);

	for(int i=0;i<n;++i){
		cin>>nums[i];
	}

	int sum=0,temp=0,tempi=0,tempj=0;
	int start=0,end=n-1;


	for(int i=0;i<n;++i){
		if(temp>=0){
			temp += nums[i];
			tempj = i;
		}else{
			temp  = nums[i];
			tempi = i;
			tempj = i;
		}
		if(temp > sum || (temp==0 && end==n-1)){
			sum   = temp;
			start = tempi;
			end   = tempj;
		}
		
	}


	cout<<sum<<" "<<nums[start]<<" "<<nums[end]<<endl; //mdzz
	return 0;
}