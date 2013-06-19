#include<stdio.h>
#include<string.h>
int flag[300];
void init()
{
	flag['O']=0;
	flag['I']=1;
	flag['V']=5;
	flag['X']=10;
	flag['L']=50;
	flag['C']=100;
	flag['D']=500;
	flag['M']=1000;
}
char s[100000];
int a[20],flg[20];
char s1[]={"MCXI"};
char s2[]={"MDLV"};
int b[]={1000,100,10,1};
void print(int ans,char str[])
{
	int k,i=0,j;
	if(ans==0) str[i++]='0';
	else
	{
		k=ans/b[0];
		while(k--) str[i++]='M';
		ans%=b[0];
		for(j=1;s1[j];j++)
		{
			k=ans/b[j];
			if(k<4) while(k--) str[i++]=s1[j];
			else if(k==4) str[i++]=s1[j],str[i++]=s2[j];
			else if(k>4&&k<9) 
			{
				str[i++]=s2[j];
				k-=5;
				while(k--) str[i++]=s1[j];
			}
			else str[i++]=s1[j],str[i++]=s1[j-1];
			ans%=b[j];
		}
	}
	str[i]=0;

	puts(str);
}
int main()
{
	int num,i,j,ans,k,n;
	char str[100];
	init();
	for(i=0;i<11;i++) a[i]=-1;
//	while(scanf("%d",&n))
//		print(n);
	while(gets(s))
	{
		if(strcmp(s,"RESET")==0) 
		{
			for(i=0;i<11;i++) a[i]=-1;
			printf("Ready\n");
		}
		else if(strcmp(s,"QUIT")==0) 
		{
			printf("Bye\n");
			return 0;
		}
		else
		{
			for(i=0;s[i]==' ';i++);
			for(num=0;s[i]>='0'&&s[i]<='9';i++) num=num*10+s[i]-'0';
			for(;s[i]==' ';i++);
			for(i++;s[i]==' ';i++);
			k=1;
			ans=0;
			while(s[i])
			{
				if(s[i]>='0'&&s[i]<='9')
				{
					n=0;
					for(;s[i]>='0'&&s[i]<='9';i++)n=n*10+s[i]-'0';
					if(a[n]==-1) 
					{
						ans=-1;
						break;
					}
					ans+=k*a[n];
				}
				else if(s[i]>='A'&&s[i]<='Z')
				{
					n=0;
					for(;s[i]>='A'&&s[i]<='Z';i++)
					{
						if(s[i+1]>='A'&&s[i+1]<='Z'&&flag[s[i+1]]>flag[s[i]])
						{
							n+=flag[s[i+1]]-flag[s[i]];
							i++;
						}
						else n+=flag[s[i]];

					}
					ans+=k*n;
				}		
				else if(s[i]=='+') k=1,i++;
				else if(s[i]=='-') k=-1,i++;
				for(;s[i]==' ';i++);
			}
			if(ans<0||ans>10000) printf("Error\n");
			else
			{
				a[num]=ans;
				printf("%d=",num);
				print(ans,str);
			}
		}
	}
	return 0;
}

