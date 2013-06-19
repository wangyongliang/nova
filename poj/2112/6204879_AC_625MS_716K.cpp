#include<iostream>
#include<stdlib.h>
using namespace std;
#include<memory.h>
#define SIZE 300

int con[SIZE][SIZE];

int s,t,queue[SIZE],head,tail,pre[SIZE],visit[SIZE],n;

bool findroad()
{
	int i,k;
	memset(visit,0,sizeof(visit));
	head = tail = 0;
	queue[tail++] = s;
	pre[s] = -1;
	while(tail > head){
		k = queue[head++];
		for(i = 0; i <= n; i++)
			if(!visit[i] && con[k][i] > 0){
				pre[i] = k;
				visit[i] = 1;
				if(i == t)
					return true;
				queue[tail++] = i;
			}
	}
	return false;
}

int Maxflow()
{
	int j,maxflow = 0;;
	while(findroad()){
		int min = 0x7FFFFFFF;
		for(j = t; j != s; j = pre[j])
			if(min > con[pre[j]][j])
				min = con[pre[j]][j];
			maxflow += min;
			for(j = t; j != s; j = pre[j]){
				con[pre[j]][j] -= min;             //容量调整
				con[j][pre[j]] += min;
				//flow[pre[j]][j] += min;
				//flow[j][pre[j] -= min;
			}
	}
	//	cout<<"maxflow = "<<maxflow<<endl;
	return maxflow;
}



int k,c,m;
int a[300][300];

#define inf 0x7fffffff


int main()
{
    int i,j;
    while(scanf("%d%d%d",&k,&c,&m)!=EOF)
    {
        n=k+c+1;
        for(i=1;i<n;i++)
        {
            for(j=1;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }            
        for(int l=1;l<n;l++)
        {
            for(i=1;i<n;i++)
            {
                if(a[i][l]==0) continue;
                for(j=1;j<n;j++)
                {
                    if(a[l][j]==0) continue;
                    if((a[i][j]==0)||(a[i][j]>a[i][l]+a[l][j])) a[i][j]=a[i][l]+a[l][j];
                }
            }
        }
		int        min=0;
		int        max=10000000;
        int mid;
        while(min<max)
        {
            mid=(min+max)/2;
            for(i=0;i<=n;i++) 
            {
                for(j=0;j<=n;j++) con[i][j]=0;
            }
            for(i=1;i<=k;i++) con[0][i]=m;
            for(i=1;i<=k;i++)
            {
                for(j=k+1;j<n;j++)
                {
                    if(a[i][j]&&(a[i][j]<=mid)) con[i][j]=1;
                    
                }
            }
            for(i=k+1;i<n;i++) con[i][n]=1;
            s=0;
            t=n;
            if(Maxflow()==c) 
			{
				max=mid;
			}
            else min=mid+1;
        }
        printf("%d\n",min);
    }
    return 0;
}
