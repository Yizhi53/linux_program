#include <stdio.h>
#include <string.h>

int main()
{
	int len;
	const char str1[] = "ABCDEFG019874";
	const char str2[] = "A";

	len = strspn(str1, str2);

	printf("init compare len: %d\n", len);

	return 0;
}
