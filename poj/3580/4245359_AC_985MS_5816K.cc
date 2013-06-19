#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
using namespace std;

const int INF = 200000000;

struct Tnode{
	int t;				//子树结点个数 
	int delta, m, data;	//m-最小值	
	bool reverse;		//是否反转 
	Tnode*lch, *rch, *parent;
} *tree, *nullnode;

int n;

void getdown(Tnode *p)
{
	Tnode*r;
	if (p->reverse){
		p->reverse=false;
		r=p->lch; p->lch=p->rch; p->rch=r;
		p->rch->reverse=!(p->rch->reverse);
		p->lch->reverse=!(p->lch->reverse);
	}
	if (p->lch!=nullnode)
		p->lch->delta+=p->delta;
	if (p->rch!=nullnode)
		p->rch->delta+=p->delta;
	p->data+=p->delta;
	p->m+=p->delta;
	p->delta=0;
}

void getcur(Tnode*p)
{
	p->m=min(p->data, min(p->lch->m+p->lch->delta, p->rch->m+p->rch->delta));
	p->t=p->lch->t+p->rch->t+1;
}

void lrot(Tnode*p)
{
	Tnode*q;
	q=p->parent;
	p->parent=q->parent;
	if (q->parent==nullnode)
		tree=p; 
	else
	if (q->parent->lch==q)
		q->parent->lch=p;
	else
		q->parent->rch=p;
	q->lch=p->rch;
	p->rch->parent=q;
	p->rch=q;
	q->parent=p;
	getcur(q);
	getcur(p);
}

void rrot(Tnode*p)
{
	Tnode*q;
	q=p->parent;
	p->parent=q->parent;
	if (q->parent==nullnode)
		tree=p; 
	else
	if (q->parent->lch==q)
		q->parent->lch=p;
	else
		q->parent->rch=p;
	q->rch=p->lch;
	p->lch->parent=q;
	p->lch=q;
	q->parent=p;
	getcur(q);
	getcur(p);
}

void splay(Tnode *p)
{
	while (p->parent!=nullnode){
		if (p->parent->lch==p){
			if (p->parent->parent==nullnode)
				lrot(p);
			else
			if (p->parent->parent->lch==p->parent){
				lrot(p->parent);
				lrot(p);
			}
			else
			{
				lrot(p);
				rrot(p);
			}
		}
		else
		{
			if (p->parent->parent==nullnode)
				rrot(p);
			else
			if (p->parent->parent->rch==p->parent){
				rrot(p->parent);
				rrot(p);
			}
			else
			{
				rrot(p);
				lrot(p);
			}
		}
	}
}

bool find(int k)
{
	if (tree==nullnode){
		if (k==0) return true; else return false;
	}
	if (k<=0 || k>tree->t) 
		return false;
	
	Tnode*p;
	p=tree;
	getdown(p);
	while (p->lch->t + 1!=k){
		if (p->lch->t>=k)
			p=p->lch;
		else
		{
			k-=(p->lch->t + 1);
			p=p->rch;
		}				
		getdown(p);
	}
	splay(p);
	return true;
}
	 
void insert(int x, int id)
{
	Tnode *temp = new Tnode, *p;
	temp->lch=temp->rch=temp->parent=nullnode;
	temp->data=x;
	temp->reverse=false;
	temp->m=x;
	temp->t=1;
	temp->delta=0;
	
	find(id);
	
	if (tree==nullnode){
		tree=temp;
		temp->parent=nullnode;
	}
	else
	{
		Tnode*right=tree->rch;
		tree->rch=temp; temp->parent=tree;
		getcur(tree);
		find(id+1);
		tree->rch=right;
		right->parent=tree;
		getcur(tree);
	}
}

void cut(int x, int y, Tnode*&left, Tnode*&right)
{ 
	find(x);
	left=tree->lch;
	tree->lch=nullnode;
	getcur(tree);
	
	find(y-x+1);
	right=tree->rch;
	tree->rch=nullnode;
	getcur(tree);
}

int getmin(int x, int y)
{
	Tnode*left, *right; 
	cut(x, y, left, right);
	
	int m=tree->m+tree->delta;
	find(1);
	tree->lch=left; left->parent=tree;
	getcur(tree);
	find(y);
	tree->rch=right; right->parent=tree;
	getcur(tree);
	
	return m;
}

void add(int x, int y, int delta)
{
	Tnode*left, *right; 
	cut(x, y, left, right);
	 
	tree->delta+=delta;
	find(1);
	tree->lch=left; left->parent=tree;
	getcur(tree);
	find(y);
	tree->rch=right; right->parent=tree;
	getcur(tree);
}

void reverse(int x, int y)
{
	Tnode*left, *right;
	cut(x, y, left, right);
	
	tree->reverse=(!tree->reverse);
	find(1);
	tree->lch=left; left->parent=tree;
	getcur(tree);
	find(y);
	tree->rch=right; right->parent=tree;
	getcur(tree);	
}

void revolve(int x, int y, int t)
{
	int L=y-x+1;
	t=t%L;
	if (t>0){
		Tnode*l1, *l2, *l3, *l4;
		cut(x, y, l1, l2);
		cut(1, L-t, l3, l4);
		find(1);
		tree->lch=l4; l4->parent=tree;
		getcur(tree);
		find(1);
		tree->lch=l1; l1->parent=tree;
		getcur(tree);
		find(y);
		tree->rch=l2; l2->parent=tree;
		getcur(tree);
	}
}

void del(int x)
{
	find(x);
	Tnode*left=tree->lch, *right=tree->rch, *p=tree;
	if (left->t!=0){
		tree=left;
		tree->parent=nullnode;
		find(tree->t);
		tree->rch=right;
		right->parent=tree;
		getcur(tree);	
	}	
	else
	if (right->t!=0){
		tree=right;
		tree->parent=nullnode;
	}
	else
		tree=nullnode;
	delete p;		
}

void init()
{
	int i, x;
	
	nullnode=new Tnode;
	nullnode->data=INF;
	nullnode->m=INF;
	nullnode->t=0;
	nullnode->delta=0;
	
	tree=nullnode;
	scanf("%d", &n);
	for (i=1; i<=n; i++){
		scanf("%d", &x);
		insert(x, i-1);		
	}
}

void work()
{
	int m, x, y, delta, t;
	char s[10];
	
	scanf("%d", &m);
	while (m--){
		scanf("%s", s);
		if (strcmp(s, "MIN")==0){
			scanf("%d%d", &x, &y);
			printf("%d\n", getmin(x, y));	
		}
		else
		if (strcmp(s, "ADD")==0){
			scanf("%d%d%d", &x, &y, &delta);
			add(x, y, delta);
		}
		else
		if (strcmp(s, "REVERSE")==0){
			scanf("%d%d", &x, &y);
			reverse(x, y);
		}
		else
		if (strcmp(s, "REVOLVE")==0){
			scanf("%d%d%d", &x, &y, &t);
			revolve(x, y, t);			
		}
		else
		if (strcmp(s, "INSERT")==0){
			scanf("%d%d", &x, &y);
			insert(y, x);
		}
		else
		if (strcmp(s, "DELETE")==0){
			scanf("%d", &x);
			del(x);
		}
		else
			printf("ERROR!!!\n");

	}
}

int main(){

	init();
	work();

	return 0;
}

