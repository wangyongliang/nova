#include<stdio.h>
#include<string.h>
#define p 9991
#define pp 1003
#define maxn 1100000
int hash1[maxn];
int hash2[maxn];
char s1[maxn],s2[maxn];
int pow1[11000],pow2[11000];
int main()
{
	int t;
	int len;
	int i,j,jj,ans;
	for(i=1,pow2[0]=pow1[0]=1;i<10100;i++)
	{
		pow1[i]=256*pow1[i-1];
		pow1[i]%=p;
		pow2[i]=255*pow2[i-1];
		pow2[i]%=pp;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",&s1,&s2);
		len=strlen(s1);
		ans=0;
		j=0;
		for(i=0;i<len;i++)
		{
			ans=ans*256+s2[i];
			ans%=p;
			j=j*256+s1[i];
			j%=p;
		}
		hash1[i-1]=ans;
		for(;s2[i];i++)
		{
			hash1[i]=hash1[i-1]*256+s2[i]-pow1[len]*s2[i-len];
			hash1[i]=(hash1[i]%p+p)%p;
		}
		ans=jj=0;
		for(i=0;i<len;i++)
		{
			ans=ans*255+s2[i];
			ans%=pp;
			jj=jj*255+s1[i];
			jj%=pp;
		}
		hash2[i-1]=ans;
		for(;s2[i];i++)
		{
			hash2[i]=hash2[i-1]*255+s2[i]-pow2[len]*s2[i-len];
			hash2[i]=(hash2[i]%pp+pp)%pp;
		}
		ans=0;
		for(i=len-1;s2[i];i++)
		{
			if(hash1[i]==j&&hash2[i]==jj) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
