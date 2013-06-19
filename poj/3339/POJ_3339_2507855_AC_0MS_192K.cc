#include <stdio.h>
#include <algorithm>
using namespace std;
#define SIZE 25


struct Team
{
	int id,year,role;
	char name[SIZE];
}teamer[SIZE];




bool cmp(const Team &a, const Team &b)
{
	return (a.role < b.role || (a.role == b.role && a.id < b.id));
}



int code(char c)
{
	if(c == 'G')
		return 1;
	if(c == 'D')
		return 2;
	if(c == 'M')
		return 3;
	if(c == 'S')
		return 4;
}



char decode(int a)
{
	if(a == 1)
		return 'G';
	if(a == 2)
		return 'D';
	if(a == 3)
		return 'M';
	if(a == 4)
		return 'S';
}
int num[5],out[14];
int main()
{
	int n = 22,id,a,b,i;
	char c,role[2];
	while(scanf("%d",&id) && id)
	{
		teamer[0].id = id;
		scanf("%s%s",teamer[0].name,role);
		teamer[0].role = code(role[0]);
		c = getchar();
		teamer[0].year = 0;
		while(c == ' ')
		{
			scanf("%d-%d",&a,&b);
			teamer[0].year += b-a+1;
			c = getchar();
		}
		for(i = 1; i < n; i++)
		{
			scanf("%d%s%s",&teamer[i].id,teamer[i].name,role);
			teamer[i].role = code(role[0]);
			c = getchar();
			teamer[i].year = 0;
			while(c == ' ')
			{
				scanf("%d-%d",&a,&b);
				teamer[i].year += b-a+1;
				c = getchar();
			}
		}
		num[1] = 1;
		scanf("%d-%d-%d",&num[2],&num[3],&num[4]);
		sort(teamer,teamer+n,cmp);
		int e = 0;
		a = -1;
		for(i = 0; i < n; i++)
		{
			if(num[teamer[i].role])
			{
				num[teamer[i].role]--;
				out[e] = i;
				if(teamer[i].year > a || teamer[i].year == a && teamer[i].id > teamer[b].id)
				{
					a = teamer[i].year;
					b = i;
				}
				e++;
			}
		}
		for(i = 1; i <= 4; i++)
			if(num[i])
				break;
			if(i <= 4){
				printf("IMPOSSIBLE TO ARRANGE\n\n");
				continue;
			}
		int t;
		printf("%d %s %c\n",teamer[b].id,teamer[b].name,decode(teamer[b].role));



		for(i = 0; i < e; i++)
		{
			t = out[i];
			if(t != b)
				printf("%d %s %c\n",teamer[t].id,teamer[t].name,decode(teamer[t].role));
		}


		printf("\n");
	}
	return 0;
}
