#include<stdio.h>
int main()
{
	int n,m,i,j,k;
	int cnt1,cnt2;
	int flg;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(m==0) 
		{
			printf("%d does not divide %d!\n",0,n);
			continue;
		}
		flg=1;
		k=m;
		if(m<=n) printf("%d divides %d!\n",m,n);
		else
		{
			for(i=2;i*i<=m;i++)
			{
				if(m%i==0)
				{
					cnt1=0;
					while(m%i==0)
					{
						cnt1++;
						m/=i;
					}
					cnt2=0;
					j=n;
					while(j)
					{
						cnt2+=j/i;
						j/=i;
					}
					if(cnt2<cnt1) flg=0;
				}
			}
			if(m!=1)
			{
				j=n;
				cnt2=0;
				while(j)
				{
					cnt2+=j/m;
					j/=m;
				}
				if(cnt2<1) flg=0;
			}
			if(flg) printf("%d divides %d!\n",k,n);
			else printf("%d does not divide %d!\n",k,n);
		}
	}
	return 0;
}