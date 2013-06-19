#include<stdio.h>
int a[30][30];
int n,k;
int sort()
{
	int i,j,cnt,flg=1,ct=0;
	int out[27];
	int ans[27]={0};
	ans[0]=1;
	for(i=0;i<n;i++)
	{
		out[i]=a[i][27];
		if(a[i][27]==0&&a[i][28]==0) flg=-1,out[i]=-1;
		if(a[i][27]||a[i][28]) ct++;
	}
	while(ct--)
	{
		cnt=0;
		for(i=0;i<n;i++)
		{
			if(out[i]==0) cnt++,j=i;
		}
		if(cnt==0)
		{
			printf("Inconsistency found after %d relations.\n",k);
			return 0;
		}
		else
		{
			if(cnt>1)	flg=-1;
			ans[ans[0]++]=j;
			out[j]=-1;
			for(i=0;i<n;i++)
			{
				if(a[j][i])
				{
					out[i]--;
				}
			}
		}
	}
	if(ans[0]==n+1&&flg==1)
	{
		printf("Sorted sequence determined after %d relations: ",k);
		for(i=1;i<ans[0];i++) printf("%c",ans[i]+'A');
		printf(".\n");
		return 0;
	}
	return 1;
}
int main()
{
	int i,j,flg,r;
	char s[5];
	while(scanf("%d %d",&n,&r)&&(n+r))
	{
		flg=1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) a[i][j]=0;
			a[i][27]=a[i][28]=0;
		}
		for(k=1;k<=r;k++)
		{
			scanf("%s",s);
			if(flg)
			{
				a[s[0]-'A'][28]++;
				a[s[2]-'A'][27]++;
				a[s[0]-'A'][s[2]-'A']=1;
				flg=sort();
			}
		}
		if(flg) printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}
