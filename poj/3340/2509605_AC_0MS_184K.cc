#include <stdio.h>
#include <string.h>
#define SIZE 15

char a[SIZE],b[SIZE];
int main()
{
	int len,i;
	while(scanf("%s",a) && a[0] != '#')
	{
		int flg = 0,num = 0;
		int da = 0;
		__int64 ans = 0;
		bool first = true;
		bool init = true;
		scanf("%s",b);
		len = strlen(a);
		for(i = 0; i < len; i++)
		{
			if(init && da == 0 && a[i] != '?' && a[i] > b[i])
			{
				da = 1;
				continue;
			}
			if(init && da == 0 && a[i] != '?' && a[i] < b[i])
			{
				da = -1;
				continue;
			}
			if(a[i] == '?')
			{
				num++;
				if(!da)
				{
					ans = ans*10;
					if(flg == 0)
						ans += '9'-b[i];
					else if(flg > 0 && first)
					{
						ans += 10;
						first = false;
					}	
					init = false;
				}
			}
			else
			{
				if(!init && flg == 0 && a[i] > b[i])
					flg = 1;
				if(!init && flg == 0 && a[i] < b[i])
					flg = -1;
			}
		}
		if(da == 1)
		{
			ans = 1;
			for(i = 0; i < num; i++)
				ans *= 10;
			printf("%I64d\n",ans);
		}
		else if(da == -1)
		{
			printf("0\n");
		}
		else
		{
			if(flg > 0 && first)
				ans++;
			printf("%I64d\n",ans);
		}
	}
	return 0;
}

