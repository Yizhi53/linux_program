#include <stdio.h>
#include <string.h>

int main()
{
	char dest[20];
	char src[20];
	int len;

	strcpy(src, "W3C School");
	len = strxfrm(dest, src, 20);

	printf("String is |%s| lens is |%d|\n", dest, len);

	return 0;
}
