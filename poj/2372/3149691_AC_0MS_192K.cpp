#include <stdio.h>
#include <string.h>
#define SIZE 1000100

char exp[SIZE];
int tail;
bool isok()
{
	tail = 0;
	int i = 0;
	int flag=0;
	bool ex = 0;
	int len = strlen(exp);
	while(i < len)
	{
		if(exp[i] == '(')
		{
			if(i+1 < len && exp[i+1] == '*')
			{
				i = i+2;
				while(i+1 < len && !(exp[i] == '*' && exp[i+1] == ')')) i++;
				if(i+1 == len)
					return false;
				i += 2;
			}
			else
			{
				flag=1;
				tail++;
				ex = 1;
				i++;
			}
		}
		else if(exp[i] == ')')
		{
			if(!ex || tail == 0)
				return false;
			tail--;
			if(tail == 0)
				ex = 0;
			i++;
		}
		else if(ex)
		{
			if(!(exp[i]=='='|| exp[i] == '\r' || exp[i] == '\n' || exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||(exp[i] >= '0' && exp[i] <= '9')))
				return false;
			i++;
		}
		else
			i++;
	}
//	if(!flag) return false;
	if(tail)
		return false;
	return true;
}
int main()
{
	//char str[100];
	//char ch[]="padsd\rx";
	//sscanf(ch,"%s",str);
//	printf("%s\n",ch);
//	printf("\r");
	//printf("y");
	char *in = exp;
	//freopen("in.txt","r",stdin);
	while((*in = getchar()) != EOF)
		in++;
	if(isok())
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

