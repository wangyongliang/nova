#include <iostream>
#include <strstream>
using namespace std;
char NN[20][128];
int digits[10];
//NN[0]=original number
//NN[k]=k-th inv
//if(NN[0]==NN[1]) self-inventorying
//if(NN[i]==NN[k]) enters an inventory loop of length k-i
//if(NN[k]==NN[k+1]) self-inventorying after k steps

void func1016(int k)//转换函数
{
	int i=0;
	for(i=0;i<10;i++) digits[i]=0;
	ostrstream out(NN[k+1],81);
	i=0;
	while(NN[k][i]!='\0')//统计NN[k]中每个数字的频度
	{
		digits[NN[k][i]-'0']++;
		i++;
	}
	for(i=0;i<10;i++)//输出结果
	{
		if(digits[i]) out<<digits[i]<<i;
	}
	out<<'\0'<<endl;
}

bool IsEqual(const char* str1,const char* str2)
{
	while(*str1==*str2&&*str1!='\0'&&*str2!='\0')
	{
		str1++;
		str2++;
	}
	return *str1==*str2;
}

int main()
{
	int k,i;
	for(;;)
	{
		cin>>NN[0];
		if(NN[0][0]=='-') break;
		for(k=0;k<15;k++)
		{
			func1016(k);
			if(IsEqual(NN[k],NN[k+1]))
			{
				if(k==0)//第一次就成立
				{
					cout<<NN[0]<<" is self-inventorying"<<endl;
					break;
				}
				else//第k次成立
				{
					cout<<NN[0]<<" is self-inventorying after "<<k<<" steps"<<endl;
					break;
				}
			}
			for(i=0;i<k;i++) if(IsEqual(NN[i],NN[k+1])) break;
			if(i!=k)//出现循环
			{
				cout<<NN[0]<<" enters an inventory loop of length "<<k+1-i<<endl;
				break;
			}
		}
		if(k==15)//做了15次转换还不能成立
			cout<<NN[0]<<" can not be classified after 15 iterations"<<endl;
	}
	return 0;
}
