#include <stdio.h>
#include <string.h>
#define SIZE 105

char in[SIZE],str[SIZE];
int flg[5],len;
int code(char c)
{
	switch(c){
	case 'p': return 0;
	case 'q': return 1;
	case 'r': return 2;
	case 's': return 3;
	case 't': return 4;
	}
}
void adjust()
{
	int i;
	for(i = 0; i < len; i++)
		if(in[i] > 'a' && in[i] < 'z')
			str[i] = '0' + flg[code(in[i])];
		else
			str[i] = in[i];
}
char cstack[SIZE];
int tstack[SIZE],ctail,ttail;

int doit(char M, int a,int b)
{
	switch(M){
	case 'A': if (a || b) return 1;
				return 0;
	case 'K': if (a && b) return 1;
				return 0;
	case 'C': if(!a || (a && b)) return 1;
				return 0;
	case 'E': if (a == b) return 1;
				return 0;
	}
}
int check()
{
	if(flg[0] == 0 && flg[1]){
		flg[0]  = 0;
	}
	adjust();
	int tf,i;
	ttail = ctail = 0;
	for(i = 0; i < len; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			cstack[++ctail] = str[i];
		}
		else{
			tf = str[i] - '0';
			while(ctail){
				if(ctail > 0 && cstack[ctail] == 'N'){
					tf = (tf+1)%2;
					ctail--;
				}
				else if(ctail > 0 && (cstack[ctail] ==0 || cstack[ctail] == 1)){
					tf = doit(cstack[ctail-1],cstack[ctail],tf);
					ctail -= 2;
				}
				else{
					cstack[++ctail] = tf;
					break;
				}
			}
		}
	}
	return tf;
}
int main()
{
	int i0,i1,i2,i3,i4;
	while(scanf("%s",in) && in[0] != '0'){
		len = strlen(in);
		for(i0 = 0; i0 < 2; i0++){
			flg[0] = i0;
			for(i1 = 0; i1 < 2; i1++){
				flg[1] = i1;
				for(i2 = 0; i2 < 2; i2++){
					flg[2] = i2;
					for(i3 = 0; i3 < 2; i3++){
						flg[3] = i3;
						for(i4 = 0; i4 < 2; i4++){
							flg[4] = i4;
							if(!check())
								goto wa;
						}
					}
				}
			}
		}
		printf("tautology\n");
		continue;
wa:
		printf("not\n");
	}
	return 0;
}