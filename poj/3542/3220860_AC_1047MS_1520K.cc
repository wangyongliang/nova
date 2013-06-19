#include<stdio.h>
//#include<time.h>
int data[10][22][300];
int len[10][22];
int a[]={0,1,3};
int aa[]={3,1,0};
int mp[3000][8];
void dfs(int deep,int sum,int num)
{
	if(deep==8) return;
	data[deep][sum][len[deep][sum]++]=num;
	int num1,i;
	for(i=0;i<3;i++)
	{
		num1=num*3+i;
		dfs(deep+1,sum+a[i],num1);
	}
}
int b[10],p[10],n;
int cnt,kk;
int ans[6][371293];
bool flag[6][371293]={0};
int mod;
void dfs1(int deep,int r,bool fg)
{
	int i,j,k,tp,tp1,sum,dt;
	int cnt1;
	if(deep==n)
	{
		if(b[deep]==p[deep]) cnt++;
		return;
	}
	if(n-deep<=4)
	{
		mod=(n-deep)*3+1;
		j=0;
		for(i=deep;i<=n;i++) j=j*mod+(p[i]-b[i]);
		if(j>=471293||j<0) while(1);
		if(flag[n-deep+1][j]) 
		{
			cnt+=ans[n-deep+1][j];
			return ;
		}
	}
	cnt1=cnt;
	int m=p[deep]-b[deep];
	if(m>(n-deep)*3) return ;
	for(i=0;i<len[n-deep][m];i++)
	{
		k=data[n-deep][m][i];
		sum=tp1=0;
		dt=7-n;
		for(j=n;j>deep;j--)
		{
			tp=b[j]+aa[mp[k][j+dt]];
			if(mp[k][j+dt]==1) tp1++;
			if(tp>p[j]) break;
			if(tp+3*(n-deep-1)<p[j]) break;
			if(tp1+r>kk) break;
			sum+=p[j]-tp;
		}
		if(j==deep)
		{
			tp=(n-deep)*(n-deep-1);
		//	tp/=2;
		//	j=kk-r-tp1;
		//	tp=j*2+(tp-j)*3;
		//	if(sum==tp){
			k=data[n-deep][m][i];
			for(j=n;j>deep;j--) b[j]+=aa[mp[k][j+dt]];
			dfs1(deep+1,r+tp1,fg);
			k=data[n-deep][m][i];
			for(j=n;j>deep;j--) b[j]-=aa[mp[k][j+dt]];
		//	}
		}
	}
	if(n-deep<=4)
	{
		mod=(n-deep)*3+1;
		j=0;
		for(i=deep;i<=n;i++) j=j*mod+(p[i]-b[i]);
		if(j>=471293||j<0) while(1);
		flag[n-deep+1][j]=1;
		ans[n-deep+1][j]=cnt-cnt1;
	}
}
int main()
{
	int i,j,k;
	int sum;
	for(i=0;i<8;i++)
	{
		for(j=0;j<22;j++) len[i][j]=0;
	}
	dfs(0,0,0);
	for(i=0;i<=2186;i++)
	{
		k=i;
		for(j=7;j>=0;j--,k/=3) mp[i][j]=k%3;
	}

//	printf("%d\n",max);
//	freopen("test.in","r",stdin);
//	freopen("put.out","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		kk=n*(n-1)*3;
		kk/=2;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			kk-=p[i];
			b[i]=0;
		}
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(p[i]>3*(n-1)) break;
		}	
	//	int st,en;
	//	st=clock();
		if(kk<0||i<=n||kk>n*(n-1)/2);
		else
		{
		//	printf("OK!");
			dfs1(1,0,1);
		}
	//	en=clock();
	//	printf("time is %d\n",en-st);
		printf("%d\n",cnt);
	}
	return 0;
}

