import java.util.*;
import java.math.*;

public class Main {
	
	public static void main(String [] args)
	{
		int n,p;
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext())
		{
			n=cin.nextInt();
			p=cin.nextInt();
//			p+=2;
			int [] sum=new int[n];
			int [][] total=new int[n][n];
			int [][] dp=new int[n][p+1];
			int [] a=new int[n];
			for(int i=0;i<n;i++)
			{
				a[i]=cin.nextInt();	
			}
			Arrays.sort(a);

			for(int i=0;i<n;i++)
			{
				sum[i]=a[i];
				if(i>0) sum[i]+=sum[i-1];
			}
			for(int i=0;i<n;i++)
			{
				int pos=i;
				for(int j=i+1;j<n;j++)
				{
					while(pos+1<=j&&(a[pos+1]*2<a[i]+a[j])) pos++;
					total[i][j]=(j-pos)*a[j]-(pos-i+1)*a[i];
					total[i][j]+=sum[pos]-(i>0?sum[i-1]:0);
					total[i][j]-=sum[j]-sum[pos];					
				}
				total[i][i]=0;
			}
			
			
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<=p;j++) dp[i][j]=1000000000;
				
			}
			for(int i=0;i<n;i++)
			{
				dp[i][1]=(i+1)*a[i]-sum[i];
		//		System.out.println(dp[i][1]);
			}
			
			for(int i=0;i<n;i++)
			{
				for(int j=2;j<=p;j++)
				{
					for(int k=0;k<=i;k++)
					{
						dp[i][j]=Math.min(dp[i][j],dp[k][j-1]+total[k][i]);
					}
				//	dp[i][j]=Math.min(dp[i][j],dp[i][j-1]);
				}
			}
			int ans=0x7ffffff;
			for(int i=0;i<n;i++)
			{
				int tp=0;
				if(i>0) tp=sum[i-1];
				else tp=0;
				tp=sum[n-1]-sum[i];
				tp-=a[i]*(n-i-1);
				
				ans=Math.min(ans,dp[i][p]+tp);				
			}
			System.out.println(ans);

		}
	}
}
