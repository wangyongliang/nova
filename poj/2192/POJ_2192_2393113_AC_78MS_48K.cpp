#include<stdio.h>
#include<string.h>
int main()
{
	bool a[210][210]={0};
	char s1[210],s2[210],s3[420];
	int n,i,j,k,len1,len2;
	scanf("%d",&n);
	k=1;
	while(k<=n)
	{
		scanf("%s%s%s",s1,s2,s3);
		len1=strlen(s1);
		len2=strlen(s2);
		if(s1[0]==s3[0])
		{
			for(i=0;i<len2;i++) a[1][i]=1;
		}
		if(s2[0]==s3[0])
		{
			for(i=0;i<len1;i++) a[i][1]=1;
		}
		for(i=0;i<=len1;i++)
		{
			for(j=0;j<=len2;j++)
			{
				if(a[i][j])
				{
					if(s1[i]==s3[i+j]) a[i+1][j]=1;
					if(s2[j]==s3[i+j])  a[i][j+1]=1;
					if(!(i==len1&&j==len2)) a[i][j]=0;
				}
			}
		}
		printf("Data set %d: %s",k,a[i-1][j-1]?"yes\n":"no\n");
		a[i-1][j-1]=0;
		k++;
	}
	return 0;
}
