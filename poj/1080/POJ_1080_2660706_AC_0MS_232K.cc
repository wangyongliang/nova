#include<stdio.h>
int a[101][101];
int b[5][5]={{5,-1,-2,-1,-3},
			{-1,5,-3,-2,-4},
			{-2,-3,5,-2,-2},
			{-1,-2,-2,5,-1},
			{-3,-4,-2,-1,-9999}};
int index[270]={0};
char s1[111],s2[11];
int max(int i,int j,int k)
{
	int temp;
	if(i>j) temp=i;
	else temp=j;
	if(temp<k) temp=k;
	return temp;
}
int main()
{
	int i,j,n,m;
	int temp;
	index['A']=0;
	index['C']=1;
	index['G']=2;
	index['T']=3;
	index[' ']=4;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,&s1);
		scanf("%d%s",&m,&s2);
		a[0][0]=b[index[s1[0]]][index[s2[0]]];
		temp=b[index[' ']][index[s2[0]]];
		for(i=1;i<m;i++)
		{
			a[0][i]=temp+b[index[s1[0]]][index[s2[i]]];
			temp+=b[index[' ']][index[s2[i]]];
		}
		temp=b[index[s1[0]]][index[' ']];
		for(i=1;i<=n;i++)
		{
			a[i][0]=temp+b[index[s1[i]]][index[s2[0]]];
			temp+=b[index[s1[i]]][index[' ']];
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<m;j++)
			{
				a[i][j]=max(a[i-1][j]+b[index[s1[i]]][index[' ']],a[i][j-1]+b[index[' ']][index[s2[j]]]
					,a[i-1][j-1]+b[index[s1[i]]][index[s2[j]]]);
			}
		}
		printf("%d\n",a[n-1][m-1]);
	}
	return 0;
}