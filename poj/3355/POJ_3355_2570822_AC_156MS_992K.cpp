#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 1e-7
struct node
{
	double x;
	double y;
	char s[50];
}a[10009];
int n,tail;
int q[10009];
char s[1000000];
char temp[20];
double dis(int i,int j)
{
	return (a[i].x-a[j].x)*(a[i].x-a[j].x) + (a[i].y-a[j].y)*(a[i].y-a[j].y );
}
double Mu(int i,int j,int k)
{
	double dx,dy,dx1,dy1;
	dx=a[j].x-a[k].x;
	dy=a[j].y-a[k].y;
	dx1=a[i].x-a[j].x;
	dy1=a[i].y-a[j].y;
	return dx*dy1-dy*dx1;
}
bool cmp(const node &x,const node &y)
{
	double dx,dy,dx1,dy1,ans;
	dx=x.x-a[0].x;
	dy=x.y-a[0].y;
	dx1=y.x-a[0].x;
	dy1=y.y-a[0].y;
	ans=dx*dy1-dy*dx1;
	if(fabs(ans)<inf)
	{
		return (x.x-a[0].x)*(x.x-a[0].x)+(x.y-a[0].y)*(x.y-a[0].y)>(y.x-a[0].x)*(y.x-a[0].x)+(y.y-a[0].y)*(y.y-a[0].y);
	}
	return ans>0;
}
void f()
{
	int i;
	a[n].x=a[0].x;
	a[n].y=a[0].y;
	strcpy(a[n].s,a[0].s);
	q[0]=0;
	q[1]=1;
	tail=1;
	for(i=2;i<=n;i++)
	{
		while(Mu(i,q[tail],q[tail-1])<-inf) tail--;
		if(Mu(i,q[tail],q[tail-1])<inf)
		{
			if(dis(i,q[tail-1])>dis(q[tail],q[tail-1])) q[tail] =i;
		}
		else q[++tail] =i;
	}
}
int main()
{
	int i,k,l,j;
	int min;
	double x,y;
	while(gets(s))
	{
		j=0;
		min=0;
		for(i=0,k=0;s[i];i++)
		{
			while(s[i]!='(') i++;
			i++;
			l=0;
			a[j].s[k++]='(';
			while(s[i]!=',')
			{
				temp[l++]=s[i];
				a[j].s[k++]=s[i];
				i++;
			}
			a[j].s[k++]=',';
			i++;
			temp[l]='\0';
			a[j].x=atof(temp);
			l=0;
			while(s[i]!=')')
			{
				temp[l++]=s[i];
				a[j].s[k++]=s[i];
				i++;
			}
			a[j].s[k++]=')';
			temp[l]='\0';
			a[j].y=atof(temp);
			a[j].s[k]='\0';
			k=0;
			if(a[j].y<a[min].y||(fabs(a[min].y -a[j].y )<inf&&a[j].x<a[min].x)) min=j;
			j++;
		}
		if(min!=0)
		{
			x=a[min].x;
			a[min].x=a[0].x;
			a[0].x=x;
			y=a[min].y;
			a[min].y=a[0].y;
			a[0].y=y;
			strcpy(temp,a[min].s);
			strcpy(a[min].s,a[0].s);
			strcpy(a[0].s,temp);
		}
		sort(a+1,a+j,cmp);
		n=j;
		f();
		printf("%s",a[q[0]].s);
		for(i=1;i<=tail;i++)
		{
			printf(" %s",a[q[i]].s);
		}
		printf("\n");
	}
	return 0;
}
