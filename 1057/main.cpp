#include <iostream>
//ά��һ��С�ڵ���mid�ģ�һ������mid�������֣�
//����С�ĵĴ�С�ʹ�ĵĴ�Сһ�»��߱ȴ�Ķ�һ��������mid��С�ĵ����һ������
#include <set>
#include <algorithm>
#include <stack>
#include<cstring>
using namespace std;

void adjust(multiset<int>& small,multiset<int>& big,int& mid,const stack<int>& stack1){
	multiset<int>::iterator it;
	if(big.size()+1<small.size()){
		it=small.end();
		--it;
		big.insert(*it);
		small.erase(it);
	}else if(big.size()>small.size()){
		it=big.begin();
		small.insert(*it);
		big.erase(it);
	}
	if(!stack1.empty()){
		it=small.end();
		--it;
		mid=*it;
	}
}


int main(){
	int n;
	scanf("%d",&n);
	multiset<int> small,big;
	stack<int> stack1;
	char s[15];
	int mid,top;
	int a;
	multiset<int>::iterator it;
	for(int i=0;i<n;++i){
		scanf("%s",s);
		if(strcmp(s,"Push")==0){
			scanf("%d",&a);
			if(stack1.empty()){
				small.insert(a);
				mid=a;
			}else if(a<=mid){
				small.insert(a);
			}else{
				big.insert(a);
			}
			stack1.push(a);
			adjust(small,big,mid,stack1);
		}else if(strcmp(s,"Pop")==0){
			if(stack1.empty()){
				printf("Invalid\n");
			}else{
				top=stack1.top();
				stack1.pop();
				printf("%d\n",top);
				if(top<=mid){
					it=small.find(top);
					small.erase(it);
				}else{
					it=big.find(top);
					big.erase(it);
				}
				adjust(small,big,mid,stack1);
			}
		}else if(strcmp(s,"PeekMedian")==0){
			if(stack1.empty()){
				printf("Invalid\n");
			}else{
				printf("%d\n",mid);
			}
		}else{
			printf("Invalid\n");
		}
		
	}
	return 0;
}