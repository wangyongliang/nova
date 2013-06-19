#include<stdio.h>
int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char s[20][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int main()
{
	int n,i,j;
	int year,month,date;
	int week;
	while(scanf("%d",&n)&&n!=-1)
	{
		year=2000;
		week=(n+6)%7;
		month=1;
		date=1;
		j=366;
		while(n>=j)
		{
			n-=j;
			year++;
			if((year%100!=0&&year%4==0)||(year%400==0))
			{
				j=366;
			}
			else j=365;
		}
		i=1;
		j=a[i];
		while(n>=j)
		{
			n-=j;
			i++;
			if(i==2)
			{ 
				if((year%100!=0&&year%4==0)||(year%400==0)) j=29;
				else j=28;
			}
			else j=a[i];
		}
		month=i;
		date=1;
		date+=n;
		printf("%d-",year);
		if(month<10) printf("0%d-",month);
		else printf("%d-",month);
		if(date<10) printf("0%d ",date);
		else printf("%d ",date);
		printf("%s\n",s[week]);
	}
	return 0;
}