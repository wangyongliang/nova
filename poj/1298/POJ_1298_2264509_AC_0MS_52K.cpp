#include<stdio.h>
#include<string.h>
char s[]=("VWXYZABCDEFGHIJKLMNOPQRSTU");
int main()
{
	char c[100];
	int i;
	while(1)
	{
		gets(c);
		if(strcmp(c,"START")==0||strcmp(c,"END")==0) continue;
		else  if(strcmp(c,"ENDOFINPUT")==0) break;
		else
		{
			for(i=0;c[i];i++)
			{
				if(c[i]>='A'&&c[i]<='Z')
					printf("%c",s[c[i]-'A']);
				else printf("%c",c[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
