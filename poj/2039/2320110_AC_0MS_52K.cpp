#include <iostream.h>
#include <string.h>

int main() 
{
	int col;
	int i,j;
	while(cin>>col&&col)
	{
		char a[207];
		cin>>a;//gets(a) get a wa but cin>>a gets AC Why??
	    int len=strlen(a);
		int row=len/col;
		for(i=0;i<row;i++)
			for(j=0;j<col/2;j++)
			{
				if(i%2==1)
				{
					int temp=a[i*col+j];
					a[i*col+j]=a[i*col+col-j-1];
					a[i*col+col-j-1]=temp;
				}
			}
			
			for(i=0;i<col;i++)
    			for(j=0;j<row;j++)
    			{
    				cout<<a[i+j*col];
    			}
			cout<<endl;
	}
	return 0;
}