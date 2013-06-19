import java.util.*;

public class Main {
	static String dfs(String str1,String str2)
	{
		if(str1.length()==1)
		{
			return str1;
		}
		else
		{
			char ch=str1.charAt(0);
			int index=str2.indexOf(ch);
			String left_1,left_2,right_1,right_2;
			String ans="";
			if(index>0)
			{
				
			
				left_1=str1.substring(1, index+1);
				left_2=str2.substring(0,index);
				ans+=dfs(left_1,left_2);
				
			}
			if(index<str1.length()-1)
			
			{
				right_1=str1.substring(index+1, str1.length());
			
				right_2=str2.substring(index+1, str2.length());
				ans+=dfs(right_1,right_2);
			}
			
			
			ans+=ch;
			return ans;
			
		}
	}
	public static void main(String [] args)
	{
		String str1,str2;
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext())
		{
			str1=cin.next();
			str2=cin.next();
			//System.out.println(str1);
			//System.out.println(str2);
			System.out.println(dfs(str1,str2));
		}
	}
}
