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
void print(int ans)
{
	int k;
	if(ans==0) printf("O");
	k=ans/1000;
	while(k--) printf("M");
	ans%=1000;
	k=ans/100;
	if(k<4)while(k--) printf("C");
	else if(k==4) printf("CD");
	else if(k>4&&k<9)
	{
		k-=5;
		printf("D");
		while(k--) printf("C");
	}
	else printf("CM");
	ans%=100;
	k=ans/10;
	if(k<4)while(k--) printf("X");
	else if(k==4) printf("XL");
	else if(k>4&&k<9)
	{
		k-=5;
		printf("L");
		while(k--) printf("X");
	}
	else printf("XC");
	ans%=10;
	k=ans;	
	if(k<4)while(k--) printf("I");
	else if(k==4) printf("IV");
	else if(k>4&&k<9)
	{
		k-=5;
		printf("V");
		while(k--) printf("I");
	}
	else printf("IX");
	printf("\n");
}
int main()
{
	int num,i,j,ans,k,n;
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
				print(ans);
			}
		}
	}
	return 0;
}