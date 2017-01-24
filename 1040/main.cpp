//DP
//flag[i][j]表示从i开始，到j结束的字符串是否是回文串
//显然flag[i][i]==true
//如果flag[i][j]==true,且str[i-1]==str[j+1]，则flag[i-1][j+1]==true
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string s;
	getline(cin,s);
	vector<vector<bool>> flag(s.length(),vector<bool>(s.length(),false));
	int max=1;
	for(int i=0;i<s.length();++i){
		flag[i][i]=true;
		if(i<s.length()-1){
			if(s[i]==s[i+1]){
				flag[i][i+1]=true;
				max=2;
			}
		}
	}
	int j;
	for(int k=0;k<s.length();++k){
		for(int i=1;i<s.length()-k-1;++i){
			j=i+k;
			if(flag[i][j] && s[i-1]==s[j+1]){
				flag[i-1][j+1]=true;
				max=k+3;
			}
		}
	}
	/*
	for(int i=0;i<s.length();++i){
		for(int j=0;j<s.length();++j){
			cout<<flag[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	cout<<max<<endl;
}	