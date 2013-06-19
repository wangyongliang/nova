#include <stdio.h>
void main()
{
	int k,m,c,r,i,j,counter,t,flag;
	int chosen[101],cata[101];
	scanf("%d",&k);
	while(k)
	{
		scanf("%d",&m);
		flag=1;
		for(i=0;i<k;i++)
			scanf("%d",&chosen[i]);
		for(t=1;t<=m;t++)
		{
			scanf("%d %d",&c,&r);
			counter=0;
			for(i=0;i<c;i++)
				scanf("%d",&cata[i]);
			if(flag)
			{
				for(i=0;i<k;i++)
				{
					for(j=0;j<c;j++)
						if(chosen[i]==cata[j]) counter++;
				}
				if(counter<r)flag=0;
			}
		}
		if(flag)printf("yes\n");
		else printf("no\n");
		scanf("%d",&k);
	}
} 