#include<stdio.h>
char s1[]={'-',' ','-','-',' ','-','-','-','-','-'};
char s2[]={' ',' ','-','-','-','-','-',' ','-','-'};
char s3[]={'-',' ','-','-',' ','-','-',' ','-','-'};
char ss1[10][2]={
'|','|',  
' ','|',
' ','|',
' ','|',
'|','|',
'|',' ',
'|',' ',
' ','|',
'|','|',
'|','|'
};
char ss2[10][2]={
'|','|',
' ','|',
'|',' ',
' ','|',
' ','|',
' ','|',
'|','|',
' ','|',
'|','|',
' ','|'};
int a[20],m;
void display(int t)
{
	int i,j,k;
	for(i=0;i<m;i++)
	{
		if(i>0) printf(" ");
		printf(" ");
		for(j=0;j<t;j++) printf("%c",s1[a[i]]);
		printf(" ");
	}
	printf("\n");
	for(j=0;j<t;j++)
	{
		for(i=0;i<m;i++)
		{
			if(i>0) printf(" ");
			printf("%c",ss1[a[i]][0]);
			for(k=0;k<t;k++) printf(" ");
			printf("%c",ss1[a[i]][1]);
		}
		printf("\n");
	}
	for(i=0;i<m;i++)
	{
		if(i>0) printf(" ");
		printf(" ");
		for(j=0;j<t;j++) printf("%c",s2[a[i]]);
		printf(" ");
	}
	printf("\n");
	for(j=0;j<t;j++)
	{
		for(i=0;i<m;i++)
		{
			if(i>0) printf(" ");
			printf("%c",ss2[a[i]][0]);
			for(k=0;k<t;k++) printf(" ");
			printf("%c",ss2[a[i]][1]);
		}
		printf("\n");
	}
	for(i=0;i<m;i++)
	{
		if(i>0) printf(" ");
		printf(" ");
		for(j=0;j<t;j++) printf("%c",s3[a[i]]);
		printf(" ");
	}
	printf("\n");
}
int main()
{
	int t,n,i;
	char s[200];
	while(scanf("%d%s",&t,&s)&&t)
	{
		for(m=0;s[m];m++) a[m]=s[m]-'0';
		display(t);
		printf("\n");
	}
	return 0;
}
