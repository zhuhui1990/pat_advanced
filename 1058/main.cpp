#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int g1,s1,k1;
	int g2,s2,k2;
	scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
	int g3,s3,k3;
	g3=g2+g1;
	s3=s2+s1;
	k3=k2+k1;
	
	if(k3>=29){
		k3 -= 29;
		s3 += 1;
	}
	if(s3>=17){
		s3 -= 17;
		g3 += 1;
	}
	
	cout<<g3<<"."<<s3<<"."<<k3<<endl;
}