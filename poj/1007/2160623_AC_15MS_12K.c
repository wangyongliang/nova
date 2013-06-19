#include <stdio.h>

int main()
{
    int m,n,i,j,k,sum[100],temp;
    char ca[100][51];
    while(scanf("%d %d",&m,&n)!=EOF){
        for(i=0;i<n;i++){
            sum[i]=0;
            scanf("%s",ca[i]);
            for(j=0;j<m-1;j++)
                for(k=j+1;k<m;k++) if(ca[i][j]>ca[i][k])sum[i]++;
        }
        for(i=0;i<n;i++)
		{
            k=0;temp=2000;
            for(j=0;j<n;j++)
                if(sum[j]<temp)
				{
                    temp=sum[j];
                    k=j;
				}
            sum[k]=2001;
            printf("%s\n",ca[k]);
        }
    }      
  return 0;
}