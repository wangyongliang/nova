#include<stdio.h>
#include<string.h>


const int ttime[]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4}; 
const int key[]=  {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9,10};

int main()
{
	//freopen("cch.txt","r",stdin);
	char str[1005];
	long count;
	int t,i;
	int p,w;
	char pre,now;
	int length;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d\n",&p,&w);
		gets(str);
		count=0;
		length=strlen(str);
		if(length>0){
			i=0;
			count+=ttime[str[i]-'A']*p;
			pre=str[i];
			i++;
			while(i<length){
				now=str[i];
				if(now==' ')	count+=p;
				else if(key[now-'A']==key[pre-'A'])	count=count+w+ttime[now-'A']*p;
				else if(key[now-'A']!=key[pre-'A'])	count+=ttime[now-'A']*p;
				pre=now;
				i++;
			}
		}
		printf("%ld\n",count);
	}
	return 0;
}