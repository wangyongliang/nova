#include<stdio.h>
#include<string>
using namespace std;
string f(string str1)
{return str1.substr(0,str1.size()-1);}void g(string &str2,string &str3,char ch){int i;if(ch=='+'||ch=='-'){if(ch=='+') return ;
else{for(i=0;i<str2.size();i++){if(str3[i]=='1'){if(str2[i]=='+') str2[i]='-';else if(str2[i]=='-') str2[i]='+';}}}}else{
int flag=1;for(i=0;i<str2.size();i++){if(str3[i]=='1'&&(str2[i]=='+'||str2[i]=='-')) flag=0;
}if(flag==0){str2='('+str2+')';str3='0'+str3+'0';
for(i=0;i<str3.size();i++) str3[i]='0';return ;}else{if(ch=='*') return ;for(i=0;i<str2.size();i++){if(str3[i]=='1'){
if(str2[i]=='*') str2[i]='/';else str2[i]='*';}}}}}void dfs(string str1,string &str2,string &str3){string tp1,tp2,tp3;
str2=str3="";int i,j,l,cnt,k;if(str1.size()==0||str1.size()==1){str2=str1;for(i=0;i<str1.size();i++) str3+='0';}else{for(i=0;i<str1.size();i++){str2+=str1[i];if(str1[i]=='+'||str1[i]=='-'||str1[i]=='*'||str1[i]=='/') str3+='1';
else str3+='0';if(str1[i]=='('){str2=f(str2);str3=f(str3);cnt=1;tp1="";for(j=i+1;cnt;j++){tp1+=str1[j];if(str1[j]=='(') cnt++;if(str1[j]==')') cnt--;}k=j;tp1=f(tp1);dfs(tp1,tp2,tp3);if(i==0){if(k==str1.size()||str1[k]=='+'||str1[k]=='-')str2+=tp2,str3+=tp3;
else{for(l=0;l<tp2.size();l++){if(tp3[l]=='1'&&(tp2[l]=='+'||tp2[l]=='-')) break;
}if(l==tp2.size())str2+=tp2,str3+=tp3;else {str2+='('+tp2+')';for(l=0;l<tp3.size();l++) tp3[l]='0';
str3+='0'+tp3+'0';}}}else{if(str1[i-1]=='+'||str1[i-1]=='-'){if(k==str1.size()||str1[k]=='+'||str1[k]=='-'){if(str1[i-1]=='-')g(tp2,tp3,'-');str2+=tp2,str3+=tp3;}else{for(l=0;l<tp2.size();l++){if(tp3[l]=='1'&&(tp2[l]=='+'||tp2[l]=='-')) break;
}if(l==tp2.size())str2+=tp2,str3+=tp3;else {str2+='('+tp2+')';for(l=0;l<tp3.size();l++) tp3[l]='0';
str3+='('+tp3+')';}}}else{if(str1[i-1]=='*') g(tp2,tp3,'*');
else g(tp2,tp3,'/');
str2+=tp2,str3+=tp3;}}i=k-1;}}}}
int main()
{char s[1100];
string str1,str2,str3,tp;
while(scanf("%s",s)!=EOF){
str1=s;while(1){str2=str3="";
tp=str1;dfs(str1,str2,str3);if(tp==str2) break;
str1=str2;}printf("%s\n",str2.c_str());}
return 0;
}