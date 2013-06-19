import java.util.*;
import java.io.*;
public class Main {
	
	public static void main(String []args) throws IOException
	{
		int maxn=100010;
		int [] a=new int [maxn];
		long [] sum=new long [maxn];
		BufferedReader Stdin=new BufferedReader(new InputStreamReader(System.in));
		
	//	while(Stdin.ready())
		/*
		{
			String str=Stdin.readLine();
			System.out.println(str);
			int x=Integer.parseInt(str,10);
			System.out.println(x);
		}
		*/
		//System.out.println("ok");
		//Scanner stdin=new Scanner(System.in);
		int n=Integer.parseInt(Stdin.readLine(), 10);
		//while(stdin.hasNext())
		{
			//int n=stdin.nextInt();
			for(int i=0;i<n;i++)
			{
				a[i]=Integer.parseInt(Stdin.readLine(), 10);
				//a[i]=Stdin.nextInt();
			}
			Arrays.sort(a,0,n);
			
			for(int i=0;i<n;i++)
			{
				sum[i]=a[i];
				if(i>0) sum[i]+=sum[i-1];
			}		
			long ans=0;
			/*
			for(int i=0;i<n;i++)
			{
				System.out.print(sum[i]);
				System.out.print("  ");
				System.out.println(sum2[i]);
			}
			*/
			for(int i=0;i<n;i++)
			{
				if(i>0)
				{
					ans+=i*(long)a[i]-sum[i-1];
				}
				if(i+1<n)
				{
					ans+=sum[n-1]-sum[i]-(n-i-1)*(long)a[i];
				}
			}
			System.out.println(ans);
			
			
		}
	}
}
