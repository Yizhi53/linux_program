#include <stdio.h>
#include <string.h>

int main()
{
	char str1[15];
	char str2[15];
	int ret;

	strcpy(str1, "abc");
	strcpy(str2, "ABC");

	ret = strcoll(str1, str2);

	if(ret > 0)
		printf("str1 > str2\n");
	else if(ret < 0)
		printf("str1 > str2\n");
	else
		printf("str1 == str2");
	
	return 0;
}
