#include <stdio.h>
#include <string.h>

int main()
{
	int len;
	const char str1[] = "ABCDEF4960910";
	const char str2[] = "A13";

	len = strcspn(str1, str2);

	printf("%d\n", len);

	return 0;
}
