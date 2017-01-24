#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isSame(vector<int> &v1,vector<int> &v2);	//比较两个序列是否相同

int main()
{
	int n;
	cin>>n;
	vector<int> first(n,0),second(n,0),tv1;	//第一组，第二个组，临时数据
	vector<int>::iterator ivi;
	for(int i=0;i<n;i++)	//输入
		cin>>first[i];
	for(int i=0;i<n;i++)
		cin>>second[i];

	tv1=first;
	for(int i=0;i<n;i++)	//判断插入排序
	{
		sort(tv1.begin(),tv1.begin()+i+1);	//不断插入，对比
		if(isSame(tv1,second))
		{
			for(i++;i<n;i++)	//！！！要找一个结果改变的项
			{
				ivi=tv1.begin()+min(n,i+1);
				sort(tv1.begin(),ivi);
				if(!isSame(tv1,second))	//结果改变，输出
					break;
			}
			cout<<"Insertion Sort\n";
			cout<<tv1[0];
			for(int j=1;j<n;j++)
				cout<<" "<<tv1[j];
			return 0;
		}
	}

	cout<<"Heap Sort\n";	//二选一，只能是堆排序了
	tv1=second;
	int pos=0,max,last=0;	//堆需要修正的位置，需要修正位置和两个子节点中的最大置为，堆的最后一个元素的位置
	for(int i=n-1;i>=0;i--)	//查找堆的最后一个元素
	{
		if(second[i]<second[0])
		{
			last=i;
			break;
		}
	}
	swap(tv1[0],tv1[last]);	//交换
	while(pos<last)		//修正最大堆
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
	cout<<tv1[0];	//输出
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