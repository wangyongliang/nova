#include <stdio.h>
#include <string.h>

char in[20];

int mem[32], acc, pc, cmd, addr;

int get( char *p )
{
	int s = 0;
	while( *p ) {
		s *= 2;
		s += *p - '0';
		p ++;
	}
	return s;
}

int main()
{
	int i;
	while( 1 ) {
		for( i = 0; i < 32; i ++ )
		{
			if( scanf( "%s", in ) < 0 ) return 0;
			mem[i] = get( in );
		}
		pc = acc = 0;
		while( 1 ) {
			cmd = mem[pc]>>5;
			addr = mem[pc] % 32;
			switch( cmd ) {
			case 0:	mem[addr] = acc;break;
			case 1:	acc = mem[addr];break;
			case 2:	if( !acc )	pc = addr-1;	break;
			case 3:		break;
			case 4:	acc = ( acc + 255 ) % 256;	break;
			case 5:	acc = ( acc + 1 ) % 256;	break;
			case 6:	pc = addr-1;			break;
			case 7:		  goto end;
			}
			pc = (pc + 1 ) % 32;
		}
		;end:
		for( i = 7; i >= 0; i -- )
			printf( "%d", (acc>>i)&1 );
		printf( "\n" );
	}
	return 0;
}

