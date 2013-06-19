import java.util.*;

public class Main{
	static  int maxn=50100;
	public static void main(String [] args)
	{
		class node
		{
			int h;
			int x,y;
		};
		Scanner cin=new Scanner(System.in);
		int n,w;
		PriorityQueue<node> heap=new PriorityQueue<node>(maxn,new Comparator<node>()
				{
			public int compare(node x,node y)
			{
				if(x.h==y.h)
				{
					if(x.x==y.x) return x.y-y.y;
					else return x.x-y.x;
				}
				else return y.h-x.h;
			}
				});
		int []index=new int[1000100];
		while(cin.hasNext())
		{
			heap.clear();
			n=cin.nextInt();
			w=cin.nextInt();			
			int h,start;
			for(int i=0;i<=w+1;i++) index[i]=0;
			h=0;
			start=0;
			for(int i=0;i<n;i++)
			{
				node tmp= new node ();
				tmp.h=h;
				tmp.x=start;
				start=cin.nextInt();
				tmp.y=start-1;
				h=cin.nextInt();
				heap.offer(tmp);
				index[tmp.x]=index[tmp.y]=tmp.h;
			}
			int  len;
			len=0;
			node tmp= new node ();
			tmp.h=h;
			tmp.x=start;
			tmp.y=w;
			heap.offer(tmp);
			index[tmp.x]=index[tmp.y]=tmp.h;
			index[0]=0;
			index[w+1]=0;
			int ans=0;
			node tq=new node();
			while(heap.size()>0)
			{
				tmp=heap.poll();

				if(tmp.h==0) break;
				ans++;				
				while(heap.size()>0)
				{
					
					tq=heap.peek();
					if(tq.h==0) break;					
					if(tq.h==tmp.h)
					{
						heap.poll();
						if(tmp.y==tq.x-1)
						{

							tmp.y=tq.y;
						}
						else
						{
							tmp.h=index[tmp.x-1];
							ans++;
							node tp=new node();
							
							tp.h=tmp.h;
							tp.x=tmp.x;
							tp.y=tmp.y;
							heap.offer(tp);
							index[tp.x]=index[tp.y]=tp.h;
							tmp=tq;							
						}
					}
					else
					{
						tmp.h=index[tmp.x-1];						
						node tp=new node();						
						tp.h=tmp.h;
						tp.x=tmp.x;
						tp.y=tmp.y;
						heap.offer(tp);
						index[tp.x]=index[tp.y]=tp.h;							
						len--;
						break;						
					}
				}				
			}
			System.out.println(ans);			
		}	
	}
}
