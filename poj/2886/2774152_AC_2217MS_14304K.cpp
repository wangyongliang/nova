
//http://acm.pku.edu.cn/JudgeOnline/problem?id=2309

#include<stdio.h>
#define size 500100
char s[size][20];
int a[size];
int flag[size];
bool flg[size];
int n;
int prime[]={2,4,6,12,24,36,48,60,120,180,
240,360,720,840,1260,1680,2520,5040,7560,
10080,15120,20160,25200,27720,45360,50400,
55440,83160,110880,166320,221760,277200,332640,498960,510000};
int prime1[]={2,3,4,6,8,9,10,12,16,18,20,
24,30,32,36,40,48,60,64,72,80,84,90,96,
100,108,120,128,144,160,168,180,192,200,0};
int lowbit(int n)
{
	return n&(-n);
}
int sum(int i)
{
	int cnt=0;
	while(i>0)
	{
		cnt+=flag[i];
		i-=lowbit(i);
	}
	return cnt;
}
void update(int i,int k)
{
	while(i<n) 
	{
		flag[i]+=k;
		i+=lowbit(i);
	}
}
int f(int j)
{
	int min,max,mid;
	int k;
	min=1;
	max=n;
	while(min<max)
	{
		mid=(min+max)/2;
		k=sum(mid);
		if(k<j) min=mid+1;
		else if(k==j)
		{
			if(flg[mid]) return mid;
			else max=mid-1;
		}
		else max=mid;
	}
	return min;
}
int main()
{
	int i,j,p;
	int m;
	int sum;
	int ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		sum=n-1;
		for(i=1;i<=n;i++) 
		{
			scanf("%s %d",s[i],&a[i]);
			flag[i]=0;
			flg[i]=1;
		}
		for(i=1;i<=n;i++) update(i,1);
		for(i=0;prime[i+1]<=n;i++);
		p=prime[i];
		ans=prime1[i];
		update(m,-1);
		flg[m]=0;
		i=m-1;
		while(--p)
		{
			j=a[m];
			if(j>0) j=((i+j)%sum+sum)%sum;
			else j=((i+j)%sum+sum)%sum+1;
			if(j==0) j=sum;
			m=f(j);
			update(m,-1);
			flg[m]=0;
			i=j-1;
			sum--;
		}
		printf("%s %d\n",s[m],ans);
	}
	return 0;
}
