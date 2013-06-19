
#include <stdio.h>
void main(){
int n,stu,i,score[1001],per;
float ave;
scanf("%d",&n);
while(n--)
{
	ave=0.0;
	per=0;
	scanf("%d",&stu);
	for(i=0;i<stu;i++)
	{
		scanf("%d",&score[i]);
		ave+=score[i];
	}
	ave/=stu;
	for(i=0;i<stu;i++)
		if(score[i]>ave) per++;
	printf("%.3f%%\n",1.0*per*100/stu);
}

	
}