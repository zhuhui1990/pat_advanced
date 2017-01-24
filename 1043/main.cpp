#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int N;
int A[1005];
vector<int> res;//���������
int value;//��ʱ����������lambda�����ڲ�
function<int (int)> func = [=](int i){return i>=value;}; //lambda����ָ��
void tree(int* a, int* b){
	if(a>=b)
		return; //�ݹ����
	value = *a;
	int* center = find_if(a+1,b,func);  //����ֳ�3���֣��ֱ��ǣ���Ԫ�� ������ ������ 
	if(!all_of(center,b,func)) //�����������Ƿ���������
		return;
	tree(a+1,center);    //����������
	tree(center,b);      //����������
	res.push_back(*a);   //�洢���
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",A+i);
	}
	if(N>1 && A[0]<=A[1])
		func = ([=](int i){return i<value;});//�����mirror,�ı�lambda����
	tree(A,A+N);
	if(res.size()!=N)
		printf("NO\n");
	else{//���
		printf("YES\n");
		printf("%d",res[0]);
		for(int i=1;i<res.size();i++)
			printf(" %d",res[i]);
	}
	return 0;
}