#include<stdio.h>
#include<algorithm>
using namespace std;

int N;
int num[100000];
char a[100];
int length;

char ENDL;

int get_val(char c)
{
	if(c<='P')
		return(2+(c-'A')/3);
	else if(c=='R'||c=='S')
		return(7);
	else if(c=='T'||c=='U'||c=='V')
		return(8);
	else
		return(9);
}

void init()
{
	int i,j;
	scanf("%d",&N);
	scanf("%c",&ENDL);
	for(i=0;i<N;i++)
	{
		gets(a);
		length=strlen(a);
		num[i]=0;
		for(j=0;j<length;j++)
		{
			if(a[j]>='0'&&a[j]<='9')
				num[i]=num[i]*10+a[j]-'0';
			else if(a[j]>='A'&&a[j]<='Z')
				num[i]=num[i]*10+get_val(a[j]);
		}
	}
}

void process()
{
	int i,j;
	bool dup=false;
	for(i=0;i<N;)
	{
		for(j=i+1;j<N&&num[i]==num[j];j++);
		if(j-i>1)
		{
			printf("%03d-%04d %d\n",num[i]/10000,num[i]%10000,j-i);
			dup=true;
		}
		i=j;
	}
	if(!dup)
		printf("No duplicates.\n");
}

int main()
{
	init();
	sort(num,num+N);
	process();
	return(0);
}