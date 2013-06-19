#include<iostream>
#include<stdlib.h>
using namespace std;
#define maxn 1010
int a[maxn],b[maxn],dp[maxn][maxn][2];
int c,h,B;

int max(int x,int y)
{
	if(x<y) return y;
	else return x;
}
int min(int x,int y)
{
	if(x<y) return x;
	else return y;
}
int f(int x,int y,int flag)
{
	if(dp[x][y][flag]!=-1) return dp[x][y][flag];
	else
	{
		int tp1=0x7fffffff,tp2;
		if(flag==0)
		{
			if(x)		
			{
				tp2=f(x-1,y,0)+b[x]-b[x-1];
				tp2=max(tp2,a[x]);
				tp1=min(tp2,tp1);
			}	
			if(y+1<c)
			{
				tp2=f(x,y+1,1)+b[y+1]-b[x];
				tp2=max(tp2,a[x]);
				tp1=min(tp2,tp1);
			}
		}
		else
		{
			if(x)		
			{
				tp2=f(x-1,y,0)+b[y]-b[x-1];
				tp2=max(tp2,a[y]);
				tp1=min(tp2,tp1);
			}	
			if(y+1<c)
			{
				tp2=f(x,y+1,1)+b[y+1]-b[y];
				tp2=max(tp2,a[y]);
				tp1=min(tp2,tp1);
			}
		}
		if(tp1==0x7fffffff) tp1=-1;
		dp[x][y][flag]=tp1;
		return tp1;
	}
}
int main()
{
	int i,j,k;
	while(cin>>c>>h>>B){
		for(i=0;i<=h;i++) a[i]=-1;
		a[0]=0;
		k=0;
		while(c--)
		{
			cin>>i>>j;
			k=max(k,j);
			if(a[i]<j) a[i]=j;
		}
		a[B]=k;
		c=0;
		for(i=0;i<=h;i++){
			if(a[i]!=-1) 
			{
				a[c]=a[i];
				b[c]=i;
				c++;
			}
		}
		for(i=0;i<c;i++) {
            if(b[i]==B){
                B=i;
                break;
            }
        }
		for(i=0;i<c;i++){
			for(j=0;j<c;j++) dp[i][j][0]=dp[i][j][1]=-1;
		}
		dp[0][c-1][0]=a[0];
		dp[0][c-1][1]=max(a[c-1],b[c-1]);
		int tp1=f(B,B,0);
		int tp2=f(B,B,1);
		if(tp1<tp2) cout<<tp1<<endl;
		else cout<<tp2<<endl;
	}
	return 0;
}
