#include <stdio.h>
#include <string.h>

int main()
{
	char str1[15];
	char str2[15];
	int ret;

	strcpy(str1, "abcdef");
	strcpy(str2, "ABCDEF");

	ret = strncmp(str1, str2, 4);

	if(ret < 0)
	{
		printf("str1 < str2\n");
	}else if(ret > 0)
	{
		printf("str1 > str2\n");
	}else{
		printf("str1 == str2\n");
	}
}
