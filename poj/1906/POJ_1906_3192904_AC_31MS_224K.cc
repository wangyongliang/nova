#include<stdio.h>
void print(int k)
{
	int a[110]={0};
	int i,j;
	a[0]=1;
	printf(" ");
	for(i=0;i<k;i++)
	{
		for(j=0;j<100;j++) a[j]*=3;
		for(j=0;j<100;j++) a[j+1]+=a[j]/10,a[j]%=10;
	}
	for(i=99;a[i]==0;i--);
	for(;i>=0;i--) printf("%d",a[i]);


}
int main()
{
    __int64 n;
    bool flag[65];
	int i;
    while(scanf("%I64d",&n)&&n)
    {
	//	n=0x7fffffffffffffff;
        for(i=0;i<65;i++) flag[i]=0;
        n--;
        for(i=0;i<65;i++,n/=2) flag[i]=n%2;
        printf("{");
        for(i=0;i<65&&flag[i]==0;i++);
        if(i!=65) print(i);
        for(i++;i<65;i++) 
		{
			if(flag[i]){
			printf(",");
			print(i);
			}
		}
        printf(" }\n");
    }
    return 0;
}
