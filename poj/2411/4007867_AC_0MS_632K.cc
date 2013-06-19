#include <stdio.h>

static double cnt[12][1<<11];
static int trans[16384][2];
int rows, cols, ntrans;
void backtrack (int n, int from, int to)
{
  if (n > cols) return;
  if (n == cols)
  {
    trans[ntrans][0] = from;
    trans[ntrans][1] = to;
    ++ntrans;
    return;
  }
  backtrack (n+2, from<<2, to<<2);
  backtrack (n+1, from<<1, (to<<1)|1);
  backtrack (n+1, (from<<1)|1, to<<1);
}
int main ()
{
  int r, t;
 // scanf("%d",&t);
  while (scanf ("%d%d", &rows, &cols)&&(rows+cols))
  {
  	
    if (rows < cols) { t = rows; rows = cols ; cols = t; }
    ntrans = 0;
    backtrack (0, 0, 0);
    for (r=0 ; r<=rows ; r++)
      for (t=0 ; t<(1<<cols) ; t++)
        cnt[r][t] = 0;
    cnt[0][0] = 1;
    for (r=0 ; r<rows ; r++) 
	{
		for (t=0 ; t<ntrans ; t++) 
        cnt[r+1][trans[t][1]] += cnt[r][trans[t][0]];
	}
    printf ("%.0f\n", cnt[rows][0]);
  }
  return 0;
}

