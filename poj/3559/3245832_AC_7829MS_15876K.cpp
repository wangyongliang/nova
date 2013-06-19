#include<stdio.h>
#include<math.h>
#include<string.h>
#define maxn 1000010
double tp1[maxn],tp2[maxn];//tp1==max,tp2=min
int main()
{
	int  i,n;
	double ans,tp,tp3;
	tp1[0]=cos((double)0);
	tp1[1]=cos(0.5);
	tp2[0]=tp1[0];
	tp2[1]=tp1[1];
	int cnt[2];
	char s[10][10];
	bool flag1,flag2,flag3;
	while(scanf("%s%s%s%s%d",s[0],s[1],s[2],s[3],&n)!=EOF)
	{
		for(i=2;i<n;i++)
		{
			tp=i;
			ans=cos(tp/2.0);
			tp1[i]=tp1[i-2];
			tp2[i]=tp2[i-2];
			tp1[i]=ans>tp1[i]?ans:tp1[i];
			tp2[i]=ans<tp2[i]?ans:tp2[i];
		}
		cnt[0]=cnt[1]=0;
		ans=0.0;
		for(i=0;i<3;i++)
		{
			if(strcmp(s[i],"sin")==0) 
			{
				cnt[0]++;
				if(i==2) ans+=sin((double)n-2);
				else ans+=sin(1.0);
			}
			if(strcmp(s[i],"cos")==0) 
			{
				cnt[1]++;
				if(i==2) ans+=cos((double)n-2);
				else ans+=cos(1.0);
			}
		}
		if(strcmp(s[3],"min")==0) flag3=0;
		else flag3=1;
		if(cnt[0]&1) flag1=0;
		else flag1=1;
		if(cnt[0]>=2) flag2=0;
		else flag2=1;
		for(i=2;i<n;i++)
		{
			tp3=i;
			tp=2.0;
			if(flag2==0) tp*=sin(tp3/2.0);
			else tp*=cos(tp3/2.0);
			if(flag3==0)
			{
				//	if(tp>0.0)tp*=tp2[i-2];
				if(tp*tp2[i-2]<tp*tp1[i-2]) tp=tp*tp2[i-2];
				else tp=tp*tp1[i-2];
			}
			else
			{
				if(tp*tp1[i-2]>tp*tp2[i-2])	tp*=tp1[i-2];
				else tp*=tp2[i-2];
			}
			if(flag1==0) tp+=sin((double)(n-i));
			else tp+=cos((double)(n-i));
			if(flag3) ans=ans>tp?ans:tp;
			else ans=ans<tp?ans:tp;
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}
