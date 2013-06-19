#include<stdio.h>
#include<string.h>
char s[30];
typedef __int64 int64;
int len;
int64 gcd (int64 n,int64 m)
{
	int64 r=n%m;
	while(r)
	{
		n=m;
		m=r;
		r=n%m;
	}
	return m;
}
void itoa(int64 n)
{
	int a[30];
	int i,j;
	for(i=0;n;i++,n/=10) a[i]=(int)(n%10);
	s[i]='\0';
	for(j=0,i--;i>=0;i--,j++) s[j]=a[i]+'0';
}
int f(int64 n,int64 m)
{
	int64 q;
	int ans;
	q=gcd(n,m);
	n/=q;
	m/=q;
	if(n==1&&m==1) return 1;
	if(n%m)
	{
		q=n/m;
		itoa(q);
		ans=strlen(s)+3;
		ans+=f(m,n%m);
	}
	else
	{
		q=n/m-1;
		itoa(q);
		ans=strlen(s)+3;
		ans+=f(1,1);
	}
	return ans;
}
void print(int x,int y,char ch)
{
	int i;
	for(i=x;i<y;i++) printf("%c",ch);
}
void g(int64 n,int64 m,int k)
{
	int64 mod;
	int64 p;
	int i,j;
	mod=gcd(n,m);
	n/=mod;
	m/=mod;
	if(n==1&&m==1)
	{
		print(0,k,'.');
		printf("1\n");
	//	print(0,k,'.');
	//	printf("-\n");
	//	print(0,k,'.');
	//	printf("1\n");
	}
	else
	{
		if(n%m) p=n/m;
		else p=n/m-1;
		itoa(p);
		i=k+strlen(s)+3;
		j=(len-i-1)/2+i;
		print(0,j,'.');
		printf("1");
		print(j+1,len,'.');
		printf("\n");
		print(0,k,'.');
		printf("%s.+.",s);
		print(i,len,'-');
		printf("\n");
		if(n%m) g(m,n%m,i);
		else g(1,1,i);
	}
}
int main()
{
	int64 p,q,r;
	int t=1,i,j,k;
	while(scanf("%I64d%I64d",&p,&q)&&(p+q))
	{
		printf("Case %d:\n",t++);
		printf("%I64d / %I64d\n",p,q);
		r=gcd(p,q);
		p/=r;
		q/=r;
		if(p==1&&q==1)
		{
			printf("1/n-/n1/n");
		}
		else{
			len=f(p,q);
			g(p,q,0);
		}
	}
	return 0;
}