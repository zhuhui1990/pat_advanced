#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	vector<string> nums({"zero","one","two","three","four","five","six","seven","eight","nine"});
	string num;
	int sum=0;
	cin>>num;
	if(num.size()==1 && num[0]=='0'){
		cout<<"zero"<<endl;
		return 0;
	}
	int digit;
	while(num.size()>0){
		digit = num.back()-'0';
		num.pop_back();
		sum += digit;
	}
	vector<string> digits;
	while(sum>0){
		digit = sum%10;
		sum /= 10;
		digits.push_back(nums[digit]);
	}

	for(int i=digits.size()-1;i>0;--i){
		cout<<digits[i]<<" ";
	}
	cout<<digits[0]<<endl;
	return 0;
}
