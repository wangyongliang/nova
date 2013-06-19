/*#include<stdio.h>
#include<string.h>
#define maxn 5010
char a[maxn*2],b[maxn],c[maxn];
int n,next[maxn];
void getnext(char s[])
{
	int i,j=-1;
	next[0]=-1;
	for(i=0;i<n;i++)
	{
		if(j==-1||s[i]==s[j])
		{
			i++,j++;
			next[i]=j;
		}
		else j=next[j];
	}
}
int kmp(char s1[],char s2[])
{
	int i,j;
	int n1,n2;
	n1=strlen(s1);
	n2=strlen(s2);
	getnext(s2);
	for(i=j=0;i<n1&&j<n2;)
	{
		if(j==-1||s1[i]==s2[j]) i++,j++;
		else j=next[j];
	}
	if(j>=n2) return 1;
	else return 0;
}
int main()
{
	while(scanf("%s%s",a,b)!=EOF)
	{
		printf("%d\n",kmp(a,b));
	}
	return 0;
}
*/
#include <stdio.h>
#include <string.h>
#define SIZE 5050

void GetNext(char* t,int lt,int* next) 
{ 
	int i=0,j=-1; 
	next[0]=-1; 
	while(i<lt) 
	{
		if(j<0 || t[i]==t[j]) 
		{ 
			i++; j++; 
			next[i]=j;
		/*	if(t[i]!=t[j]) 
				next[i]=j; 
			else           
				next[i]=next[j]; 
				*/
		} 
		else  j=next[j]; 
	}
} 
int next[SIZE];
int KMP(char* s,char* t) 
{ 
	int i=0,j=0,lt,ls; 
	lt=strlen(t); ls=strlen(s); 
	GetNext(t,lt,next); 
	while(i<ls && j<lt) 
	{
		if(j<0 || s[i]==t[j])
		{ 
			i++; 
			j++; 
		} 
		else  
			j=next[j]; 
	}
	if(j<lt) 
		return -1;
	else  
		return i-lt; 
} 

char a[SIZE],b[SIZE*2],c[SIZE];
int n;
int main()
{
	int i,j,k;
	scanf("%s",a);
	scanf("%s",b);
    n = strlen(b);
	for(i = 0,j = n; i < n; i++,j++)
		b[j] = b[i];
	b[j] = 0;
	for(j = 0; j < n; j++)
	{
		for(i = 0,k = j; i < n; i++,k++)
		{
			if(b[k] == a[i])
				c[i] = '0';
			else c[i] = '1';
		}
		c[i] = 0;
		if(KMP(b,c) != -1)
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
