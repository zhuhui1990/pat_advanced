//floodfill
#include <iostream>
#include <cstdio>
#include <queue>
#define MAXM 1300
#define MAXN 130
#define MAXL 100

using namespace std;

int data[MAXM][MAXN][MAXL];
bool visited[MAXM][MAXN][MAXL];
int m,n,l,t;

//DFS会栈溢出
void DFS(int r,int c,int h,int& vol){
	if(r<0 || r>=m || c<0 || c>=n || h<0 || h>=l){
		return;
	}
	if(data[r][c][h]==0 || visited[r][c][h] ){
		return;
	}
	visited[r][c][h]=true;
	++vol; 
	//cout<<"r="<<r<<" c="<<c<<" h="<<h<<" vol="<<vol<<endl;
	DFS(r-1,c,h,vol);
	DFS(r+1,c,h,vol);
	DFS(r,c-1,h,vol);
	DFS(r,c+1,h,vol);
	DFS(r,c,h-1,vol);
	DFS(r,c,h+1,vol);
}




int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif

	scanf("%d %d %d %d",&m,&n,&l,&t);
	if(m*n*l == 0){
		printf("0");
		return 0;
	}
	for(int k=0;k<l;++k){
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&data[i][j][k]);
				//if(data[i][j][k]==1){
				//	cout<<"i="<<i<<" j="<<j<<" k="<<k<<endl;
				//}
				visited[i][j][k]=false;
			}
		}
	}
	int vol,res=0;
	queue<int> q;
	//DFS会栈溢出，改成BFS
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			for(int k=0;k<l;++k){
				if(data[i][j][k]==1 && !visited[i][j][k] ){
					q.push(k*m*n+j*m+i);
					visited[i][j][k]=true;
					vol = 0;
					while(!q.empty()){
						int top=q.front();
						q.pop();
						++vol;
						int h=top/(m*n);
						int c=top%(m*n)/m;
						int r=top%(m*n)%m;
						if(r>=1 &&  data[r-1][c][h]==1 && !visited[r-1][c][h]){
							q.push(h*m*n+c*m+(r-1));
							visited[r-1][c][h]=true;
						}
						if(r<m-1 &&  data[r+1][c][h]==1 && !visited[r+1][c][h]){
							q.push(h*m*n+c*m+(r+1));
							visited[r+1][c][h]=true;
						}
						if(c>=1 &&  data[r][c-1][h]==1 && !visited[r][c-1][h]){
							q.push(h*m*n+(c-1)*m+r);
							visited[r][c-1][h]=true;
						}
						if(c<n-1 &&  data[r][c+1][h]==1 && !visited[r][c+1][h]){
							q.push(h*m*n+(c+1)*m+r);
							visited[r][c+1][h]=true;
						}
						if(h>=1 &&  data[r][c][h-1]==1 && !visited[r][c][h-1]){
							q.push((h-1)*m*n+c*m+r);
							visited[r][c][h-1]=true;
						}
						if(h<l-1 &&  data[r][c][h+1]==1 && !visited[r][c][h+1]){
							q.push((h+1)*m*n+c*m+r);
							visited[r][c][h+1]=true;
						}
					}
					if(vol>=t){
						res+=vol;
					}
				}
			}
		}
	}
	
	
	
	printf("%d",res);
	
	
	return 0;
}