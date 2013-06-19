#include<stdio.h>
#include<string>
using namespace std;
bool flag[30][30];
char s[100000];
bool flg[32];
int main()
{
	int i,j,k,l,ii;
	int t=1;
	while(scanf("%s",s)!=EOF)
	{
		if(s[0]=='#') break;
		for(i=0;i<30;i++)
		{
			for(j=0;j<30;j++) flag[i][j]=0;
		}
		for(i=0;i<strlen(s);i++)
		{
			for(j=0;j<32;j++) flg[j]=0;
			for(j=i;s[j]>='A'&&s[j]<='Z';j++)flg[s[j]-'A']=1;
			if(s[j]=='-') k=0;
			else if(s[j]=='+') k=1;
			else k=-1;
			if(k==-1)
			{
				k=j;
				for(j=0;j<30;j++)
				{
					if(flg[j])
					{
						for(ii=0;ii<30;ii++) flag[j][ii]=0;
					}
				}
				j=k;
				k=1;
			}
			for(j++;s[j]>='a'&&s[j]<='z';j++)
			{
				for(ii=0;ii<30;ii++)
				{
					if(flg[ii])
					{
						if(k) flag[ii][s[j]-'a']=1;
						else flag[ii][s[j]-'a']=0;
					}
				}
			}
			i=j;
		}
		string str1[30];
		char s1[30];
		k=0;
		for(i=0;i<26;i++)
		{
			str1[k]="";
			s1[k]=i+'A';
			for(j=0;j<26;j++)
			{
				if(flag[i][j])
				{
					s[0]='a'+j;
					str1[k]+=s[0];
				}
			}
			if(str1[k]!="") k++;
		}
		printf("%d:",t++);
		if(k==0)
		{
			printf("\n");
			continue;
		}
		printf("%c",s1[0]);
		for(i=1;i<k;i++)
		{
			if(str1[i]==str1[i-1]) printf("%c",s1[i]);
			else
			{
				printf("%s",str1[i-1].c_str());
				printf("%c",s1[i]);
			}
		}
		printf("%s\n",str1[i-1].c_str());
	}
	return 0;
}