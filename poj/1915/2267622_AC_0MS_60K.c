#include <math.h>
#include <stdio.h>
int main()
{
int s,x1,x2,y1,y2,c,x,y,l;
scanf("%d",&s);
while(s--) {
      scanf("%d",&l);
      scanf("%d%d",&x1,&y1);
      scanf("%d%d",&x2,&y2);
      x=x1-x2;
      y=y1-y2;
      c=0;
      if(x*x==1&&y*y==1&&(x1==0&&y1==0||x2==0&&y2==0||
            x1==l-1&&y1==l-1||x2==l-1&&y2==l-1||
            x1==l-1&&y1==0||x2==l-1&&y2==0||
            x1==0&&y1==l-1||x2==0&&y2==l-1))c=4-y;
      else if(l==4&&x*x+y*y==9&&(x1==0&&x2==0||x1==3&&x2==3||y1==0&&y2==0||y1==3&&y2==3))c=5-y;
      else if(x*x+y*y==8)c=4-y;
      else if(x*x+y*y==1)c=3-y;
      else for(;;) {
       x=abs(x); y=abs(y);
       if(x>y){int p=x;x=y;y=p;}
       if(x+y<2)break;
       x--;
       y-=2;
       c++;
      }
printf("%d\n",c+y);
}
return 0;
}

