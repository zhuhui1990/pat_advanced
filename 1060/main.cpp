#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	string a,b;
	cin>>n>>a>>b;

	
	//ָ���ļ��������
	//1.û��С���㣬ȥ�����п�ͷ��0���ɣ�ָ��=����
	//2.��С���㣬ȥ�����п�ͷ��0
	//	2.1 ��ʱ��һλ����С���㣬С�����λ��=ָ��
	//  2.2 ��ʱ��һλ��С���㣬Ѱ��С������һ�������λ��
	int adot=a.find('.');
	int bdot=b.find('.');
	
	int anz=a.find_first_not_of("0");
	int bnz=b.find_first_not_of("0");
	
	if(anz!=a.npos)
		a.erase(a.begin(),a.begin()+anz);
	if(bnz!=b.npos)
		b.erase(b.begin(),b.begin()+bnz);
				
	int apow,bpow;	
	int anz1,bnz1;
	if(a=="0"){
		apow=0;
	}else{
		if(adot==a.npos){
			apow=a.size();
		}else{
			if(a[0]!='.'){
				apow=a.find('.');			
			}else{
				anz1=a.find_first_not_of("0",1);
				if(anz1!=a.npos){
					apow=1-anz1;
				}else{
					apow=0;
				}
			}
		}
	}
	if(b=="0"){
		bpow=0;
	}else{
		if(bdot==b.npos){
			bpow=b.size();
		}else{
			if(b[0]!='.'){
				bpow=b.find('.');			
			}else{
				bnz1=b.find_first_not_of("0",1);
				if(bnz1!=b.npos){
					bpow=1-bnz1;
				}else{
					bpow=0;
				}
			}
		}
	}
	
	//ϵ������
	//��ȥ��С�������
	int adot1=a.find('.');
	int bdot1=b.find('.');
	
	if(adot1 != a.npos){
		a.erase(adot1,1);
	}
	if(bdot1 != b.npos){
		b.erase(bdot1,1);
	}
	int anz2=a.find_first_not_of("0");
	int bnz2=b.find_first_not_of("0");
	
	if(anz2!=a.npos)
		a.erase(a.begin(),a.begin()+anz2);
	if(bnz2!=b.npos)
		b.erase(b.begin(),b.begin()+bnz2);
	
	int n1 = a.size()<n? a.size():n;
	int n2 = b.size()<n? b.size():n;
		 
	string aa(a.begin(),a.begin()+n1);
	string bb(b.begin(),b.begin()+n2);
	
	while(aa.size()<n){
		aa+="0";
	}
	while(bb.size()<n){
		bb+="0";
	}
	if(aa==bb && apow==bpow){
		cout<<"YES 0."<<aa<<"*10^"<<apow<<endl;	
	}else{
		cout<<"NO 0."<<aa<<"*10^"<<apow<<" 0."<<bb<<"*10^"<<bpow<<endl;
	}
}