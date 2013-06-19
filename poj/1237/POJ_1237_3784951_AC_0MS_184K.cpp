#include<stdio.h>
#include<string.h>
int a[30][30];
int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
int main()
{
	char s[110];
	int len,i,j,k;
	int ans;
	int cnt[30];
	while(scanf("%s",s)!=EOF)
	{
		for(i=0;i<30;i++)
		{
			cnt[i]=0;
			for(j=0;j<30;j++) a[i][j]=0x7fffffff;
		}
		ans=len=strlen(s);
		i=s[0]-'a';
		j=s[len-1]-'a';
		a[i][j]=min(a[i][j],len);
		a[j][i]=min(a[j][i],len);
					cnt[i]++;
			cnt[j]++;
		while(scanf("%s",s))
		{
			if(strcmp(s,"deadend")==0) break;
			len=strlen(s);
			i=s[0]-'a';
			j=s[len-1]-'a';
			a[i][j]=min(a[i][j],len);
			a[j][i]=min(a[j][i],len);
			ans+=len;
						cnt[i]++;
			cnt[j]++;
		}
		int k1,k2,n=26;
		for(k1=0;cnt[k1]%2==0&&k1<n;k1++);
		if(k1<n){
			for(k2=k1+1;cnt[k2]%2==0&&k2<n;k2++);
			for(i=0;i<26;i++)
			{
				for(j=0;j<26;j++)
				{
					if(a[j][i]==0x7fffffff) continue;
					for(k=0;k<26;k++)
					{
						if(a[i][k]==0x7fffffff) continue;
						if(a[j][i]+a[i][k]<a[j][k]) a[j][k]=a[j][i]+a[i][k];
					}
				}
			}
			ans+=a[k1][k2];
		}
		printf("%d\n",ans);
	}
	return 0;
}