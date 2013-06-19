#include<stdio.h>
int main()
{
	int max;
	int xx=0,yy=0;
	int tpx,tpy;
	int x,y;
	while(scanf("%d",&max)&&max)
	{
		tpx=max;
		tpy=0;
		xx=yy=0;
		while(scanf("%d%d",&x,&y))
		{
			if(x==-1) break;
			if(x<=tpx)
			{
				tpx-=x;
				tpy=tpy<y?y:tpy;
			}
			else
			{
				xx=xx<max-tpx?max-tpx:xx;
				yy+=tpy;
				tpx=max-x;
				tpy=y;
			}
		}
						xx=xx<max-tpx?max-tpx:xx;
				yy+=tpy;
				tpx=max-x;
				tpy=0;
		printf("%d x %d\n",xx,yy);
	}
	return 0;
}