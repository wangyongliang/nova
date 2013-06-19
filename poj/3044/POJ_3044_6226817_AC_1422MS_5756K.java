import java.util.*;

public class Main{
	static  int maxn=50100;
	public static void main(String [] args)
	{
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		int w=cin.nextInt();
		int []a=new int[maxn];
		int i;
		int len;
		int ans;
		len=0;
		ans=0;
		for(i=0;i<n;i++)
		{
			int x=cin.nextInt();
			int h=cin.nextInt();
			while(len>0&&a[len-1]>h)
			{
				if(a[len-1]>0)	ans++;
				len--;
			}
			if(len==0||h>a[len-1])
			{
				a[len++]=h;
			}			
		}
		while(len>0)
		{
			if(a[len-1]>0) ans++;
			len--;
		}
	//	ans+=len;
		System.out.println(ans);
		
	}
}
