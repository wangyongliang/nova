#include<stdio.h>
int a[30];
int main()
{
	int i,j,ans,n,k,m;
	char s[1000];
	int flag[28],wait[28],hash[28];
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++) a[i]=-1;
		for(i=0;i<28;i++) wait[i]=flag[i]=hash[i]=-1;
		scanf("%s",s);
		ans=0;
		m=n;
		for(i=0;s[i];i++)
		{
			if(hash[s[i]-'A']==-1)
			{
				hash[s[i]-'A']=i;
				if(m)
				{
					for(j=0;j<n&&a[j]!=-1;j++) ;
					a[j]=1;
					flag[s[i]-'A']=j;
					wait[s[i]-'A']=-1;
					m--;
				}
				else wait[s[i]-'A']=1;
			}
			else
			{
				if(wait[s[i]-'A']==1) 
				{
					wait[s[i]-'A']=-1;
					ans++;
				}
				else 
				{
					a[flag[s[i]-'A']]=-1;
					m++;
					for(j=hash[s[i]-'A']+1;j<i&&wait[s[j]-'A']==-1;j++);
					if(wait[j]==1&&j<i)
					{
						for(k=0;k<n&&a[k]!=-1;k++);
						a[k]=1;
						wait[s[j]-'A']=-1;
						flag[s[j]-'A']=k;
	
					} 	
					flag[s[i]-'A']=-1;
					wait[s[i]-'A']=-1;
				}
			}
		}
		if(ans==0) printf("All customers tanned successfully.\n");
		else printf("%d customer(s) walked away.\n",ans);
	}
	return 0;
}