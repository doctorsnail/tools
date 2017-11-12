#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUF_SIZE 10485760

int main()
{
	char *buf = malloc(BUF_SIZE);
	char lines[64] = "";
	long ln, sl;
	long jump_max, i, j, m;
	fgets(buf, BUF_SIZE, stdin);
	sl = strlen(buf) - 1;
	//printf("%ld:%s\n", sl, buf);	
	fgets(lines, 64, stdin);
	ln = atol(lines);
	//printf("number:%ld\n", ln);	
	
	if (ln <= 0)
		goto out;
	
	jump_max = 2 * ln - 2;
	//printf("jump_max:%ld\n", jump_max);
	
	if (jump_max == 0)
	{
		printf("%s\n", buf);
		goto out;
	}

	for (i = 0; i < ln; i ++)
	{
		m = 2 * (ln - i) - 2;
		m = jump_max -m;

		for(j = i; j < sl; j += m)
		{
			printf("%c", buf[j]);
			m = jump_max - m;
			if (m == 0)
				m = jump_max;					
		}
	}	
	printf("\n");	
out:	free(buf);	
	return 0;
}
