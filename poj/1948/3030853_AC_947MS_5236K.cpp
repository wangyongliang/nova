
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
//pku 3293

#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define maxn 1600+10
bool flag[2][maxn][maxn];
int a[3];
int main()
{
	int n,i,j,x;
	int flg;
	int cnt;
	int sum;
	double p,s,max;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		for(i=0;i<maxn;i++)
		{
			for(j=0;j<maxn;j++) flag[1][i][j]=flag[0][i][j]=0;
		}
		flag[0][0][0]=1;
		flg=0;
		while(n--)
		{
			scanf("%d",&x);
			sum+=x;
			for(i=0;i<sum;i++)
			{
				for(j=0;j<sum;j++)
				{
					if(flag[flg][i][j])
					{
						a[0]=i+x;
						a[1]=j;
						a[2]=sum-a[0]-a[1];
						sort(a,a+3);
						flag[1-flg][a[0]][a[1]]=1;
						a[0]=i;
						a[1]=j+x;
						a[2]=sum-a[0]-a[1];
						sort(a,a+3);
						flag[1-flg][a[0]][a[1]]=1;
						a[0]=i;
						a[1]=j;
						a[2]=sum-a[0]-a[1];
						sort(a,a+3);
						flag[1-flg][a[0]][a[1]]=1;
					}
				}
			}
			cnt=0;
		/*	for(i=0;i<sum;i++)
			{
				for(j=0;j<sum;j++) 
				{
					cnt+=flag[flg][i][j];
					flag[flg][i][j]=0;
				}
			}
			printf("n=%d cnt=%d\n",n,cnt); */
			flg=1-flg;
		}
		max=-1.0;
		for(i=0;i<sum;i++)
		{
			for(j=0;j<sum;j++)
			{
				if(flag[flg][i][j]&&i&&j&&(i+j<sum)&&(2*(i+j)>sum)&&(sum>2*j)&&(sum>2*i))
				{
					p=sum/2.0;
					s=sqrt(p*(p-i)*(p-j)*(p-sum+i+j));
					max=max<s?s:max;
				}
			}
		}
		max*=100;
		if(max<0) printf("-1\n");
		else 	printf("%d\n",(int)max);
	}
	return 0;
}

