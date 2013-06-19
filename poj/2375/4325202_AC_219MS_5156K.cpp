#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
#define maxn 510
int id[maxn][maxn];
int flag[maxn*maxn],in[maxn*maxn],out[maxn*maxn];
int find(int x)
{
	if(flag[x]==x) return x;
	else flag[x]=find(flag[x]);
	return flag[x];
}
/*
struct node
{
	int x,y;
};
struct cmp
{
	bool operator()(const node &x,const node &y)
	{
		return a[x.x][x.y]<a[y.x][y.y];
	}
};
priority_queue<node,vector<node>,cmp> heap;
*/
int a[maxn][maxn];
int main()
{
	int i,j,n,m,k;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		k=0;
	in[0]=out[0]=flag[0]=0;
	
	//	while(heap.size()) heap.pop();
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				id[i][j]=k++;
				flag[k]=k;
				in[k]=out[k]=0;
				scanf("%d",&a[i][j]);
			//	node tp;
			//	tp.x=i;
			//	tp.y=j;
			//	heap.push(tp);
			}
		}
		//while(heap.)
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				int xx,yy;
				for(k=0;k<4;k++)
				{
					xx=i+dx[k];
					yy=j+dy[k];
					if(xx>=0&&xx<n&&yy>=0&&yy<m)
					{		
						int x=find(id[i][j]);
						int y=find(id[xx][yy]);
						if(a[xx][yy]==a[i][j])	flag[y]=x;
						else if(a[xx][yy]<a[i][j])
						{
							out[x]++;
							in[y]++;
						}
					}
				}
			}
		}
		int cnt1=0,cnt2=0,cnt=0;
		for(i=0;i<n*m;i++)
		{
			if(flag[i]==i){
				cnt++;
			if(in[i]==0) cnt1++;
			if(out[i]==0) cnt2++;
			}
		}
		if(cnt>1){
		if(cnt1<cnt2) cnt1=cnt2;
		printf("%d\n",cnt1);}
		else printf("0\n");
	}
	return 0;

}