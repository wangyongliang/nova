#include<iostream>
#include<vector>
using namespace std;

bool flag[1<<25]={0};
int dx[]={0, 0,1,-1};
int dy[]={1,-1,0, 0};
vector<int> ans;
void dfs(int bit,int x,int y,int deep)
{
    int k;
  //  cout<<bit<<endl;
    flag[bit]=1;
    if(deep==0) 
    {
        ans.push_back(bit);
    }
    else
    {
        for(x=0;x<5;x++)
        {
            for(y=0;y<5;y++)
            {
                if(bit&(1<<(x*5+y)));
                else continue;
                for(k=0;k<4;k++)
                {
                    int xx=x+dx[k];
                    int yy=y+dy[k];        
                    if(xx>=0&&xx<5&&yy>=0&&yy<5)
                    {
                        if((bit&(1<<(xx*5+yy)))==0 && flag[bit+(1<<(xx*5+yy))]==0)
                        {
                            dfs(bit+(1<<(xx*5+yy)),xx,yy,deep-1);
                        }
                    }
                }
            }
        }
    }
}

void print(int bit)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(bit&(1<<(i*5+j))) printf("1");
            else printf("0");
        }
        printf("\n");
    }
    printf("\n");
}

char str[10][10];
int check(int bit)
{
        int i,j;
        int cnt1=0,cnt2=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(bit&(1<<(i*5+j))) 
            {
                if(str[i][j]=='J') cnt1++;
                else cnt2++;
            }

        }

    }
    return cnt1>=4;
}


int main()
{   
    
//    print(1);
//    print(2);
    ans.clear();
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            dfs(1<<(i*5+j),i,j,6);
        }
    }
  //  cout<<ans.size()<<endl;
    for(i=0;i<5;i++) gets(str[i]);
    
    int cnt=0;
    for(int i=0;i<ans.size();i++)
    {
        if(check(ans[i]))
        {
      //      print(ans[i]);
            cnt++;
        }
    }

    cout<<cnt<<endl;
//    system("pause");
    return 0;
}
