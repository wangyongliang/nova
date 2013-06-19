#include <iostream>
using namespace std;
int main()
{
	char s1[6000],s2[6000],s3[6000],t1[12000],t2[12000];
	long i,l,j,k,d;
	bool flag;
	cin>>s1>>s2;
	flag=false;
	l=strlen(s1);
	strcpy(t1,s1);
	strcat(t1,s1);
	for(i=0;i<l;i++)
	{
		for(k=0;k<l;k++)
		{
			j=(i+k)%l;
			if (s2[k]==s2[j]) s3[k]='0';
			else s3[k]='1';
		}
		strcpy(t2,s3);
		strcat(t2,s3);
		j=0;k=0;
		while ((j<l)&&(k<l))
		{
			d=0;
			while ((t1[j+d]==t2[k+d])&&(d<l)) d++;
			if (d<l)
			{
				if (t1[j+d]>t2[k+d]) j+=d+1;
				else k+=d+1;
			}
			else
			{
				flag=true;
				break;
			}
		}
		if (flag) break;
	}
	if (flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
