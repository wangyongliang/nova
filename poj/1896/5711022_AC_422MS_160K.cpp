#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
using namespace std;
#define maxn 2000000
char s[maxn];
void print(int n)
{
	while(n--) printf(" ");
//	return 0;
}
int main()
{
	int i,j;
	s[0]=0;
	int len=0;
//	freopen("1.in","r",stdin);
	while(s[len]=getchar())
	{
		if(s[len]==EOF) break;
		len++;
	}
	j=0;
//	puts(s);
//	cout<<len<<endl;
//	cout<<"-------"<<endl;
	for(i=0;i<len;i++)
	{
		if(s[i]==' '||s[i]==10||s[i]==13||s[i]==9) continue;
		else
		{
			s[j++]=s[i];
		//	cout<<i<<" "<<j<<endl;
		}
	}
	s[j]=0;
//	puts(s);
	len=j;
	int n;
	n=4;
//	print(n);
	printf("{\n");
	print(n);
	for(i=1;i<len;i++)
	{
	//	printf("%c",s[i]);
		if(s[i]=='{') 
		{
			printf(" {\n");
			n+=4;
			print(n);
		}
		else if(s[i]==';')
		{
            if(i&&s[i-1]==';')
            {
                printf("\n");
                print(n);
            }
			printf(";");
//			print(n);
		}
		else if(s[i]=='}')
		{
            n-=4;
		//	if(i&&s[i-1]!=':'){
            printf("\n");
				print(n);
//            }
			printf("}");
		//	n-=4;
		}
		else if(s[i]==',') printf(", ");
		else {
            if(i&&s[i-1]==';')
            {
                printf("\n");
                print(n);                
            }
            printf("%c",s[i]);
        }
	}
//	system("pause");
//	getchar();

	return 0;
}


