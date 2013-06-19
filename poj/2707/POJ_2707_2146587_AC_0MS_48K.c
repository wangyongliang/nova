#include <stdio.h>
struct
{
	int a;
	int b;
}paper,image;
void main(){
	int t,p1,p2;
//printf("%c",'%');

scanf("%d %d %d %d",&image.a,&image.b,&paper.a,&paper.b);
	while(image.a||image.b||paper.a||paper.b){
if(image.a<image.b&&paper.a>paper.b||(image.a>image.b&&paper.a<paper.b))
{
t=paper.a;paper.a=paper.b;paper.b=t;
}
//printf("%d %d %d %d",image.a,image.b,paper.a,paper.b);
p1=100*paper.a/image.a;//printf("%d",p1);
p2=100*paper.b/image.b;//printf("%d",p2);
if(p1>=100&&p2>=100) printf("100%%\n");
else {printf("%d",(p1<p2?p1:p2));printf("%c\n",'%'); }
	
scanf("%d %d %d %d",&image.a,&image.b,&paper.a,&paper.b);}	
	} 