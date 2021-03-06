#include <iostream>
#include <vector>
#include <string>

using namespace std;

string int2string(int j){
	string s;
	if(j>=10){
		s += '1';
		j -= 10;
	}
	char c=j+'0';
	s+=c;
	return s;
}

int main(){
	int n;
	cin>>n;
	vector<string> card(54);
	const string cc="SHCD";
	for(int i=0;i<4;++i){
		for(int j=0;j<13;++j){
			card[i*13+j] = cc[i]+int2string(j+1);
		}
	}
	card[52]="J1";
	card[53]="J2";
	vector<int> shuffle(54);
	vector<int> newshuffle(54);
	vector<int> mid(54);
	for(int i=0;i<54;++i){
		cin>>shuffle[i];
		--shuffle[i];
		mid[i]=i;
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<54;++j){
			newshuffle[shuffle[j]]=mid[j];
		}
		mid=newshuffle;
	}
	cout<<card[mid[0]];
	for(int i=1;i<54;++i){
		cout<<" "<<card[mid[i]];
	}
	cout<<endl;
}