#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 10485760

int main()
{
	char *buf = malloc(BUF_SIZE);
	char lines[64] = "";
	long linenumber, sl;
	long jump_max, i, j, m;
	gets(buf);
	sl = strlen(buf);
	printf("%ld:%s\n", sl, buf);	
	gets(lines);
	linenumber = atol(lines);
	printf("number:%ld\n", linenumber);	
	
	if (linenumber <= 0)
		goto out;
	
	jump_max = 2 * linenumber - 2;
	printf("jump_max:%ld\n", jump_max);
	
	if (jump_max == 0)
	{
		printf("%s\n", buf);
		goto out;
	}

	for (i = 0; i < linenumber; i ++)
	{
		m = 2 * (linenumber - i) - 2;
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
