#include <stdio.h>
#include <string.h>

int main()
{
	char str[50];
	int len;

	strcpy(str, "This is runoob.com");

	len = strlen(str);
	printf("|%s| lens is |%d|\n", str, len);

	return 0;
}
