#include<stdio.h>
int main()
{
	int m,t,u,f,d;
	int i;
	char s[10];
	int j;
	scanf("%d%d%d%d%d",&m,&t,&u,&f,&d);
//	while(!=EOF)
	{
		for(i=0;i<t;i++)
		{
			scanf("%s",s);
			if(s[0]=='f') j=f*2;
			else j=u+d;
			if(j<=m) m-=j;
			else 
			{
			//	i++;
				break;
			}
		}
		printf("%d\n",i);
	}
	return 0;
}
