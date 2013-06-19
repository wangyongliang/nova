#include<stdio.h>
#include<math.h>
#include<string.h>

char s[100],p[100],c[10000],m[10000];
int main()
{
	int x,n,d,i,k,j;
	//freopen("permcode.in","r",stdin);
	while(scanf("%d",&x)&&x)
	{
		scanf("%s%s",s,p);
		scanf("%s",c);
		n=strlen(c);
		d=((int)pow(n,1.5)+x)%n;
		for(i=0;s[i];i++)
		{
			if(s[i]==c[d]) break;
		}
		m[d]=p[i];
		for(i=d-1;i>=0;i--)
		{
			for(k=0;s[k];k++) 
			{
				if(c[i]==s[k]) break;
			}
			for(j=0;s[j];j++) 
			{
				if(m[i+1]==s[j]) break;
			}
			k=k^j;
			m[i]=p[k];
		}
		for(i=n-1;i>d;i--)
		{
			for(k=0;s[k];k++) 
			{
				if(c[i]==s[k]) break;
			}
			for(j=0;s[j];j++) 
			{
				if(m[(i+1)%n]==s[j]) break;
			}
			k=k^j;
			m[i]=p[k];
		}
		m[n]=0;
		//puts(m);
		printf("%s\n",m);
	}
	return 0;
}