#include<iostream>
using namespace std;


int upperInt(int integer,int mod)
{
	if(integer%mod==0)
		return integer/mod;
	else
		return integer/mod+1;
}

int main()
{
	
	while(true)
	{
		int sum;
		int parcel;
		int b[7];
		int i;
		sum=0;
		for(i=1;i<=6;i++)
		{
			cin>>b[i];
			sum+=i*i*b[i];
		}
		if(sum==0)
			break;
		parcel=b[6]+b[5]+b[4]+upperInt(b[3],4);
		int room22=5*b[4]; //extra room for 2*2
		int room11=11*b[5];//extra room for 3*3
		switch(b[3]%4)
		{
		case 1: room22+=5;room11+=7;break;
		case 2: room22+=3;room11+=6;break;
		case 3: room22+=1;room11+=5;break;
		}
		if(b[2]<=room22)
		{
			room11+=(room22-b[2])*4;
			
			if(b[1]>room11)
			{
				parcel+=upperInt(b[1]-room11,36);
			}
		}
		else
		{
			int more22=b[2]-room22;
			parcel+=upperInt(more22,9);
			if(more22%9!=0)
				room11+=(9-(more22%9))*4;
			if(b[1]>room11)
			{
				parcel+=upperInt(b[1]-room11,36);
			}
		}
		cout<<parcel<<endl;

	}
		
		
	return 0;
}

