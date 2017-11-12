#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_STR 10485760
int main ()
{
	int tmp, i = 0, start = 0, max_start = 0, max_end = 0;
	long sum = 0, max_sum = 0;
	char *buf = malloc(MAX_STR);
	char *buf_t = buf;
	char *num = NULL;
	fgets(buf, MAX_STR, stdin);
	
	while((num = strtok(buf_t, " ")) != NULL)
	{
		i++;
		tmp = atoi(num);
		sum += tmp;
		if (sum > max_sum)
		{	
			max_start = start;
			max_sum = sum;
			max_end = i;
		}
		if(sum < 0)
		{
			start = i;
			sum = 0;
		}
		buf_t = NULL;
	}
	printf("max_sum:%ld, max_start:%d, max_end:%d\n", max_sum, max_start + 1, max_end);
out:	
	free(buf);
	return 0;
}
