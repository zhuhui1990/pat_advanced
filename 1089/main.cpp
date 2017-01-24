#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isSame(vector<int> &v1,vector<int> &v2);	//�Ƚ����������Ƿ���ͬ

int main()
{
	int n;
	cin>>n;
	vector<int> first(n,0),second(n,0),tv1;	//��һ�飬�ڶ����飬��ʱ����
	vector<int>::iterator ivi;
	for(int i=0;i<n;i++)	//����
		cin>>first[i];
	for(int i=0;i<n;i++)
		cin>>second[i];

	tv1=first;
	for(int i=0;i<n;i++)	//�жϲ�������
	{
		sort(tv1.begin(),tv1.begin()+i+1);	//���ϲ��룬�Ա�
		if(isSame(tv1,second))
		{
			for(i++;i<n;i++)	//������Ҫ��һ������ı����
			{
				ivi=tv1.begin()+min(n,i+1);
				sort(tv1.begin(),ivi);
				if(!isSame(tv1,second))	//����ı䣬���
					break;
			}
			cout<<"Insertion Sort\n";
			cout<<tv1[0];
			for(int j=1;j<n;j++)
				cout<<" "<<tv1[j];
			return 0;
		}
	}

	cout<<"Heap Sort\n";	//��ѡһ��ֻ���Ƕ�������
	tv1=second;
	int pos=0,max,last=0;	//����Ҫ������λ�ã���Ҫ����λ�ú������ӽڵ��е������Ϊ���ѵ����һ��Ԫ�ص�λ��
	for(int i=n-1;i>=0;i--)	//���Ҷѵ����һ��Ԫ��
	{
		if(second[i]<second[0])
		{
			last=i;
			break;
		}
	}
	swap(tv1[0],tv1[last]);	//����
	while(pos<last)		//��������
	{
		max=pos;
		if(pos*2+1<last&&tv1[pos*2+1]>tv1[max])
			max=pos*2+1;
		if(pos*2+2<last&&tv1[pos*2+2]>tv1[max])
			max=pos*2+2;
		if(max==pos)
			break;
		swap(tv1[pos],tv1[max]);
		pos=max;
	}
	cout<<tv1[0];	//���
	for(int j=1;j<n;j++)
		cout<<" "<<tv1[j];

	return 0;
}

bool isSame(vector<int> &v1,vector<int> &v2)
{
	for(int i=0;i<v1.size();i++)
		if(v1[i]!=v2[i])
			return false;
	return true;
}