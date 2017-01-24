//̰��
//Sample 1:
//749.17 = 7.10*(150./12.)+7.00*(150./12.)+6.85*(600./12.)+7.00*(300./12.)+7.30*(50./12.)+6.00*(50./12.)
/*
7.10 0
7.00 150
7.20 200
6.85 300
7.50 400
7.00 600
7.30 1000
6.00 1250
*/


#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

struct Station{
	double price;
	double location;
};

inline bool comp(const Station& lhs, const Station& rhs){
	return lhs.location < rhs.location;
}

int main(){
	const double inf=0xffffff;
	double cmax,dist,davg;
	int n;
	cin>>cmax>>dist>>davg>>n;
	vector<Station> sta(n);
	for(int i=0;i<n;++i){
		cin>>sta[i].price>>sta[i].location;
	}
	sort(sta.begin(),sta.end(),comp);
	if(sta[0].location!=0){
		cout<<"The maximum travel distance = 0.00"<<endl;
		return 0;
	}
	double total=0.;
	double c=0.; //��ǰ����
	double cadd; //��ǰ��������
	double dmax=cmax*davg;//���������ܵľ���
	double minprice;
	int minloc;
	int j=0,k=0;
	double d=0;
	//�߼���
	//1.��Ѱ����һ���ȵ�ǰλ�ü۸�͵ļ���վj
	//2.���j�������䷶Χ�ڣ���ֻ��Ҫ�ӹ�����j���ͼ��ɣ���ǰλ�õ���j
	//3.���j���������䷶Χ�ڣ��������䣬��ǰλ�õ����ܵ������Զλ��i
	cout<<setprecision(2)<<fixed;
	while(true){
		if(j==n-1){
			if(sta[j].location+dmax<dist){
				cout<<"The maximum travel distance = "<<sta[j].location+dmax<<endl;
				return 0;
			}
		}
		minprice=sta[j].price;
		minloc=j;
		int i=j;
		for(;i<n;++i){
			if(sta[i].location>sta[j].location+dmax){
				break;
			}
			if(sta[i].price<minprice){
				minprice=sta[j].price;
				minloc=i;
				break;
			}
		}
		//cout<<"j="<<j<<" total="<<total<<" minloc="<<minloc<<" c="<<c<<endl;
		if(i==n){
			if(sta[j].location+dmax >= dist){ //�ܵ��յ�
				total += (dist-sta[j].location)/davg*sta[j].price;
				break;
			}else{
				total += (sta[n-1].location-sta[j].location)/davg*sta[j].price;
				j = n-1;
			}
		}else if(minloc==j){
			--i;
			total+=sta[j].price*(cmax-c);
			c += cmax-c; //��������
			c -= (sta[i].location-sta[j].location)/davg;//����iλ�õ�����
			j=i;
		}else{
			total += ((sta[minloc].location-sta[j].location)/davg-c)*sta[j].price;
			j = minloc;
			//��������û�б仯
		}
	}
	cout<<total<<endl;
	
	return 0;
}