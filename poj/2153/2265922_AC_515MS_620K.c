#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/*#include<assert.h>*/

typedef struct node
{    char name[31];
    int score;
    struct node *left,*right;
}NODE;

NODE *root = NULL;
int nStudent,nCourse,rank,nowscore;

void MakeTree()
{    int i,cmp;
    char buf[31];
    NODE *p,*parent;
    scanf("%d",&nStudent);
    getchar();
    /*单独处理第一个*/
    gets(buf);
    root = malloc(sizeof(NODE));
    strcpy(root->name,buf);
    root->score = 0;
    root->left = root->right = NULL;
    /*循环处理后续结点*/
    for(i=1;i<nStudent;++i)
    {    gets(buf);
        p = root;
        while( p )
        {    parent = p;
            cmp = strcmp(buf,p->name);
            /*assert(cmp != 0);*/
            if(cmp>0)
                p = p->right;
            else
                p = p->left;
        }
        p = malloc(sizeof(NODE));
        strcpy(p->name,buf);
        p->score = 0;
        p->left = p->right = NULL;
        /*cmp = strcmp(p->name,parent->name);*/
        if(cmp>0)
        {    parent->right = p;
        }
        else
        {    parent->left = p;
        }
    }
    scanf("%d",&nCourse);
}

int *searchscore(char *name)
{    NODE *p;
    int cmp;
    p = root;
    while(p)
    {    cmp = strcmp(name,p->name);
        if(cmp>0)
            p = p->right;
        else if(cmp<0)
            p = p->left;
        else
            return &(p->score);
    }
    /*assert(1);*/
    return NULL;
}

void PostOrder(NODE *p)
{    if(p->left)
        PostOrder(p->left);
    if(p->right)
        PostOrder(p->right);
    if(p->score > nowscore)
        ++rank;
}

int main()
{    int i,j,temp;
    int *pscore;
    char namebuf[31],c;
    MakeTree();
    pscore = searchscore("Li Ming");
    for(i=0;i<nCourse;++i)
    {    for(j=0;j<nStudent;++j)
        {    scanf("%d",&temp);
            getchar();
            gets(namebuf);
            *(searchscore(namebuf)) += temp;
        }
        rank = 1;
        nowscore = *pscore;
        PostOrder(root);
        printf("%d\n",rank);
    }
    return 0;
}