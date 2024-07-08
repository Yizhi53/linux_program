#include <stdio.h>
#include <string.h>

int main()
{
	const char str1[] = "abcde2fghi3jk4l";
	const char str2[] = "34";
	char *ret;

	ret = strpbrk(str1, str2);
	if(ret)
		printf("First word finded: %c in %ld\n", *ret, ret - str1 + 1);
	else
		printf("Not find words\n");

	return 0;
}
