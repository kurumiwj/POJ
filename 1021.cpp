#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 102
#define INFINITY -1
using namespace std;

vector<vector<int>> contiguous(2);
vector<vector<int>> hashTable(2);	//�жϸ�����ͨ����״�Ƿ���ͬ
int g[MAXN][MAXN]={INFINITY};
bool visited[MAXN][MAXN]={false};
int w,h,cnt=0,hashSquare=0,starta,startb;
void DFS(int a,int b,int k){
	if(g[a][b]==INFINITY) return;	//�����߽�
	if(g[a][b]==0){	//�õ�������
		visited[a][b]=true;	//�øõ��ѷ��ʹ�
		return;
	}
	if(!visited[a][b]){	//δ���ʹ��õ��Ҹõ�һ��������
		visited[a][b]=true;	//�øõ��ѷ��ʹ�
		cnt++;
		hashSquare+=(a-starta)*(a-starta)+(b-startb)*(b-startb);
		DFS(a+1,b,k);	//���ҷ���
		DFS(a,b+1,k);	//���·���
	}
}
int main(){
	int t,n;
	scanf("%d",&t);
	for(int m=0;m<t;m++){
		scanf("%d%d%d",&w,&h,&n);
		for(int k=0;k<2;k++){
			for(int i=0;i<MAXN;i++){	//��ʼ��
				fill(g[i],g[i]+MAXN,INFINITY);
				fill(visited[i],visited[i]+MAXN,false);
			}
			contiguous[k].clear();
			hashTable[k].clear();
			for(int i=0;i<h;i++)	//��Ч��������Ϊ0
				fill(g[i],g[i]+w,0);
			for(int j=0;j<n;j++){	//ÿ��������¼��
				int xw,yh;
				scanf("%d%d",&xw,&yh);
				g[yh][xw]=1;
			}
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++){
					cnt=0,hashSquare=0;
					if(!visited[i][j]&&g[i][j]!=0){
						starta=i,startb=j;
						DFS(i,j,k);
						contiguous[k].push_back(cnt);	//����ͨ���еĵ����ӽ�������
						hashTable[k].push_back(hashSquare);	//����ÿ��ͼ������ֵ
					}
				}
			sort(contiguous[k].begin(),contiguous[k].end());
			sort(hashTable[k].begin(),hashTable[k].end());
//			printf("��ͨ�������%d\n",contiguous[k].size());
		}
		if(contiguous[0]==contiguous[1]&&hashTable[0]==hashTable[1])
			printf("YES\n");
		else
			printf("NO\n");
	}
	system("pause");
	return 0;
}
