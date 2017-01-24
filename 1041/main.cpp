//三个变量：val,cnt,idx
//按照cnt排序，如果cnt相等再按照idx排序
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Num{
	int val;
	int cnt;
	int idx;
};

bool comp(const Num& lhs,const Num& rhs){
	if(lhs.cnt != rhs.cnt){
		return lhs.cnt < rhs.cnt;
	}else{
		return lhs.idx < rhs.idx;
	}
}

int main(){
	int n;
	cin>>n;
	vector<Num> nums;
	unordered_map<int,int> hashtable;
	int loc;
	int val;
	for(int i=0;i<n;++i){
		cin>>val;
		if(hashtable.find(val)==hashtable.end()){
			nums.push_back({val,1,i});
			hashtable.insert({val,nums.size()-1});
		}else{
			loc=hashtable[val];
			++nums[loc].cnt;
		}
	}
	sort(nums.begin(),nums.end(),comp);
	if(nums[0].cnt==1){
		cout<<nums[0].val<<endl;
	}else{
		cout<<"None"<<endl;
	}
	return 0;
}
