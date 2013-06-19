#include<stdio.h>
#include<string.h>
int main()
{
    char f[128],c,ch[250]; 
    int i,len;
    for(i=0;i<128;i++) f[i]=-1;
f['2']='1';
    f['=']='-'; f['-']='0'; f['0']='9'; f['9']='8'; f['8']='7';
    f['7']='6'; f['6']='5'; f['5']='4'; f['4']='3'; f['3']='2'; f['1']='`';
    
    f['\\']=']'; f[']']='['; f['[']='P'; f['P']='O'; f['O']='I'; f['I']='U'; 
    f['U']='Y'; f['Y']='T';  f['T']='R'; f['R']='E'; f['E']='W'; f['W']='Q';
    
    f['\'']=';';
     f[';']='L'; f['L']='K'; f['K']='J'; f['J']='H'; f['H']='G';
    f['G']='F'; f['F']='D'; f['D']='S';  f['S']='A'; 
    
    f['/']='.'; f['.']=','; f[',']='M'; f['M']='N'; f['N']='B'; f['B']='V';
    f['V']='C'; f['C']='X'; f['X']='Z';
    
   //while((c=getchar())!=EOF)
   while(gets(ch)!=NULL)
    {
       //if(f[c]==0) printf("%c",c); 
       //else printf("%c",f[c]);  
       len=strlen(ch);
       for(i=0;i<len;i++)
       {
           if(f[ch[i]]<0) printf("%c",ch[i]);
           else printf("%c",f[ch[i]]);
       }    
     printf("\n");
    }        
    return 0;
    } 