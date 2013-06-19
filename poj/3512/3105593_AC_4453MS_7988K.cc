#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
//#include<time.h>
#define inf 1e-6
using namespace std;
#define maxn 1010000
struct node
{
	double k,b;
}a[maxn];
int cnt[maxn],kk;
int d[2000][2];
bool cmp(const node &x,const node &y)
{
	if(fabs(x.k-y.k)<inf)
	{
		return x.b<y.b;
	}
	return x.k<y.k;
}
char s[200];
int main()
{
	int i,j,k,n;
	int ans,max,t=1,flg;
	int len;
	double dx,dy;
	//int st,en,sum=0;
	//freopen("segment.in","r",stdin);
	while(scanf("%s",s))
	{

		len=strlen(s);
		if(s[len-1]=='-') break;
		else
		{
			d[0][0]=0;
			if(s[0]=='-') flg=-1,i=1;
			else flg=1,i=0;
			for(;s[i];i++) d[0][0]=d[0][0]*10+s[i]-'0';
			d[0][0]*=flg;
			scanf("%d",&d[0][1]);
			n=1;
			while(scanf("%s",s))
			{
				len=strlen(s);
				if(s[len-1]=='-') break;
			//	sscanf(s,"%lf",&d[n][0]);
				d[n][0]=0;
				if(s[0]=='-') flg=-1,i=1;
				else flg=1,i=0;
				for(;s[i];i++) d[n][0]=d[n][0]*10+s[i]-'0';
				d[n][0]*=flg;
				scanf("%d",&d[n][1]);
				n++;
			}
		//	st=clock();
			if(n==1)
			{
				printf("%d. 1\n",t++);
				continue;
			}
			k=0;
			kk=0;
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if(d[i][0]==d[j][0]) cnt[kk++]=d[i][0];
					else
					{
						dy=d[i][1]-d[j][1];
						dx=d[i][0]-d[j][0];
						a[k].k=dy/dx;
						a[k].b=-a[k].k*d[i][0]+d[i][1];
						k++;
					}
				}
			}
			ans=0;
			max=1;
			sort(a,a+k,cmp);
//			en=clock();
//			sum=en-st>sum?en-st:sum;
			j=0;
			for(i=1;i<k;i++)
			{
				if(fabs(a[i].k-a[j].k)<inf&&(a[i].b-a[j].b)<inf) max++;
				else
				{
					if(ans<max) ans=max;
					max=1;
					j=i;
				}
			}
			if(ans<max) ans=max;
			if(kk){
				sort(cnt,cnt+kk);
			max=1;
			j=0;
			for(i=1;i<kk;i++)
			{
				if(cnt[i]==cnt[j]) max++;
				else
				{
					if(ans<max) ans=max;
					max=1;
					j=i;
				}
			}
			if(ans<max) ans=max;
			}
			for(i=1,j=0;j<ans;i++) j+=i;
			printf("%d. %d\n",t++,i);
		//	en=clock();
		//	sum=en-st>sum?en-st:sum;
		}
	}
//	printf("time is %d\n",sum);
	return 0;
}
