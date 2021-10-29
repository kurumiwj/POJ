#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 102
#define INFINITY -1
using namespace std;

int g[MAXN][MAXN]={INFINITY},hashTable[2][MAXN]={0};
int w,h,cnt=0;
int main(){
	int t,n;
	scanf("%d",&t);
	for(int m=0;m<t;m++){
		scanf("%d%d%d",&w,&h,&n);
		for(int k=0;k<2;k++){
			fill(hashTable[k],hashTable[k]+n,0);
			for(int i=0;i<MAXN;i++)	//初始化
				fill(g[i],g[i]+MAXN,INFINITY);
			for(int i=0;i<h;i++)	//有效区域设置为0
				fill(g[i],g[i]+w,0);
			for(int j=0;j<n;j++){	//每个点坐标录入
				int xw,yh;
				scanf("%d%d",&xw,&yh);
				g[yh][xw]=1;
				hashTable[k][j]=yh*yh+(h-yh)*(h-yh)+xw*xw+(w-xw)*(w-xw);
			}
			sort(hashTable[k],hashTable[k]+n);
			for(int i=0;i<n;i++){
				printf("%d ",hashTable[k][i]);
			}
			printf("\n");
		}
		bool flag=true;
		for(int i=0;i<n;i++)
			if(hashTable[0][i]!=hashTable[1][i]){
				flag=false;
				break;
			}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	system("pause");
	return 0;
}
