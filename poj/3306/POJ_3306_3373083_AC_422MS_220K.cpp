#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct RECORD
{
	int id;
	int month,days,year;
	int hour,minute,second,ms;
	int dh,dm,ds,dms;
	char state;
}RECORD;

class Comp
{
public:
	bool operator () (const RECORD &a, const RECORD &b)
	{
		if (a.year != b.year)	return a.year > b.year;
		if (a.month != b.month)	return a.month > b.month;
		if (a.days != b.days)	return a.days > b.days;
		if (a.hour != b.hour)	return a.hour > b.hour;
		if (a.minute!=b.minute) return a.minute>b.minute;
		if (a.second!=b.second) return a.second>b.second;
		if (a.ms != b.ms )return a.ms > b.ms;
		if (a.state != b.state) return a.state > b.state;
		return a.id > b.id;
	}
};

int n,B;
priority_queue<RECORD, vector<RECORD>, Comp> Q;

void Read()
{
	int i;
	RECORD T;
	scanf("%d%d",&n,&B);
	while (!Q.empty()) Q.pop();
	for (i=0; i<n; i++)
	{
		scanf("%d %d/%d/%d ",&T.id,&T.days,&T.month,&T.year);
		scanf("%d:%d:%d.%d ",&T.hour,&T.minute,&T.second,&T.ms);
		scanf("%d:%d:%d.%d",&T.dh,&T.dm,&T.ds,&T.dms);
		T.state = 'R';
		Q.push(T);
	}
}

bool Leap(int x)
{
	x %= 33;
	return (x==1 || x==5 || x==9 || x==13 || x==17 || x==22 || x==30);
}

void AddTime(RECORD &T, int hour,int minute,int second, int ms)
{
	int x = 0;
	T.ms += ms;
	x = T.ms / 1000;
	T.ms %= 1000;
	T.second += second + x;
	x = T.second / 60;
	T.second %= 60;
	T.minute += minute + x;
	x = T.minute / 60;
	T.minute %= 60;
	T.hour += hour + x;
	x = T.hour / 24;
	T.hour %= 24;
	while (x--)
	{
		T.days++;
		if (T.days <= 29) continue;
		if (T.month <= 6)
		{
			if (T.days<=31) continue;
			T.month++;
			T.days=1;
		}
		else if (T.month <= 11)
		{
			if (T.days<=30) continue;
			T.month++;
			T.days=1;
		}
		else
		{
			if (Leap(T.year))
			{
				if (T.days==31)
				{
					T.year++;
					T.days=1;
					T.month=1;
				}
			}
			else
			{
				if (T.days == 30)
				{
					T.year++;
					T.days=1;
					T.month=1;
				}
			}
		}
	}
}

void Work(int cas)
{
	RECORD T;
	printf("Report for Test-Case #%d:\n",cas);
	while (!Q.empty())
	{
		T = Q.top();
		Q.pop();
		printf("%d %02d/%02d/%04d %02d:%02d:%02d.%03d ",T.id,T.days,T.month,T.year,T.hour,T.minute,T.second,T.ms);
		if (T.state == 'A')
		{
			B++;
			puts("LANDED");	
		}
		else if (T.state == 'R')
		{
			if (B>0)
			{
				B--;
				AddTime(T,T.dh,T.dm,T.ds,T.dms);
				T.state = 'A';
				Q.push(T);
				puts("ACCEPTED");
			}
			else
			{
				AddTime(T,0,10,0,0);
				Q.push(T);
				puts("POSTPONED");
			}
		}
	}
	printf("\n");
}

int main()
{
	int cas;
	scanf("%d",&cas);
	for (int i=1; i<=cas; i++)
	{
		Read();
		Work(i);
	}
	return 0;
}