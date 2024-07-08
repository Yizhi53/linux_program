#include <stdio.h>
#include <string.h>

int main()
{
	int len;
	const char str[] = "https://www.runoob.com";
	const char ch = '.';
	char *ret;

	ret = strrchr(str, ch);

	printf("after |%c| words are |%s|\n", ch, ret);

	return 0;	
}
