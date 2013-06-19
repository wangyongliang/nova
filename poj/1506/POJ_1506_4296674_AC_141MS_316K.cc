
#include <stdio.h>
#include <string.h>

#define PISMEN 		('z'-'a'+1)
#define MAXWORD 	80
#define MAXMESSAGE	255

void task()
{
	static int t[PISMEN][PISMEN], cand[PISMEN], ccand;
	static char sc[PISMEN], mesg[MAXMESSAGE+1];
	char word1[MAXWORD+1], word2[MAXWORD+1], *p1, *p2;
	int i, j, ch, pismen, k, w1, nalezen, nul, nuli;

	scanf("%d %d", &pismen, &k);

	memset(t, 0, pismen*pismen*sizeof(int));
	memset(sc, 0, pismen*sizeof(char));
	memset(mesg, 0, pismen*sizeof(char));

	w1=1;
	scanf("%s", word1); 
	k--;
	for (; k; k--) 
	{
		if (w1) 
		{ 
			scanf("%s", word2); p1=word1; p2=word2; w1=0;
		}
		else 
		{ 
			scanf("%s", word1); p1=word2; p2=word1; w1=1;
		}
		while (*p1 && *p2 && *p1==*p2)
		{ 
			p1++; p2++;
		}
		if (*p1 && *p2)
			t[(*p1)-'a'][(*p2)-'a']=1;
	} 
	while (getchar()!='\n') ;
	gets(mesg);
	/*printf("message: %s\n", mesg);*/
	ch=0; nalezen=0;
	for (i=0; i<pismen; i++)
	{
		nul=1;
		for (j=0; j<pismen; j++) 
		{
			if (t[j][i]>0) { nul=0; break; }
		}
		if (nul) { cand[0]=i; ccand=1; nalezen++; }
	}
	if (!nalezen || nalezen>1)
	{
		printf( "Message cannot be decrypted.\n");
		return;
	}
	do {
		nalezen=0;
		for (i=0; i<ccand; i++) 
		{
			nul=1;
			for (j=0; j<pismen; j++) 
			{
				if (t[j][cand[i]]>0) { nul=0; break; }
			}
			if (nul) { nuli=cand[i]; nalezen++; }
		}
		if (!nalezen || nalezen>1)
		{
			printf( "Message cannot be decrypted.\n");
			return;
		}
		/*printf("%c --> %c\n", ch+'a', nuli+'a');*/
		sc[nuli]=ch++;
		ccand=0;
		for (j=0; j<pismen; j++) 
		{
			if (t[nuli][j]>0) { cand[ccand++]=j; t[nuli][j]=0; }
		}
	} while (nalezen && ch<pismen);
	if (ch==pismen) 
	{
		/*printf("Encrypted message: %s\n", mesg);*/
		for (p1=mesg; *p1; p1++) 
			if (*p1>='a' && *p1<='z') *p1='a'+sc[(*p1)-'a'];
		printf( "%s\n", mesg);
	}
	else printf( "Message cannot be decrypted.\n");
}

int main()
{
	int n;

	scanf("%d", &n);
	for (; n; n--) {
		task();
	}
	return 0;
}

