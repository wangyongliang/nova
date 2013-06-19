#include<iostream>

using namespace std;
#define maxn 110
int flag[maxn];
int a[maxn][4];
int f(int i,int j)
{
	int x,y;
	for(x=0;x<2;x++)
	{
		for(y=2;y<4;y++)
		{
			if(a[j][x]>=a[i][0]&&a[j][x]<=a[i][1]&&
				a[j][y]>=a[i][2]&&a[j][y]<=a[i][3]) return 1;
		}
	}
	return 0;
}
int min(int x,int y)
{
	return x>y?y:x;
}
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	int x,y,i,j,n,k;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			int xi,yi,ri;
			scanf("%d%d%d",&xi,&yi,&ri);
			a[i][0]=xi-ri;
			a[i][1]=xi+ri;
			a[i][2]=yi-ri;
			a[i][3]=yi+ri;
			flag[i]=0;
			
		}
	//	cout<<f(0,1)<<endl;
		for(i=0;i<n;i++)
		{
			int cnt=0;
			for(j=0;j<n;j++)
			{
				if(flag[j]==0)
				{
					for(k=j+1;k<n;k++)
					{
						if(flag[k]==0&&(f(j,k)||f(k,j)))
						{
							a[j][0]=min(a[j][0],a[k][0]);
							a[j][1]=max(a[j][1],a[k][1]);
							a[j][2]=min(a[j][2],a[k][2]);
							a[j][3]=max(a[j][3],a[k][3]);
							flag[k]=1;
							cnt++;
					//		cout<<a[j][0]<<" "<<a[j][1]<<" "<<a[j][2]<<" "<<a[j][3]<<endl;
						}
					}
				}
			}
			if(!cnt) break;
		}
		int ans=x*y;
		for(i=0;i<n;i++)
		{
			if(flag[i]==0)
			{
				ans-=(a[i][0]-a[i][1])*(a[i][2]-a[i][3]);
			}

		}
		cout<<ans<<endl;
	}
	return 0;
}
