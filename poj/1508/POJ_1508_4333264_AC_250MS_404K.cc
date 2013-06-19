#include<iostream>
#include<algorithm>
using namespace std;
typedef long long lld;
void gcd(lld a , lld b , lld & d , lld & x , lld & y) //a*x+by=d=gcd(a,b);
{
	if (!b){ d = a; x = 1; y = 0; }
	else 
	{
		gcd(b , a%b , d , y , x ); // (**)
		y -= x*(a/b);
	}
}
lld china(int n,lld a[],lld b[],lld &m) // x=a[i](mod b[i]);
{
	lld w,x=0;
	m=1;
	lld d,xx,yy;
	int i;
	for(i=0;i<n;i++) m*=b[i];
	for(i=0;i<n;i++)
	{
		w=m/b[i];
		gcd(w,b[i],d,xx,yy);
		lld tp=xx*w%m;
		tp=tp*a[i]%m;
		x=(x+tp)%m;
	}
	x=(x%m+m)%m;
	return x;
}
lld GCD(lld x,lld y)
{
	lld r=x%y;
	while(r)
	{
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}
lld solve(lld a1,lld b1,lld a2,lld b2,lld &m)
{
	m=1;
	lld a[100],b[100],d,r;
	lld tp1,tp2,r1,r2;
	int n=0;
	while(1)
	{
		d=GCD(b1,b2);
		if(d==1)
		{
			a[n]=a1;
			a[n+1]=a2;
			b[n]=b1;
			b[n+1]=b2;
			n+=2;
			return china(n,a,b,m);
		}
		else
		{
			while(1)
			{
				tp1=b1;
				tp2=b2;
				while(tp1%d==0) tp1/=d;
				while(tp2%d==0) tp2/=d;
				r1=GCD(tp1,d);
				r2=GCD(tp2,d);
				if(r1==r2&&r1==1)  break;
				if(r1>r2) d=r1;
				else d=r2;
			}
			tp1=tp2=1;
			while(b1%d==0)
			{
				b1/=d;
				tp1*=d;
			}			
			while(b2%d==0)
			{
				b2/=d;
				tp2*=d;
			}
			if(tp1>tp2) swap(tp1,tp2);
			if(a1%tp1!=a2%tp1) return -1;
			a[n]=a1%tp1;
			b[n++]=tp1;
		}
	}
}
int q[1000];
int st,en;
lld max(lld x,lld y)
{
	if(x>y) return x;
	else return y;
}
int main()
{

	int t,i,j,n;
	lld a[200],b[200],c[200],m;
	lld f;
	scanf("%d",&t);
	int flag[220];
	lld A,B;
	while(t--)
	{
		scanf("%I64d%d%I64d%I64d",&f,&n,&A,&B);
		st=0;
		en=0;
		for(i=0;i<n;i++)
		{
			scanf("%I64d%I64d",&b[i],&c[i]);
			a[i]=c[i]%b[i];
			if(A>=c[i]&&(A%b[i]==a[i])) 
			{
				flag[i]=1;
				q[en++]=i;
			}
			else flag[i]=0;
		}
		while(st<en)
		{
			for(i=0;i<n;i++)
			{
				if(flag[i]==0)
				{
					lld tp=solve(a[q[st]],b[q[st]],a[i],b[i],m);
					if(tp==-1) continue;
					
					lld tpp=max(c[q[st]],c[i]);
					if(tpp>tp){
					tpp=(tpp-tp)/m+((tpp-tp)%m!=0);
					tp+=tpp*m;}
					if(tp<=f) 
					{
						flag[i]=1;
						q[en++]=i;
					}
				}
			}
			st++;
		}
		for(i=0;i<n;i++)
		{
			if(flag[i])
			{
				if(B>=c[i]&&B%b[i]==a[i]) break;
			}
		}
		if(i==n&&A!=B) printf("The furniture cannot be moved.\n");
		else printf("It is possible to move the furniture.\n");
	}
	return 0;
}