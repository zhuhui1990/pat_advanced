#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int time=0;
	int loc,preloc;
	preloc=0;
	for(int i=0;i<n;++i){
		cin>>loc;
		if(loc>preloc){
			time += 5+(loc-preloc)*6;
		}else if(loc<preloc){
			time += 5+(preloc-loc)*4;
		}else{
			time += 5;
		}
		preloc=loc;
	}
	cout<<time<<endl;
}