#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	int x,y,z;
};
class people 
{
public:
	node before;node behind;node left;node right;node up;node down;
	people()
	{
		before.x=1;	before.y=before.z=0;behind.x=-1;behind.y=behind.z=0;left.y=-1;left.z=left.x=0;
		right.y=1;right.x=right.z=0;up.z=1;up.x=up.y=0;down.z=-1;down.x=down.y=0;
	}
};

void turn_back(people &x)
{
	swap(x.before,x.behind);swap(x.left,x.right);
}
void turn_right(people &x)
{
	node tmp;tmp=x.left;x.left=x.before;x.before=x.right;x.right=x.behind;x.behind=tmp;
}

void turn_left(people &x)
{
	node tmp;tmp=x.right;x.right=x.before;x.before=x.left;x.left=x.behind;x.behind=tmp;
}

void turn_down(people &x)
{
	node tmp;tmp=x.up;x.up=x.before;x.before=x.down;x.down=x.behind;x.behind=tmp;
}
void turn_up(people &x)
{
	node tmp;tmp=x.up;x.up=x.behind;x.behind=x.down;x.down=x.before;x.before=tmp;
}

int main()
{
	int t;scanf("%d",&t);	
	int xx,yy,zz;char str[1000];
	while(t--)
	{
		int n;
		scanf("%d",&n);
		people x;xx=yy=zz=0;
		while(n--)
		{
			int k;
			scanf("%s%d",str,&k);
			if(strcmp(str,"left")==0) turn_left(x);
			else if(strcmp(str,"right")==0) turn_right(x);
			else if(strcmp(str,"up")==0) turn_up(x);
			else if(strcmp(str,"down")==0) turn_down(x);
			else if(strcmp(str,"back")==0) turn_back(x);
			xx+=x.before.x*k;yy+=x.before.y*k;zz+=x.before.z*k;
		}
		printf("%d %d %d ",xx,yy,zz);
		if(x.before.x==1) printf("0");
		else if(x.before.y==1) printf("1");
		else if(x.before.z==1) printf("2");
		else if(x.before.x==-1) printf("3");
		else if(x.before.y==-1) printf("4");
		else printf("5");printf("\n");
	}
	return 0;
}