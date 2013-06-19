#include <iostream.h>
#include <string.h>

int i,j,l;
int i0,k,temp;
int b[1001];
int f[1001];
char a[1001][100];

void p(int x)
{
	cout<<a[x]<<endl;
}
void init()
{   i=0;j=0;k=1;
    char a0[]="http://www.acm.org/";
	for(l=0;a0[l];l++){
		a[1][l]=a0[l];
	}
	temp=1;
}
void visit()
{
	b[++i]=temp;
	cin>>a[++k];
	temp=k;
	p(temp);
	j=0;
}
void back()
{
	if(i>0){
		f[++j]=temp;
		temp=b[i];
		--i;
		p(temp);
	}
	else{cout<<"Ignored"<<endl;}
}
void forward()
{
	if(j>0){
		b[++i]=temp;
		temp=f[j];
		--j;
		p(temp);
    }
	else{cout<<"Ignored"<<endl;
	}
}
int main()
{
     init();
	 while(1)
	 {
		  char c[100];
		  cin>>c;
		  if(c[0]=='V'){visit();}
		  else if(c[0]=='B'){back();}
		  else if(c[0]=='F'){forward();}
		  else if(c[0]=='Q'){break;}
	 }
	 return 0;
}