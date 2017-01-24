#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long long icount = 0;
	long long n = 0;
	long long ifactor = 1;
	long long curr = 0;
	long long lower = 0;
	long long higher = 0;

	cin >> n;
	while (n / ifactor != 0){
		lower = n - (n / ifactor)*ifactor;
		curr = (n / ifactor) % 10;
		higher = n / (ifactor * 10);
		switch (curr){
		case 0:{
			icount += higher * ifactor;
			break;
		}
		case 1:{
			icount += higher * ifactor + lower + 1;
			break;
		}
		default:{
			icount += (higher + 1)*ifactor;
			break;
		}
		}
		ifactor *= 10;
	}
	cout << icount << endl;
	return 0;
}