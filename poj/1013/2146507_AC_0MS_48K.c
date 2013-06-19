#include <stdio.h>
#include <string.h>
int main()
{
    int T;  
    char left[20],right[20],result[10];
    scanf("%d",&T);
    while(T--)
    { 
       int i,j,k,m;
       int flag[200]={0};
       int pos,max;
              
       for(i=1;i<=3;i++)
      {                     
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        memset(result,0,sizeof(result));
      
         scanf("%s%s%s",left,right,result);
      
          if(strcmp(result,"even")==0)
         {
                for(j=0;left[j];j++)  flag[left[j]]=1;
                for(j=0;right[j];j++) flag[right[j]]=1;
          }
        else if(strcmp(result,"up")==0)
        {
           for(j=0;left[j];j++)
           for(k=0;right[k];k++)
            if(left[j]==right[k])flag[left[j]]=1;
            
           for(j=0;left[j];j++) 
           {     
                if(flag[left[j]]==1)continue;       
                else if(flag[left[j]]!=0&&flag[left[j]]%2==0) flag[left[j]]+=2;
                else if(flag[left[j]]%2==1)flag[left[j]]=1;                                        
                else if(flag[left[j]]==0) flag[left[j]]=2;
           }
     
           for(j=0;right[j];j++)
           {  
                if(flag[right[j]]==1)continue;
                else if(flag[right[j]]%2==1)flag[right[j]]+=2;
                else if(flag[right[j]]!=0&&flag[left[j]]%2==0)flag[right[j]]=1;
                else if(flag[right[j]]==0) flag[right[j]]=3;
           }
         
        }
        
        else if(strcmp(result,"down")==0)
        {
           for(j=0;left[j];j++)
           for(k=0;right[k];k++)
              if(left[j]==right[k])flag[left[j]]=1;
              
          for(j=0;left[j];j++) 
          {      
                if(flag[left[j]]==1)continue;         
                else if(flag[left[j]]%2==0&&flag[left[j]]!=0)flag[left[j]]=1;
                else if(flag[left[j]]%2!=0)flag[left[j]]+=2;
                else if(flag[left[j]]==0)flag[left[j]]=3;
            }
           
          for(j=0;right[j];j++)
          {
                if(flag[right[j]]==1)continue;                                        
                else if(flag[right[j]]%2==0&&flag[right[j]]!=0)flag[right[j]]+=2;
                else if(flag[right[j]]%2==1)flag[right[j]]=1;
                else if(flag[right[j]]==0)flag[right[j]]=2;
            }
         }
    }
        max=-1;
        for(i=65;i<=76;i++)
        if(flag[i]>max){max=flag[i];pos=i;}
        if(max%2==0) printf("%c is the counterfeit coin and it is heavy.\n",pos); 
        else printf("%c is the counterfeit coin and it is light.\n",pos);
    }
    return 0;
}
