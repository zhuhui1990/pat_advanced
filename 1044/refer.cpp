#include <stdio.h>
#include <vector>
using namespace std;

const int MAX = 100001;
int arr[MAX],des[MAX];

int findBestSum(int i,int n,int m){
	int left = i+1;
	int right = n;
	int mid;
	while(left < right){			//���ö��ַ�����
		mid = (left + right)/2;
		if(arr[mid]-arr[i] >= m){	//arr[x]-arr[i] ��ʾ[i+1,...,x]�����ݺ�
			right = mid;
		}else{
			left = mid+1;
		}
	}
	des[i] = right;				//��¼���ұ߽�
	return arr[right]-arr[i];
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);

	int i,j;
	arr[0]=0;
	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		arr[i]=arr[i]+arr[i-1];
	}
	vector<int> vec;
	int res,mm;
	mm = 0x7fffffff;

	for(i=0;i<n;i++){
		res = findBestSum(i,n,m);			//Ѱ�Ҵ�i+1��ʼ����ӽ�m�ĺ�
		if(res >= m){
			if(res == mm){					//�͵�ǰ��Сֵ��ȣ������vector
				vec.push_back(i);
			}else if(res < mm){				//�ȵ�ǰ��Сֵ��С�������vector�����¼�����ֵ
				mm = res;
				vec.clear();
				vec.push_back(i);
			}
		}else{								//����϶���С���ޱ�Ҫ����
			break;
		}
	}

	for(i=0;i<vec.size();i++){
		printf("%d-%d\n",vec[i]+1,des[vec[i]]);
	}

	//system("pause");
	return 0;
}