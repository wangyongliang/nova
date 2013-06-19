#include <stdio.h>
#include <string.h>

char s[1001];
int len,st,ed,ei,pi;
/*
LEGAL
ILLEGAL*/

int chk(char c)
{
	return ((c>='0'&&c<='9') || c=='+' || c=='-');
}

int isinteger(int i, int j)
{
	int k;
	if (j-i+1 == 1)
	{
		if (s[i] =='+' || s[i] == '-')
			return 0;
		return 1;
	}

	if (s[i] == '+' || s[i] == '-') i++;
	for (k=i; k<=j; k++)
	{
		if (!(s[k]>='0' && s[k]<='9')) return 0;
	}
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	while (t--)
	{
		gets(s);
		len = strlen(s);
		st = 0;
		ed = len-1;
		while (s[st] && s[st]==' ') st++;
		while (s[ed] && s[ed]==' ') ed--;

		int i,en = 0, pn = 0, bn = 0, flag = 1;
		for (i=st; i<=ed; i++)
		{
			if (s[i] == 'e' || s[i] == 'E') en++,ei = i;
			else if (s[i] == '.') pn++,pi = i;
			else if (s[i] == ' ') bn++;
			else if (s[i]!= '+' && s[i]!='-' && (s[i] <'0' || s[i]>'9'))
			{
				flag = 0;
				break;
			}
		}
		if (pn>1 || bn>1 || en > 1 || !chk(s[st]) || !chk(s[ed]))
			flag = 0;
		if (!flag)
		{
			puts("ILLEGAL");
			continue;
		}
		if (pn==1)
		{
			if (! isinteger(st,pi-1))
			{
				puts("ILLEGAL");
				continue;
			}
			if (en==1)
			{
				if (pi + 1 == ei)
				{
					puts("ILLEGAL");
					continue;
				}
				if (s[pi+1] == '+' || s[pi+1] == '-')
				{
					puts("ILLEGAL");
					continue;
					if (!isinteger(pi+2,ei-1))
					{
						puts("ILLEGAL");
						continue;
					}
				}
				else if (!isinteger(pi+1,ei-1))
				{
					puts("ILLEGAL");
					continue;
				}
				if (!isinteger(ei+1,ed))
				{
					puts("ILLEGAL");
					continue;
				}
				else
				{
					puts("LEGAL");
					continue;
				}
			}
			else
			{
				if (s[pi+1] == '+' || s[pi+1] == '-')
				{
					puts("ILLEGAL");
					continue;
				}
				if (!isinteger(pi+1,ed))
				{
					puts("ILLEGAL");
					continue;
				}
				else
				{
					puts("LEGAL");
					continue;
				}
			}
		}
		else
		{
			if (en==1)
			{
				if (!isinteger(st,ei-1))
				{
					puts("ILLEGAL");
					continue;
				}
				if (!isinteger(ei+1,ed))
				{
					puts("ILLEGAL");
					continue;
				}
				else
				{
					puts("LEGAL");
					continue;
				}
			}
			else
			{
				if (!isinteger(st,ed))
				{
					puts("ILLEGAL");
					continue;
				}
				else
				{
					puts("LEGAL");
					continue;
				}
			}
		}
	}
	return 0;
}
