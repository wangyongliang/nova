#include<stdio.h>
int b[1010][1010]={0};
int f1[1010]={0},f2[1010]={0};
int main()
{
	int i,j,k,n,d,t;
	int ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&d,&n);
		for(i=0;i<n;i++) 
		{
			scanf("%d%d",&j,&k);
			j=(j%d+d)%d;
			k=(k%d+d)%d;
			f1[j]++;
			f2[k]++;
			b[j][k]++;
		}
		ans=2000000;
		for(i=0;i<d;i++)
		{
			for(j=0;j<d;j++)
			{
				k=f1[i]+f2[j]-b[i][j];
				if(ans>k) ans=k;
				b[i][j]=0;
				if(i==d-1) f2[j]=0;
			}
			f1[i]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}

