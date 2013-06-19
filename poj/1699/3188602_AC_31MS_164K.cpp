#include<iostream.h>
#include<string.h>
struct node
{
	char ch[21] ;
	int len ;
	int flag;
};
int n,m,min ;
node segment[10];    //保存输入数据的信息
int save[10][10];    //保存任意两个字符串相接将增加的长度
//深度优先搜索求最小值
	// floor表示递归到达的深度，也是已经接入的字符串的个数
	//total表示当前总长度
	//last表示上一个被接入的字符串编号
void srch(int floor,int total,int last)  
{
	int i;
	if ( total >= min ) return ;
	if ( floor == m-1 ) 
	{
		min = total;
		return ;
	}
	for( i = 0 ;i < m; i++ )
	{
		if (segment[i].flag == 1 ) continue ;
		segment[i].flag = 1 ;
		srch(floor+1,total+save[last][i],i) ;
		segment[i].flag = 0 ;
	}
}
void main()
{
	int i,l1,l2,len,j,k,l,flag,flag2;
	cin >> n ;
	while(n--)
	{
		cin >> m ;
		min = 999999999;
		for( i = 0 ; i < m ; i++ )       //输入数据
		{
			cin >> segment[i].ch ;
			segment[i].len = strlen(segment[i].ch);
			segment[i].flag = 0 ; 
		}
		memset(save,0,sizeof(save));
		for( i = 0 ; i < m ; i++ )       //循环求save数组
			for( j = 0 ; j < m ; j++)
			{
				l1 = segment[i].len ;
				l2 = segment[j].len ;
				len = (l1 > l2)?l2:l1;
				flag2 = 0 ;
				for( k = len ; k >= 0 ; k-- )
				{
					flag = 0 ;	
					for( l = 0 ; l < k ; l++ )
					{
						if ( segment[i].ch[l] != segment[j].ch[l2-k+l] )
						{
							flag = 1 ;
							break;
						}
					}
					if ( flag ==0 )
					{
						save[j][i] = l1-k ;
						break;
					}
				}
			}
		for( i = 0 ; i < m ; i++)     //任取一个字符串作为第一个字符串
		{
			segment[i].flag = 1 ;
			srch(0,segment[i].len,i);
			segment[i].flag = 0 ;
		}
		cout << min << endl;         //输出最小值
	}
}

