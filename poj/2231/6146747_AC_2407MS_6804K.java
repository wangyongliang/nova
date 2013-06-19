import java.util.*;
import java.io.*;
public class Main {
	
	public static void main(String []args)
	{
		int maxn=100010;
		int [] a=new int [maxn];
		long [] sum=new long [maxn];
		Scanner stdin=new Scanner(new BufferedReader( new InputStreamReader(System.in)));
		while(stdin.hasNext())
		{
			int n=stdin.nextInt();
			for(int i=0;i<n;i++)
			{
				a[i]=stdin.nextInt();
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