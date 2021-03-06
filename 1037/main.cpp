#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	int n1,n2;
	scanf("%d",&n1);
	vector<long long> pcoupon,ncoupon;
	long long temp;
	for(int i=0;i<n1;++i){
		scanf("%lld",&temp);
		if(temp>=0){
			pcoupon.push_back(temp);
		}else{
			ncoupon.push_back(temp);
		}
	}
	cin>>n2;
	vector<long long> pprice,nprice;
	for(int i=0;i<n2;++i){
		scanf("%lld",&temp);
		if(temp>=0){
			pprice.push_back(temp);
		}else{
			nprice.push_back(temp);
		}
	}
	long long total=0;
	sort(pcoupon.begin(),pcoupon.end());
	sort(ncoupon.begin(),ncoupon.end());
	sort(pprice.begin(),pprice.end());
	sort(nprice.begin(),nprice.end());
	
	reverse(pcoupon.begin(),pcoupon.end());
	reverse(pprice.begin(),pprice.end());
	
	for(int i=0;i<pcoupon.size() && i<pprice.size();++i){
		//cout<<"total="<<total<<endl;
		total+=pcoupon[i]*pprice[i];
	}
	for(int i=0;i<ncoupon.size() && i<nprice.size();++i){
		//cout<<"total="<<total<<endl;
		total+=ncoupon[i]*nprice[i];
	}
	printf("%lld\n",total);
}