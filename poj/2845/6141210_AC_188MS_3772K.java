import java.util.*;

public class Main {
	public static void main(String args[])
	{
		String str1;
		String str2;
		int n;
		Scanner stdin=new Scanner(System.in);
		n=stdin.nextInt();
		char [] ans=new char[100];
		int cnt;
		int t=1;
		while((n--)>0)
		{
			str1=stdin.next();
			str2=stdin.next();
			String string1=new StringBuffer(str1).reverse().toString();
			String string2=new StringBuffer(str2).reverse().toString();
			
			int length;
			if(str1.length()>str2.length()) length=str1.length();
			else length=str2.length();
			int flag=0;
			cnt=0;
		//	System.out.println(string1);
			//System.out.println(string2);
			for(int i=0;i<length;i++)
			{
				int k,l;
				if(i<string1.length())
				{
					k=string1.charAt(i)-'0';
				}
				else k=0;
				if(i<string2.length())
				{
					l=string2.charAt(i)-'0';
				}
				else l=0;
				
				flag+=k+l;
				ans[i]=(char)(flag%2+'0');
				flag=flag/2;	
				cnt++;
			}
			if(flag>0)
			{
				ans[cnt]=(char)(flag+'0');
			}
			else cnt--;
			for(;cnt>0;cnt--)
			{
				if(ans[cnt]!='0') break;
			}
			System.out.print(t++);
			System.out.print(" ");
			for(int i=cnt;i>=0;i--)
			{
				System.out.print(ans[i]);
			}
			System.out.println();
		}
		
	}
}
