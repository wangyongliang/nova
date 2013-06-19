#include <stdio.h>
#include <string.h>

char str[200];
int dp[200][200] = {0};		// [begin][len]
int take[200][200] = {0};	// [begin][len]
int length;

void TraceBack(int begin, int len)
{
	if (begin<0||begin>=length||len==0)
		return ;

	if (take[begin][len]==-1)
	{
		if (str[begin]=='['||str[begin]==']')
		{
			printf ("[]");
		}
		else
		{
			printf ("()");
		}

		TraceBack(begin+1, len-1);
	}
	else
	{
		int mid = take[begin][len];
		printf ("%c", str[begin]);
	
		TraceBack(begin+1, mid-begin-1);

		printf ("%c", str[mid]);

		TraceBack(mid+1, len-mid+begin-1);
	}
}

int main()
{
	scanf ("%s", str);
	length = strlen(str);

	for (int i=0; i<length; i++)
	{
		dp[i][0] = 0;
		dp[i][1] = 2;
		take[i][1] = -1;
	}

	for (int l=2; l<=length; l++)	//len
	{
		for (int s=0; s<=length-l; s++)	// start..
		{
			int answer = 2+dp[s+1][l-1];
			int method = -1;	// -1 means make up.

			if (str[s]=='['||str[s]=='(')
			{
				char match = (str[s]=='[')? ']' : ')';

				for (int mid=s+1; mid<s+l; mid++)
				{
					if (str[mid]==match)
					{
						int buf = dp[s+1][mid-s-1];
						if (mid!=s+l-1)	//if mid is not the last one..
						{
							buf += dp[mid+1][l-mid+s-1];
						}

						if (buf+2<answer)
						{
							answer = buf;
							method = mid;
						}
					}
				}

			}

			dp[s][l] = answer;
			take[s][l] = method;
		}
	}

	TraceBack(0, length);
	printf ("\n");

	return 0;
}
