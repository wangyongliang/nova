#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void init(int a[27][28])
{
	int i,j;
	for(i=0;i<27;i++)
	{
		for(j=0;j<28;j++)
			a[i][j]=0;
	}
}
void main()
{
	int a[27][28],b[100],i,j,k,c[100],l;
	char s[100],flag[20]="END_OF_FIRST_PART";
	init(a);
	while(1)
	{
		gets(s);
		if(strcmp(s,flag)==0)
			break;
		else
		{
			if(s[1]!=' ')
			{
				
				
				a[s[0]-'A'][s[1]-'a'+1]=atoi(&s[2]);
			}
			else
			{
				i=1;
				while(s[i]==' ')i++;
				a[s[0]-'A'][0]=atoi(&s[1]);
			}
		}
	}
	while(1)
	{
		gets(s);
		if(s[0]=='0')
			break;
		else
		{
			j=l=0;
			for(i=0;i<100;i++)
			{
				b[i]=0;
				c[i]=-1;
			}
			for(i=0;s[i];i++)
			{
				if(s[i]>='A'&&s[i]<='Z')
				{
					if(s[i+1]>='a'&&s[i+1]<='z')
					{
						if(a[s[i]-'A'][s[i+1]-'a'+1]==0)
						{
							printf("UNKNOWN\n");
							goto line;
						}
						b[j++]+=a[s[i]-'A'][s[i+1]-'a'+1];
						i++;
					}
					else
					{
                        if(a[s[i]-'A'][0]==0) 
						{				
							printf("UNKNOWN\n");
							goto line;
						}
						b[j++]+=a[s[i]-'A'][0];
					}
				}
				else if(s[i]=='(')
				{
					c[l++]=j-1;
				}
				else if(s[i]==')')
				{
					j--;
					while(j>c[l-1]+1)
					{
						b[j-1]+=b[j];
						b[j]=0;
						j--;
					}
					j++;
					c[--l]=-1;
				}
				else if(s[i]>='0'&&s[i]<='9')
				{
					k=0;
					while(s[i]>='0'&&s[i]<='9'&&s[i]!='\0')
					{
						k=k*10+s[i]-'0';
						i++;
					}
					b[j-1]*=k;
					i--;
				}
			}
		}
		for(i=1;i<100;i++)
			b[0]+=b[i];
		printf("%d\n",b[0]);
line:;
	}
}
