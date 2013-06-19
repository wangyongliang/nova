#include<stdio.h>
#include<string.h>
int a[20]={0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,5};
char aa[22][10]={"sdkshk","pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen",
"yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char b[23][10]={"wehk","imix","ik","akbal","kan","chicchan","cimi",
"manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
int main()
{
	int n,flag=1;
	long date;
	int i,j,k,l;
	int year;
	char temp[20];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d,",&j);
		scanf("%s",temp);
		scanf("%s",temp);
		scanf("%d",&k);
		date=k*365;
		k=1;
		while(strcmp(temp,aa[k])!=0)
		{
			date+=a[k];
			k++;
		}
		if(flag) printf("%d\n",n+1),flag=0;
		date+=j;
		date++;
		i=date/260;
		if(date%260==0)  i--;
		j=date%13;
		if(!j) j=13;
		k=date%20;
		if(!k) k=20;
		printf("%d %s %d\n",j,b[k],i);
	}
	return 0;
}