#include <stdio.h>
#include <string.h>

int main()
{
	const char haystack[20] = "RUNOOB";
	const char needle[10] = "NOOB";
	char *ret;

	ret = strstr(haystack, needle);

	printf("first needle word pos is :%ld\n", ret - haystack + 1);

	return 0;
}
