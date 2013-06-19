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
			int []a=new int[n+1];
			int h,start;
			for(int i=0;i<=w+1;i++) index[i]=0;
			h=0;
			start=0;
			
			//输入
			
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
				a[i]=h;
			}
			a[n]=0;
			Arrays.sort(a);
			int  len;
			len=0;
			for(int i=1;i<a.length;i++)
			{
				if(a[i]!=a[len])
				{
					len++;
					a[len]=a[i];
				}
			}
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
			//	System.out.println("弹出 "+tmp.h+" "+tmp.x+" "+tmp.y);
				if(tmp.h==0) break;
				ans++;
				//System.out.println("++");
				
				while(heap.size()>0)
				{
					
					tq=heap.peek();
					if(tq.h==0) break;
				//	System.out.println("出 "+tq.h+" "+tq.x+" "+tq.y);
					
					if(tq.h==tmp.h)
					{
						heap.poll();
						if(tmp.y==tq.x-1)
						{
					//		System.out.println("合并 "+tq.h+" "+tq.x+" "+tq.y);
							tmp.y=tq.y;
						}
						else
						{
							tmp.h=index[tmp.x-1];
							ans++;
						//	System.out.println("++");
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

/*
10 26
1 1
2 2
5 1
6 3
8 1
11 0
15 2
17 3
20 2
22 1

2 100
1 1
99 0


*/
