import java.util.*;
import java.text.*;
public class Main {
	public  static void main(String agrs[])
	{
		double []a=new double [3010];
		double []c=new double [3010];
		int n;
		Scanner stdin=new Scanner(System.in);
		while(stdin.hasNext())
		{
			n=stdin.nextInt();
			a[0]=stdin.nextDouble();
			a[n+1]=stdin.nextDouble();
			for(int i=1;i<=n;i++)
			{
				c[i]=stdin.nextDouble();
			}
			
			double min,max,mid;
			min=-1000.0;
			max=1000.0;
			double ans=a[n+1];
			//System.out.println(ans);
		//	System.out.println("OK");
			while(max-min>1e-3)
			{
				mid=(min+max)/2.0;
				a[1]=mid;
				for(int i=1;i<=n;i++)
				{
					a[i+1]=(a[i]+c[i])*2.0-a[i-1];
				}
				if(a[n+1]<ans) min=mid;
				else max=mid;
			}
			DecimalFormat df=new DecimalFormat("#.00");
			System.out.println(df.format(min));
		}
		//System.out.println("that is the end!");
	}
}
