#include<iostream>
#include<string>

using namespace std;
char s[1000];
int a[10000];
string ans;
int b,len;
void f()
{
	int i;
	while(a[0]==0&&len>0)
	{
		for(i=0;i<len;i++){
			a[i]=a[i+1];

		}
		len--;
	}
//	f();
}
void mun(int x)
{
	int i;
a[len-1]-=x;
	for(i=len-1;i>=0;i--)
	{
		if(a[i]<0)
		{
			a[i-1]--;
			a[i]+=10;
		}
	}
	f();
}
int mod()
{
	int i;
	int x=0;
	for(i=0;i<len;i++)
	{
		x=x*10+a[i];
	//	a[i]=x/b;
		x%=b;
	}
	if(x==0) x=b;
	return x;
}
void div()
{
	int i;
	int x=0;
	for(i=0;i<len;i++)
	{
		x=x*10+a[i];
		a[i]=x/b;
		x%=b;
	}
	f();
}

int main()
{
	int i;
	while(scanf("%d%s",&b,s)!=EOF)
	{
		for(i=0;s[i];i++) a[i]=s[i]-'0';
		
		ans="";
		len=i;
		f();
		while(len)
		{
		int	x=mod();
		char		ch=x+'0';
				ans=ch+ans;
				mun(x);
				div();


		}
		cout<<ans<<endl;
	}
	return 0;
}

