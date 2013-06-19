import java.util.*;
public class Main {
	
	public static void main(String []args)
	{
		int maxn=100010;
		long [] a=new long [maxn];
		long [] sum=new long [maxn];
		long [] sum2=new long [maxn];
		Scanner stdin=new Scanner(System.in);
		while(stdin.hasNext())
		{
			int n=stdin.nextInt();
			for(int i=0;i<n;i++)
			{
				a[i]=stdin.nextLong();
				sum[i]=0;
				//System.out.println(a[i]);
			}
			Arrays.sort(a,0,n);
			
			for(int i=0;i<n;i++)
			{
				//System.out.println(a[i]);
				sum[i]=a[i];
				if(i>0) sum[i]+=sum[i-1];
			}		
			for(int i=n-1;i>=0;i--)
			{
				sum2[i]=a[i];
				if(i+1<n)
				{
					sum2[i]+=sum2[i+1];
				}
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
					ans+=i*a[i]-sum[i-1];
				}
				if(i+1<n)
				{
					ans+=sum2[i+1]-(n-i-1)*a[i];
				}
			}
			System.out.println(ans);
			
			
		}
	}
}
