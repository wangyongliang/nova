#include<stdio.h>
int cnt[]={0,0,0,1,1,1,1,6,10,11,17,88,162,197,437,1350};

int main()
{
	int a[100];
	int i,j,n,m,flag,k;
	__int64 ans,temp;
	int ct;
	while(scanf("%d",&n)!=EOF)
	{
	//	cnt=0;
		ct=20;
		for(i=m=1;i<n;i++) m*=3;
		for(i=0;i<m&&ct;i++)
		{
			k=i;
			for(j=n-2;j>=0;j--,k/=3) a[j]=k%3;
			temp=1;
			for(j=0;j<n-1;j++)
			{
				if(a[j]==2) 
				{
					if((j+2)<10)	temp=temp*10+j+2;
					else temp=temp*100+j+2;
				}
				else break;
			}
			ans=temp;
			temp=j+2;
			flag=a[j];
			for(j++;j<n-1;j++)
			{
				if(a[j]==2) 
				{
					if((j+2)<10)	temp=temp*10+j+2;
					else temp=temp*100+j+2;
				}
				else
				{
					if(flag==0) ans+=temp;
					else ans-=temp;
					temp=j+2;
					flag=a[j];
				}
			}
			if(flag==0) ans+=temp;
			else ans-=temp;
		//	printf("%I64d\n",ans);
			if(ans==0)
			{
			//	cnt++;
				if(ct){
				printf("1");
				for(j=0;j<n-1;j++) {
					if(a[j]==0) printf(" + ");

					else if(a[j]==1) printf(" - ");
					else printf(" . ");
					printf("%d",j+2);
				}
				printf("\n");
				ct--;
				} 
			}

		}
		printf("%d\n",cnt[n]);
	}
	return 0;
}