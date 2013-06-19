#include<stdio.h>
#include<string.h>
char s[101][100],c[100]="http://www.acm.org/";;
int j=1,k=0,l=1,b[101],f[101];
void vist()
{
	strcpy(s[j],&c[6]);
	b[l++]=j;
	k=0;
	puts(s[j++]);
}
void back()
{
	if(l>1)
	{
		f[k++]=b[--l];
		puts(s[b[l-1]]);
	}
	else
		printf("Ignored\n");
}
void forward()
{
	if(k>0)
	{
		b[l++]=f[--k];
		puts(s[f[k]]);
	}
	else	
		printf("Ignored\n");
}
void main()
{
	strcpy(s[0],c);
	b[0]=0;
	while(1)
	{
		gets(c);
		if(c[0]=='V')vist();
		else if(c[0]=='B')back();
		else if(c[0]=='F')forward();
		else if(c[0]=='Q')break;
	}
}