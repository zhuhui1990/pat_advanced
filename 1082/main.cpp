#include <iostream>
#include <cstring>
#include <cstdio>

int arr[9];
int l=0;
int flag=0;
char suffix[9][5]={"Yi","Qian","Bai","Shi","Wan","Qian","Bai","Shi",""};
char num[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

void output(int i,int x){
	if(x){
		if(l++){
			printf(" ");
		}
		if(flag){
			printf("ling ");
		}
		flag=0;
		if(i < 8){
			printf("%s %s",num[x],suffix[i]);
		}else{
			printf("%s",num[x]);
		}
		
	}else{
		if(i==4){
			printf(" Wan");
			flag=0;
			return;
		}
		if(i==8){
			return;
		}
		flag=1;
	}
}

int main(){
	int x,i,j;
	scanf("%d",&x);
	if(x<0){
		printf("Fu ");
		x=-x;
	}
	if(x==0){
		printf("ling\n");
		return 0;
	}
	for(i=8;i>=0;--i){
		arr[i]=x%10;
		x/=10;
	}
	for(i=0;i<9;++i){ //È¥µôÎ²ÊýÁã
		if(arr[i]!=0){
			break;
		}
	}
	for(;i<9;++i){
		output(i,arr[i]);
	}
	printf("\n");
	return 0;
}