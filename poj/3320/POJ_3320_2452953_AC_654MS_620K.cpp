#include<stdio.h>
#include<map>
#define max 1000009
using namespace std;
map<int ,int > mp;
map<int,int> mmp;
int heap [max][2];
int hash[max];
int k;
void shiftdown(int x)
{
	int i,j;
	int temp1,temp2;
	i=x;
	j=i*2;
	temp1=heap[x][0];
	temp2=heap[x][1];
	while(j<k)
	{
		if(heap[j][1]>heap[j+1][1]&&j+1<k) j++;
		if(heap[j][1]<temp2)
		{
			heap[i][1]=heap[j][1];
			heap[i][0]=heap[j][0];
			hash[heap[i][0]]=i;
			i=j;
			j=i*2;
		}
		else break;
	}
	heap[i][0]=temp1;
	heap[i][1]=temp2;
	hash[heap[i][0]]=i;
}
int main()
{
	int i,j,n,min,count;
	while(scanf("%d",&n)!=EOF)
	{
		k=1;
		mp.clear();
		mmp.clear();
		count=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			if(mp[j]==0)
			{
				count++;
				mp[j]=count;
				heap[k][0]=mp[j];
				heap[k][1]=i;
				hash[heap[k][0]]=k;
				k++;
				//shiftdown(j);
				min=i-heap[1][1]+1;
			}
			else
			{
				j=mp[j];
				j=hash[j];
				heap[j][1]=i;
				shiftdown(j);
				j=i-heap[1][1]+1;
				min=min>j?j:min;
			}
		}
		printf("%d\n",min);;
	}
	return 0;
}

