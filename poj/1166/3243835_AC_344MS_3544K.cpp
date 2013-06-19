/*
ID: 05272021
PROG: clocks
LANG: C++
*/
#include<stdio.h>
#include<set>
using namespace std;
typedef long long int64;
bool flag[300000];
struct node
{
	int a;
	int b,c;
}q[300000];
int ans[10000];
bool flg[9][9]={
1,1,0,1,1,0,0,0,0,
1,1,1,0,0,0,0,0,0,
0,1,1,0,1,1,0,0,0,
1,0,0,1,0,0,1,0,0,
0,1,0,1,1,1,0,1,0,
0,0,1,0,0,1,0,0,1,
0,0,0,1,1,0,1,1,0,
0,0,0,0,0,0,1,1,1,
0,0,0,0,1,1,0,1,1};
int64 f(int k,int n)
{
	int temp[9];
	int i;
	for(i=8;i>=0;i--)
	{
		temp[i]=k%4;
		k/=4;
	}
	for(i=0;i<9;i++)
	{
		if(flg[n-1][i])
		{
			temp[i]=(temp[i]+1)%4;
		}
	}
	k=0;
	for(i=0;i<9;i++)
	{
		k=k*4+temp[i];
	}
	return k;
}
int main()
{
	int i,j;
	int k;
//	freopen("clocks.in","r",stdin);
//	freopen("clocks.out","w",stdout);
	k=0;
	for(i=0;i<300000;i++) flag[i]=0;
	for(i=0,k=0;i<9;i++)
	{
		scanf("%d",&j);
		if(j==0) j=12;
		else if(j==1) j=3;
		else if(j==2) j=6;
		else j=9;
		k=k*4+(j/3)%4;
	}
	q[0].a=k;
	flag[k]=1;
	q[0].b=0;
	q[0].c=-1;
	int st=0,en=1;
	while(st<en)
	{
		if(q[st].a==0) break;
		else
		{
			for(i=1;i<=9;i++)
			{
				k=f(q[st].a,i);
				if(flag[k]==0)
				{
					q[en].a=k;
					q[en].b=i;
					q[en].c=st;
					flag[k]=1;
					en++;
				}
			}
		}
		st++;
	}
	i=0;
	while(q[st].c!=-1)
	{
		ans[i++]=q[st].b;
		st=q[st].c;
	}
	printf("%d",ans[i-1]);
	for(j=i-2;j>=0;j--) printf(" %d",ans[j]);
	printf("\n");
//	while(1);
	return 0;
}
