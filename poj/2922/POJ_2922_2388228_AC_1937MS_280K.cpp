#include <iostream>
using namespace std;

int road[100][100];
int mark[100][100];

int n;

int main()
{
	void read(int,int &,int &);
	int judge(int,int,int);
	int m;
	int maxt,mint;
	int temp; //temp 是区间长度
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int max,min;
		cin>>n;
		read(n,max,min); //输入矩阵,并将矩阵中最大值和最小值分
					//别赋给max,min
		mint = 0;
		maxt = max-min;
		while(mint<maxt)
		{
			temp = (maxt + mint)/2;
			if(judge(temp,max,min)) //判断在区间[min,max]
						//之间有没有temp的路径
				maxt = temp;
			else
				mint = temp + 1;
		}
		cout<<"Scenario #"<<i+1<<":"<<endl
			<<mint<<endl<<endl;
	}
	return 0;
}

void read(int n,int &max,int &min)
{
	max = 0;
	min = 10000;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>road[i][j];
			max = max>road[i][j]?max:road[i][j];
			min = min<road[i][j]?min:road[i][j];
		}
}

int dfs(int row,int column,int max,int min)
{ // (row,column)为起始点坐标，max和min为允许路径中出现的
  // 最大值和最小值。
	if(mark[row][column] || road[row][column]>max || 
			road[row][column]<min ||
 			row>=n || row<0 || column>=n || column<0)
		return 0;
	mark[row][column] = 1;
	if(row ==n-1 && column ==n-1)
		return 1;
	else if(dfs(row-1,column,max,min)||dfs(row+1,column,max,min)
	||dfs(row,column-1,max,min)||dfs(row,column+1,max,min))
		return 1;
	else 
		return 0;
}

int judge(int temp,int max,int min) //max,min are the highest and the lowest points in the matrix
{
	void initialMark();
	for(int i=0;i<=max - temp;i++)
	{
		initialMark(); //每次搜索之前都要初始化状态标记数组。
		int test = dfs(0,0,min+temp+i,min+i); //枚举当前结果下
							//的各个区间。
		if(test)
			return 1;
	}
	return 0;
}

void initialMark()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			mark[i][j] = 0;
}