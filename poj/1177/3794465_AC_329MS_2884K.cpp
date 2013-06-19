
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct Point{
 int l,r,len,lines,cover;//l为左端点,r为右端点,len为测度（被覆盖线段总长度）,lines为并区间个数,cover为覆盖次数
 int lf,rf;                  //lf为左节点覆盖标志,rf为右节点覆盖标志
 Point *lcd,*rcd;
};
void create(Point *p,int l,int r)            //建树
{
 p->l = l; p->r = r; p->lf = p->rf = p->len = p->lines = p->cover = 0; 
 p->lcd = p->rcd = NULL;
 if(r-l > 1){
  p->lcd = new Point;
  create(p->lcd,l,(l+r)>>1);           //递归建左子树
  p->rcd = new Point;
  create(p->rcd,(l+r)>>1,r);            //递归建右子树
 }
}
void update(Point *p)                 //每次插入获删除后的更新操作
{
 if(p->cover > 0){                   //整条线段被覆盖
  p->lf = p->rf = 1;
  p->lines = 1;
  p->len = p->r - p->l;
 }
 else if(p->r == p->l+1){              //未被覆盖的叶节点
  p->lf = p->rf = p->lines = p->len = 0;
 }
 else {                               //未被整个覆盖的非叶节点
  p->lf = p->lcd->lf;
  p->rf = p->rcd->rf;
  p->lines = p->lcd->lines + p->rcd->lines - p->lcd->rf*p->rcd->lf;
  p->len = p->lcd->len + p->rcd->len;
 }
}
void insert(Point *p,int l,int r)                 //插入操作
{
 if(l <= p->l && p->r <= r)
  p->cover++;
 else {
  int mid = (p->l+p->r)>>1;
  if(mid > l)
   insert(p->lcd,l,r);
  if(mid < r)
   insert(p->rcd,l,r);
 }
 update(p);
}
void deletee(Point *p,int l,int r)          //删除操作
{
 if(l <= p->l && p->r <= r)
  p->cover--;
 else {
  int mid = (p->l+p->r)>>1;
  if(mid > l)
   deletee(p->lcd,l,r);
  if(mid < r)
   deletee(p->rcd,l,r);
 }
 update(p);
}
struct Coord{
 int x,y1,y2,f;
}coord[10010];
bool cmp(const Coord &a,const Coord &b)
{
 return a.x < b.x;
}
bool used[10010];
int main()
{
 int n,i,x1,y1,x2,y2;
 scanf("%d",&n);
 for(i = 0; i < n+n; i+=2){
  scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
  coord[i].x = x1; coord[i].y1 = y1; coord[i].y2 = y2;  coord[i].f = i;
  coord[i+1].x = x2; coord[i+1].y1 = y1; coord[i+1].y2 = y2; coord[i+1].f = i;
 }
 sort(coord,coord+i,cmp);
 int ans, preline, prelen;
 Point root;
 create(&root,-10000,10000);
 insert(&root,coord[0].y1,coord[0].y2);
 preline = root.lines;
 prelen = root.len;
 ans = prelen;
 used[coord[0].f] = 1;
 for(i = 1; i < n+n; i++){
  if(!used[coord[i].f]){
   insert(&root,coord[i].y1,coord[i].y2);
   used[coord[i].f] = 1;
  }
  else {
   deletee(&root,coord[i].y1,coord[i].y2);
  }
  ans += abs(root.len - prelen);            //纵向周长增长量为前后两次测度的改变量
  ans += preline*(coord[i].x-coord[i-1].x)<<1;//横向周长的增长量为上一次区间个数乘2在乘横向长度
  prelen = root.len;
  preline = root.lines;
 }
 printf("%d\n",ans);
 return 0;
}
