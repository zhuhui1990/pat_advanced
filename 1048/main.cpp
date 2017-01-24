#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	if (n <= 1){
		printf("No Solution\n");
		return 0;
	}
	vector<int> nums(505,0);
	int a;
	for (int i = 0; i < n; ++i){
		scanf("%d", &a);
		++nums[a];
	}

	int maxi = k % 2 == 0 ? k / 2 : k / 2 + 1;
	for (int i = 1; i < maxi; ++i){
		if (i<=500 && k-i<=500 && nums[i] > 0 && nums[k - i]>0 ){
			printf("%d %d", i, k - i);
			return 0;
		}
	}
	if (k % 2 == 0 && nums[k / 2] > 1){
		printf("%d %d", k / 2, k / 2);
		return 0;
	}
	printf("No Solution\n");
	return 0;
}