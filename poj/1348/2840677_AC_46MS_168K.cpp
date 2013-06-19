#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double INF=1e10;
const double EPS=1e-9;
const double ADD=INF+1;
const double SUB=INF+2;
const double MUL=INF+3;
const double DIV=INF+4;
double a[7];
double stack[7];

int finish;
bool isop(double val) { return val>INF;}
double work(double num1,double num2,double op)
{
	if (fabs(op-1)<EPS) return num1+num2;
	if (fabs(op-2)<EPS) return num1-num2;
	if (fabs(op-3)<EPS) return num1*num2;
	if (fabs(num2)<EPS)  return INF;
	else return num1/num2;
}
double cal()
{
	int top,i;
	double sstack[7];
	top=-1;
	for(i=0;i<7;i++)
		if (i>1 && isop(stack[i])){
			sstack[top-1]=work(sstack[top-1],sstack[top],stack[i]-INF);
			if (fabs(sstack[top-1]-INF)<EPS) return INF;
			top--;
		}
		else sstack[++top]=stack[i];	
	return sstack[0];
}
void DFS(int an,int pn)
{
	int i;
	if (finish==1) return;
	if (an+pn==7){
		if (fabs(cal()-a[4])<EPS) finish=1;
		return;
	}
	if(an<4){
		stack[an+pn]=a[an];	
		DFS(an+1,pn);	
	}
	if (an-pn>=2){
		for(i=1;i<=4;i++){
			stack[an+pn]=INF+i;	
			DFS(an,pn+1);	
		}	
	}	
}	
int main()
{
	int i;
	while(scanf("%lf%lf%lf%lf%lf",&a[0],&a[1],&a[2],&a[3],&a[4])==5)
	{
		finish=0;
		for(i=0;i<5;i++) printf("%.0lf ",a[i]);
		sort(a,a+4);
		do{
			DFS(0,0);
			if (finish) break;
		}while(next_permutation(a,a+4));
		if (finish) printf("OK!\n");
		else printf("NO!\n");
	}
	return 0;
}