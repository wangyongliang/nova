#include <stdio.h>  
const int maxn=1000001;    
int pos[maxn];
bool s[maxn];    
int main()  
{
    int cs,n,m,i,tmp,k,p;   
    bool ok;   
    k=0;   
    //freopen("in.txt","r",stdin);   
    scanf("%d",&cs);  
    while(cs--)   
    {
		for(i=0;i<maxn;i++) s[i]=0;
		k=0;
        scanf("%d%d",&n,&m);    
        for(i=0;i<n;i++)    
        {     
            scanf("%d",&tmp);     
            pos[tmp]=i;     
            s[tmp]=1;    
        }    
        ok=0;    
        p=0;    
        for(i=0;i<m;i++)    
       {   scanf("%d",&tmp);     
           if(s[tmp])     
       {      
           if(pos[tmp]<p) 
           ok=1;      
           p=pos[tmp];     
        }    
    }    
    if(!ok) 
        puts("Hrac ma sanci vyhrat.");    
    else 
        puts("Spatne usporadani.");   
    }   
    return 0;  
}
