import java.util.*;

import com.sun.jndi.url.iiopname.iiopnameURLContextFactory;
import com.sun.org.apache.xpath.internal.operations.Equals;

class A
{
	void run()
	{
		Scanner cinScanner=new Scanner(System.in);
		while(cinScanner.hasNextInt())
		{
			int n=cinScanner.nextInt();
			int [] ans=new int[5];
			for(int i=0;i<ans.length;i++) ans[i]=0;
			if(n<0) break;
			while(n-->0)
			{
				int m=cinScanner.nextInt();
				if(m>=0&&m<59) ans[0]++;
				else {
					m-=59;
					m=m/10;
					m++;
					if(m==5) m--;
					ans[m]++;
				
				}
				
				
			}
			for(int i=0;i<ans.length;i++) 
			{
				if(i==0) System.out.print("0-59:");
				else if (i<4)
				{
					System.out.print((60+(i-1)*10)+"-"+(60+i*10-1)+":");
				}
				else {
					System.out.print("90-100:");
				}
				System.out.println(ans[i]);
			}
		}
	}
}

class bignum
{
	static String  reverse(String str1)
	{
		String ans="";
		for(int i=str1.length()-1;i>=0;i--) ans=ans+str1.charAt(i);
		return ans;
	}
	static String add(String str1,String str2)
	{
		String ans="";
		str1=reverse(str1);
		str2=reverse(str2);
		//System.out.println(str2);
		int flag=0;
		int i;
		for( i=0;i<str1.length()&&i<str2.length();i++)
		{
			int x=str1.charAt(i)-'0';
			int y=str2.charAt(i)-'0';
			flag+=x+y;
			ans=(char)(flag%10+'0')+ans;
			flag/=10;
			
		}
		for(;i<str1.length();i++)
		{
			int x=str1.charAt(i)-'0';
			flag+=x;
			ans=(char)(flag%10+'0')+ans;
			flag/=10;
		}
		for(;i<str2.length();i++)
		{
			
			int y=str2.charAt(i)-'0';
			
			flag+=y;
			ans=(char)(flag%10+'0')+ans;
			flag/=10;
			
		}
		if(flag>0) ans=(char)(flag+'0')+ans;
		return ans;		
	}
	static int isbig(String str1,String str2)
	{
		while(str1.length()>str2.length())
		{
			str2="0"+str2;
		}
		while(str2.length()>str1.length())
		{
			str1="0"+str1;
		}
		return str1.compareTo(str2);
		
	
	}
}
public class Main {
	public static void main(String[] args) {
		String [] fib=new String[1000];
		fib[0]="1";
		fib[1]="2";
		
		int k=1;
		while(fib[k].length()<=100&&k<800)
		{
			fib[k+1]=bignum.add(fib[k-1], fib[k]);
			k++;
		}
		Scanner cinScanner =new Scanner(System.in);
		while(cinScanner.hasNext())
		{
			
			String str1,str2;
			str1=cinScanner.next();
			str2=cinScanner.next();
			if(str1.equals("0")&&str2.equals("0")) break;
			if(str1.charAt(0)=='0') str1="0";
			if(str2.charAt(0)=='0') str2="0";
			int ans=0;
			
			for(int i=0;i<=k;i++)
			{
				if(bignum.isbig(fib[i], str2)>0)break;
				else ans++;
			}
			
			
			for(int i=0;i<=k;i++)
			{
				if(bignum.isbig(fib[i], str1)>=0)break;
				else ans--;
			}
			if(ans<0) ans=-ans;
			System.out.println(ans);
		}
		
	}

}
