#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int N;
int A[1005];
vector<int> res;//存放输出结果
int value;//临时变量，用于lambda函数内部
function<int (int)> func = [=](int i){return i>=value;}; //lambda函数指针
void tree(int* a, int* b){
	if(a>=b)
		return; //递归出口
	value = *a;
	int* center = find_if(a+1,b,func);  //数组分成3部分，分别是：根元素 左子树 右子树 
	if(!all_of(center,b,func)) //测试右子树是否满足条件
		return;
	tree(a+1,center);    //遍历左子树
	tree(center,b);      //遍历右子树
	res.push_back(*a);   //存储输出
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",A+i);
	}
	if(N>1 && A[0]<=A[1])
		func = ([=](int i){return i<value;});//如果是mirror,改变lambda函数
	tree(A,A+N);
	if(res.size()!=N)
		printf("NO\n");
	else{//输出
		printf("YES\n");
		printf("%d",res[0]);
		for(int i=1;i<res.size();i++)
			printf(" %d",res[i]);
	}
	return 0;
}